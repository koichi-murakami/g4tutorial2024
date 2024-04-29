/// RunAction.cc  Serial version

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

#include "RunAction.hh"
#include "SimData.hh"
#include <fstream>
#include <iostream>

RunAction::RunAction()	
{
 }
RunAction::~RunAction()
{
 }

void RunAction::BeginOfRunAction(const G4Run* )
{ 
  simdata[0].Initialize();
}

void RunAction::EndOfRunAction(const G4Run* )
{
 G4String  fName = "P09_Output.csv";
 auto record = simdata[0].GetRecord();  

 std::ofstream outputfile(fName);  
 for( auto val : record)
   {
	  outputfile <<	std::get<0>(val);
        outputfile << " , " ;
 	  outputfile <<	std::get<1>(val);
        outputfile <<  std::endl ;
  
	}
 outputfile.close();
}
