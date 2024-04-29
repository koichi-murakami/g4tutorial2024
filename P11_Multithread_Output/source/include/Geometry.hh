//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geometry.hh  MT mode
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef Geometry_h
#define Geometry_h 1

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class SimData;

//------------------------------------------------------------------------------
  class Geometry : public G4VUserDetectorConstruction
//------------------------------------------------------------------------------
{
  public:
    Geometry();
   ~Geometry() override;

    G4VPhysicalVolume* Construct() override;
    void ConstructSDandField() override;

    void SetSimData(SimData* data);

  private:
	SimData* simdata ;
};

inline void Geometry::SetSimData(SimData* data)
	{
		 G4cout << "Geometry::SetSimData " << G4endl;
		 simdata = data ;
	}

#endif
