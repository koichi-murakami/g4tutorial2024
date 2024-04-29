///// RunAction.hh       Serial Version
#ifndef  RunAction_h
#define  RunAction_h 1

#include "G4UserRunAction.hh"
#include "globals.hh"

class SimData ;

class  RunAction : public G4UserRunAction
		
{
  public:
     RunAction();
    ~ RunAction() override;

    void BeginOfRunAction(const G4Run*) override;
    void   EndOfRunAction(const G4Run*) override;

    void SetSimData(SimData* data);

  private:
    SimData* simdata;
};

inline void RunAction::SetSimData(SimData* data)
	{ 
		G4cout << " RunAction::SetSimData " << G4endl;
		simdata = data;
	}

#endif

