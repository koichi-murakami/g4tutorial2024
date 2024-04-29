//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geant4 Application: MT version
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
  G4UIExecutive* ui = nullptr;
  if ( argc == 1 ) {
  	ui = new G4UIExecutive(argc, argv);
  }
  // Construct the default run manager
  G4int nvec = 4;
  auto* runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::Default);
  runManager -> SetNumberOfThreads(nvec);

  // Set up mandatory user initialization: Geometry
  // Set SimData pointer
  auto simdata = new SimData[nvec];
  auto geometry = new Geometry{};
  geometry-> SetSimData(simdata);
  runManager-> SetUserInitialization(geometry);

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

// UI interactive or batch
  auto uiManager = G4UImanager::GetUIpointer();

 if( ui ) { // interactive mode

   uiManager->ApplyCommand( "/control/execute GlobalSetup.mac" );
   ui -> SessionStart();
   delete ui;

} else {
// Start batch session
   G4String command = "/control/execute  ";
   G4String macroFile = argv[1] ;
   uiManager->ApplyCommand( "/control/execute batchSetup.mac" );
   uiManager->ApplyCommand( command + macroFile );
}


// Job termination
  delete [] simdata;
  delete visManager;
  delete runManager;

  return 0;
}
