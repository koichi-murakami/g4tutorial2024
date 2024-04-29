//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SensitiveVolume.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "SensitiveVolume.hh"
#include "SimData.hh"

#include <vector>
#include "G4Event.hh"
#include "G4TouchableHistory.hh"
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4ParticleDefinition.hh"
#include "G4HCofThisEvent.hh"
#include "G4RunManager.hh"

//-------------------------------------------------------------------------
  SensitiveVolume::SensitiveVolume(G4String name)
  : G4VSensitiveDetector(name) , simdata{nullptr}
{}
//------------------------------------------------------------------------
  SensitiveVolume::~SensitiveVolume()
{}
//-------------------------------------------------------------------------
  void SensitiveVolume::Initialize(G4HCofThisEvent*)
{
}
//-------------------------------------------------------------------------
  void SensitiveVolume::EndOfEvent(G4HCofThisEvent*)
{
}
//-------------------------------------------------------------------------
  G4bool SensitiveVolume::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{
  G4cout << "=== ProcessHits ===" << G4endl;
  G4double edep = aStep->GetTotalEnergyDeposit();
  if ( edep == 0. ) return false;

// Retrieve information from the track object
   auto track = aStep->GetTrack();
   G4int idTrack = track->GetTrackID();
// Primary track is picked up
   if (idTrack != 1) return false;
           nStep  = track->GetCurrentStepNumber();
   G4String particleName = track->GetDefinition()->GetParticleName();
// primary particle has just entered a pixel
   if(track->GetTrackStatus()!=fAlive) return false;

  G4double globalTime = track->GetGlobalTime();
  auto runManager = G4RunManager::GetRunManager();
  auto currentEv = runManager->GetCurrentEvent();
  G4int eventID = currentEv->GetEventID();

   G4cout << "    eventID = " << eventID << "  Track ID =: " << idTrack 
               << "  Particle =: " << particleName << " time = " << globalTime <<G4endl;

// Get PreStepPoint and TouchableHandle objects
   G4StepPoint* preStepPoint=aStep->GetPreStepPoint();
   G4StepPoint* postStepPoint=aStep->GetPostStepPoint();

// a primary track entry coordinates
    if ( preStepPoint->GetStepStatus() != fGeomBoundary) return false;

    G4ThreeVector position_World = preStepPoint->GetPosition();
      position_Worldx = position_World.x() ;
      position_Worldy = position_World.y() ;
      position_Worldz = position_World.z() ;

// Touchable information: Volume name and copy# at the current step
  G4TouchableHandle theTouchable = preStepPoint->GetTouchableHandle();
  
  G4String volumeName = theTouchable->GetVolume()->GetName();
  G4int replicaNo = theTouchable->GetReplicaNumber();

  G4String volumeName_1 = theTouchable->GetVolume(1)->GetName();
  G4int replicaNo_1 = theTouchable->GetReplicaNumber(1);

  G4String volumeName_2 = theTouchable->GetVolume(2)->GetName();
  G4int replicaNo_2 = theTouchable->GetReplicaNumber(2);

 // next lines for debug only
 
   G4cout << "### entry point  ####" <<G4endl;   
   G4cout  << "  replicaNo = " <<replicaNo
               << "  replicaNo_1 = " << replicaNo_1
               << "  replicaNo_2 = "  << replicaNo_2
               <<"  x = " << position_Worldx << "  ,   y = " << position_Worldy 
               << " , z =  " << position_Worldz
               << G4endl;

// store thsi Hit
simdata[0].Fill(eventID, {replicaNo,  replicaNo_1, replicaNo_2}, {position_Worldx , position_Worldy, position_Worldz});

 return true;
}






