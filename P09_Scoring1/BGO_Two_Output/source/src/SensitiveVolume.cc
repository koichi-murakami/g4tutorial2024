//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SensitiveVolume.cc 
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "G4Track.hh"
#include "G4Step.hh"
#include "G4ParticleDefinition.hh"
#include "G4HCofThisEvent.hh"

#include "SimData.hh"
#include "SensitiveVolume.hh"
#include <vector>

SensitiveVolume::SensitiveVolume(G4String name)
  : G4VSensitiveDetector(name), simdata{nullptr}
{
 }
 SensitiveVolume::~SensitiveVolume()
{
 }

void SensitiveVolume::Initialize(G4HCofThisEvent*)
{
  fEdep = 0. ;
  fStep = 0. ;
}
void SensitiveVolume::EndOfEvent(G4HCofThisEvent*)
{
  simdata[0].Fill( fEdep, fStep );
}

G4bool SensitiveVolume::ProcessHits(G4Step* aStep, G4TouchableHistory*)
{
  auto edep = aStep->GetTotalEnergyDeposit();
  auto steplen = aStep->GetStepLength();
  fEdep += edep;
  fStep += steplen;

  return true;
}






