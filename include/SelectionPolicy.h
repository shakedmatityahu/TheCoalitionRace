#pragma once
#include <vector>

using  std::vector;
class Simulation;

class SelectionPolicy {

public:
    virtual int select(vector<int> neighbors, Simulation& sim, int partyId)=0;
    virtual ~SelectionPolicy();
    virtual char whoAmI()=0;

};

class MandatesSelectionPolicy: public SelectionPolicy{

public:
    int select (vector<int> neighbors, Simulation& sim,int partyId);
    ~MandatesSelectionPolicy();
    char whoAmI() override;


};

class EdgeWeightSelectionPolicy: public SelectionPolicy{

public:
    int select (vector<int> neighbors, Simulation& sim,int partyId);
    ~EdgeWeightSelectionPolicy();
    char whoAmI() override;


};