#pragma once
#include "SelectionPolicy.h"
int MandatesSelectionPolicy:: select (vector<int> neighbors, Simulation& sim,int partyId)
{
    int maxMandates=0;
    int maxParty;
    for(int i=0;i<neighbors.size();i++)
    {
        if(sim.getParty(i).getMandates()>maxMandates)
            maxParty=i;
    }
    return maxParty;
}