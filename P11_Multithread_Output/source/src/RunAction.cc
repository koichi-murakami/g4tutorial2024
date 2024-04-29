//////////////
/// RunAction.cc  MT version
/////////////

#include "RunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4Threading.hh"
#include "SimData.hh"
#include <fstream>
#include <iostream>


void RunAction::BeginOfRunAction(const G4Run*)
{
  if ( IsMaster() != true ) {
    G4int tid = G4Threading::G4GetThreadId();
    simdata[tid].Initialize();
  }
}

void RunAction::EndOfRunAction(const G4Run*)
{
  if ( IsMaster() ) {
    G4String fName = "P11_MT.csv";

    std::ofstream outputfile(fName);

    auto nworkers= G4RunManager::GetRunManager()-> GetNumberOfThreads();

    for(auto i = 0; i < nworkers; i++ ) {
    auto record = simdata[i].GetRecord();

    for (auto val : record) {
  	    outputfile <<	std::get<0>(val);
          outputfile << " , " ;
 	    outputfile <<	std::get<1>(val);
          outputfile << std::endl;
      }
    }
    outputfile.close();

  }
}
