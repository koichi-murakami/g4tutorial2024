//  SimData.hh

#ifndef SimData_h
#define SimData_h 1

#include "globals.hh"
#include <vector>
#include <tuple>

using Hit = std::tuple<G4double, G4double> ;
class SimData
{
public :
	SimData() = default;
	~SimData() = default;

	SimData( const SimData& ) = delete;
	void operator = (const SimData& ) = delete;
	
	void Fill ( G4double eval, G4double sval) ;	
        void Initialize();
	const std::vector<Hit>& GetRecord() const;

private :
	std::vector<Hit> Record ;	
};

inline void SimData::Fill(G4double eval, G4double sval) 
	{
          Record.emplace_back(eval, sval);	
	}	
inline void SimData::Initialize()
	{
	  Record.clear();
	}
inline const std::vector<Hit>& SimData::GetRecord() const
	{	
	  return Record ;
	}

#endif
