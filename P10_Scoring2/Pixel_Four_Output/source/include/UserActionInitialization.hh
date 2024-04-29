//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// UserActionInitialization.hh  Serial version
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef UserActionInitialization_h
#define UserActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class SimData ;

//------------------------------------------------------------------------------
  class UserActionInitialization : public G4VUserActionInitialization
//------------------------------------------------------------------------------
{
  public:
    UserActionInitialization();
    ~UserActionInitialization() override;

    void BuildForMaster() const override;
    void Build() const override;

    void SetSimData(SimData* simdata) ;
 private:

    SimData* simdata;

};

inline void UserActionInitialization::SetSimData(SimData* data )
	{
		simdata = data ;
	}

#endif



