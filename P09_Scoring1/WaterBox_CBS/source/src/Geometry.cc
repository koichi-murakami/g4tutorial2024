//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Geometry.cc
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "Geometry.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4VPhysicalVolume.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4NistManager.hh"
#include "G4VisAttributes.hh"
#include "G4SystemOfUnits.hh"

//------------------------------------------------------------------------------
  Geometry::Geometry() {}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
  Geometry::~Geometry() {}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
  G4VPhysicalVolume* Geometry::Construct()
//------------------------------------------------------------------------------
{
// Get pointer to 'Material Manager'
   G4NistManager* materi_Man = G4NistManager::Instance();

// Define 'World Volume'
   // Define the shape of solid
   G4double leng_X_World = 2.0*m;           // X-full-length of world
   G4double leng_Y_World = 2.0*m;           // Y-full-length of world
   G4double leng_Z_World = 2.0*m;           // Z-full-length of world
   auto solid_World =
     new G4Box( "Solid_World", leng_X_World/2.0, leng_Y_World/2.0, leng_Z_World/2.0 );

   // Define logical volume
   G4Material* materi_World = materi_Man->FindOrBuildMaterial( "G4_AIR" );
   auto logVol_World = new G4LogicalVolume( solid_World, materi_World, "LogVol_World" );
//  logVol_World->SetVisAttributes ( G4VisAttributes::Invisible );

// Placement of 'World Volume'
   G4int copyNum_World = 0;                 // Set ID number of world
   auto physVol_World  = new G4PVPlacement( G4Transform3D(), "PhysVol_World",
                                           logVol_World, 0, false, copyNum_World );

// Define 'Water Fantom'
   // Define the shape of solid

   G4double leng_X_Water = 30.0*m;           // X-full-length of world
   G4double leng_Y_Water = 30.0*m;           // X-full-length of world
   G4double leng_Z_Water = 30.0*m;           // X-full-length of world

   auto solid_Water = new G4Box( "Solid_Water", leng_X_Water/2.0, leng_Y_Water/2.0, leng_Z_Water/2.0 );

   // Define logical volume
   G4Material* materi_Water = materi_Man->FindOrBuildMaterial( "G4_WATER" );
   auto logVol_Water = new G4LogicalVolume( solid_Water, materi_Water, "LogVol_Water",
                                          0, 0, 0 );

//  logVol_Water->SetVisAttributes ( G4VisAttributes::Visible );


// Placement of two 'Water Fantom' into 'World Volume'
   // Create G4Transform3D to define rotation/translation
   G4double pos_X_LogV = 0.0*cm;            // X-location LogV
   G4double pos_Y_LogV = 0.0*cm;            // Y-location LogV
   G4double pos_Z_LogV = 0.0*cm;            // Z-location LogV
   auto threeVect_LogV = G4ThreeVector( pos_X_LogV, pos_Y_LogV, pos_Z_LogV );
   auto rotMtrx_LogV   = G4RotationMatrix();
   auto trans3D_LogV   = G4Transform3D( rotMtrx_LogV, threeVect_LogV );

   // Install  'Water Fantom'
   G4int copyNum_LogV = 1;               // Set ID number of LogV
   new G4PVPlacement( trans3D_LogV, "PhysVol_Water", logVol_Water,
                      physVol_World, false, copyNum_LogV, true );


// Return the physical volume of 'World'
   return physVol_World;
}
