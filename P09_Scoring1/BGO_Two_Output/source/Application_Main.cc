//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geant4 Application: Serial version
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Geometry.hh"
#include "UserActionInitialization.hh"

#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4UIcommand.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "FTFP_BERT.hh"

#include "SimData.hh"

//-------------------------------------------------------------------------------
  int main( int argc, char** argv )
//-------------------------------------------------------------------------------
{


// Construct the "Serial" run manager
   auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Serial);

// Set up mandatory user initialization: Geometry
//    Set SimData pointer
//    use array of size 1
      G4int nvec = 1 ;
	auto simdata = new SimData[nvec];
	auto geometry = new Geometry{};
	geometry->SetSimData(simdata);
   runManager->SetUserInitialization( geometry );

// Set up mandatory user initialization: Physics-List
   runManager->SetUserInitialization( new FTFP_BERT{} );

// Set up user initialization: User Actions

   auto useraction = new UserActionInitialization{};
      useraction -> SetSimData(simdata) ;
   runManager->SetUserInitialization(  useraction );

// Initialize G4 kernel
   runManager->Initialize();

// Create visualization environment 
   auto visManager = new G4VisExecutive{};
   visManager->Initialize();

   auto uiManager = G4UImanager::GetUIpointer();
 if( argc > 1 ) { // batch mode
   G4String macroFile = argv[1];
   uiManager->ApplyCommand( "/control/execute batchSetup.mac" ); 
   G4String command = "/control/execute ";
   uiManager->ApplyCommand(command+macroFile);
  } else {   // Start interactive session
   auto uiExec = new G4UIExecutive( argc, argv );
   uiManager->ApplyCommand( "/control/execute GlobalSetup.mac" );
   uiExec->SessionStart();

// interactive session termination
   delete uiExec;
}
   delete [] simdata;
   delete visManager;
   delete runManager;

   return 0;
}
