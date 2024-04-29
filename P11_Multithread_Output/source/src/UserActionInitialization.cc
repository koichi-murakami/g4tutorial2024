//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// UserActionInitialization.cc   MT
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "UserActionInitialization.hh"
#include "PrimaryGenerator.hh"
#include "RunAction.hh"
#include "G4RunManager.hh"
#include "Geometry.hh"
#include "SimData.hh"


//------------------------------------------------------------------------------
  void UserActionInitialization::Build() const
//------------------------------------------------------------------------------
{
  SetUserAction( new PrimaryGenerator{} );

  auto runaction = new RunAction{};
  runaction -> SetSimData(simdata);
  SetUserAction(runaction);
}


// --------------------------------------------------------------------------
void UserActionInitialization::BuildForMaster() const
{
  auto runaction = new RunAction{};
  runaction-> SetSimData(simdata);
  SetUserAction(runaction);
}
