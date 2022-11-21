#pragma once
#include <vector>

using  std::vector;
class Simulation;

class SelectionPolicy {

public:
    virtual int select(vector<int> neighbors, Simulation& sim, int partyId)=0;
    //virtual SelectionPolicy SelectionPolicy(SelectionPolicy* other);

};

class MandatesSelectionPolicy: public SelectionPolicy{

public:
    int select (vector<int> neighbors, Simulation& sim,int partyId);
    //MandatesSelectionPolicy MandatesSelectionPolicy(SelectionPolicy* other);


};

class EdgeWeightSelectionPolicy: public SelectionPolicy{

public:
    int select (vector<int> neighbors, Simulation& sim,int partyId);
    //EdgeWeightSelectionPolicy EdgeWeightSelectionPolicy(SelectionPolicy* other);



};