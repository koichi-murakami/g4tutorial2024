//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// SensitiveVolume.hh  Serial version
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef SensitiveVolume_h
#define SensitiveVolume_h 1

#include "G4VSensitiveDetector.hh"

#include <tuple>
#include <vector>

class G4Step;
class SimData;

//------------------------------------------------------------------------------
  class SensitiveVolume : public G4VSensitiveDetector
//------------------------------------------------------------------------------
{
  public:
      SensitiveVolume(G4String);
     ~SensitiveVolume() override ;

      void Initialize(G4HCofThisEvent*) override;
      G4bool ProcessHits(G4Step*, G4TouchableHistory*) override;
      void EndOfEvent(G4HCofThisEvent*) override;

      void SetSimData(SimData* data);
private:
      G4double fEdep = 0.;
      G4int nStep;
      G4double position_Worldx = 0.;
      G4double position_Worldy = 0.; 
      G4double position_Worldz = 0.; 
      G4double globalTime = 0.;
      G4int eventID  = 0;

	SimData* simdata;

};

inline void SensitiveVolume::SetSimData(SimData* data)
	{ 
	  G4cout << " simdata set by SensitiveVolume "<< G4endl;
	  simdata = data;
	}

#endif
