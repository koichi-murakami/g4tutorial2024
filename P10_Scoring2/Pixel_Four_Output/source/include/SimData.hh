
//  SimData.hh   Serial version

#ifndef SimData_h
#define SimData_h 1

#include "globals.hh"
#include <vector>
#include <tuple>


using Replica = std::tuple<G4int, G4int, G4int>;
using Coordinate = std::tuple<G4double, G4double, G4double>;
struct Hit {
		G4int eventID;
		Replica replica;
		Coordinate coordinate;
		};

class SimData
{

	public :
	SimData() = default;
	~SimData() = default;

	SimData( const SimData& ) = delete;
	void operator = (const SimData& ) = delete;
	
	void Fill (G4int eventID,  Replica replica, Coordinate coordinate ) ;	
        void Initialize();
	const std::vector<Hit>& GetRecord();

private :
        
	
	std::vector<Hit> Record ;	
};

inline void SimData::Fill(G4int eventID, Replica replica, Coordinate coord) 
	{
        Record.push_back({eventID, replica, coord});	
	}	
inline void SimData::Initialize()
	{
	  Record.clear();
	}
inline const std::vector<Hit>& SimData::GetRecord()
	{	
	  return Record ;
	}

#endif
