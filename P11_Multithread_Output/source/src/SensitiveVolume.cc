//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SensitiveVolume.cc MT version
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "SensitiveVolume.hh"

#include "G4Track.hh"
#include "G4Step.hh"
#include "G4ParticleDefinition.hh"
#include "G4HCofThisEvent.hh"
#include "G4Threading.hh"
#include "SimData.hh"
#include <vector>

//------------------------------------------------------------------------------
SensitiveVolume::SensitiveVolume(G4String name)
  : G4VSensitiveDetector(name), simdata{nullptr}
{
}

//------------------------------------------------------------------------------
void SensitiveVolume::Initialize(G4HCofThisEvent*)
{
  fEdep = 0.;
  fStep = 0. ;
}

//------------------------------------------------------------------------------
  G4bool SensitiveVolume::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{
  auto edep = aStep-> GetTotalEnergyDeposit();
  auto steplen = aStep->GetStepLength();
  fEdep += edep;
  fStep += steplen;
  return true;
}

//------------------------------------------------------------------------------
  void SensitiveVolume::EndOfEvent(G4HCofThisEvent*)
{
  //G4cout << " fEdep =  " << fEdep <<G4endl;

  G4int tid = G4Threading::G4GetThreadId();
  simdata[tid].Fill(fEdep, fStep );
}
