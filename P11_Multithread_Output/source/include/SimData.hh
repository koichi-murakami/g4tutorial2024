//
//   SimData.hh

#ifndef SimData_h
#define SimData_h 1

#include "globals.hh"
#include <vector>

class SimData {
public :
	SimData() = default;
	~SimData() = default;

	SimData(const SimData&) = delete;
	void operator = (const SimData&) = delete;

  void Fill(G4double eval, G4double sval);
  void Initialize();
  const std::vector<std::tuple<G4double, G4double>>& GetRecord() const;

private :
	std::vector<std::tuple<G4double, G4double>> Record;
};


inline void SimData::Initialize()
{
	Record.clear();
}

inline void SimData::Fill(G4double eval, G4double sval )
{
  Record.emplace_back(eval, sval);
}

inline const std::vector<std::tuple<G4double, G4double>>& SimData::GetRecord() const
{
  return Record;
}

#endif
