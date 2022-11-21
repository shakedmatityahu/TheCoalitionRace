#include "../include/SelectionPolicy.h"
#include "../include/Simulation.h"

int MandatesSelectionPolicy:: select (vector<int> neighbors, Simulation& sim, int partyId)
{
    int maxMandates=0;
    int maxParty;
    int neighborsSize=neighbors.size();
    for(int i=0;i<neighborsSize;i++)
    {
        if(sim.getParty(i).getMandates()>maxMandates)
            maxParty=i;
    }
    return maxParty;
}
char  MandatesSelectionPolicy:: whoAmI()
{
    return 'M';
}