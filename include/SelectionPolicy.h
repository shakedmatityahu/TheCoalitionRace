#pragma once
#include <vector>

using  std::vector;
class Simulation;

class SelectionPolicy {

public:
    virtual int select(vector<int> neighbors, Simulation& sim, int partyId)=0;
    virtual ~SelectionPolicy()= default;;
    virtual SelectionPolicy* clone() const =0;
};

class MandatesSelectionPolicy: public SelectionPolicy{

public:
    int select (vector<int> neighbors, Simulation& sim,int partyId);
    ~MandatesSelectionPolicy() = default;;
    MandatesSelectionPolicy* clone() const;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{

public:
    int select (vector<int> neighbors, Simulation& sim,int partyId);
    ~EdgeWeightSelectionPolicy() = default;;
    EdgeWeightSelectionPolicy* clone() const;
};