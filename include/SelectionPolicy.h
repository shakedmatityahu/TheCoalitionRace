#pragma once

class SelectionPolicy {

public:
    virtual int select(vector<int> neighbors)=0;

};

class MandatesSelectionPolicy: public SelectionPolicy{

    public: int select (vector<int> neighbors)
    {
        int max = *max_element(neighbors.begin(),neighbors.end());


    }
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ };