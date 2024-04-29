//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// UserActionInitialization.hh
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#ifndef UserActionInitialization_h
#define UserActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

//------------------------------------------------------------------------------
  class UserActionInitialization : public G4VUserActionInitialization
//------------------------------------------------------------------------------
{
  public:
    UserActionInitialization();
    virtual ~UserActionInitialization() override;

    virtual void Build() const override;
};
#endif
