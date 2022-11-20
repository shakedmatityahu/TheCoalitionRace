#include "../include/Simulation.h"


Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    PartiesByCoalition = vector<vector<int>>;
    // You can change the implementation of the constructor, but not the signature!
}


void Simulation::step()
{
    for(int i=0; i<mAgents.size(); i++)
    {
        mAgents[i].step(*this);
    }
    for(int i=0;i<getGraph().getNumVertices();i++)
    {
        getGraph().getParty(i).step(*this);
    }
}
void Simulation:: init()
{

    int k=0;
    for (int i=0; i<mAgents.size(); i++)
    {
        PartiesByCoalition[i][0]=mAgents[i].getPartyId();

    }
}
bool Simulation::shouldTerminate() const
{
    int countParties=0;
    for(int i=0; i<PartiesByCoalition.size();i++)
    {
        int sumMandates=0;
        for(int k=0;k<PartiesByCoalition[i].size();k++) //check if any coalition reached 61 mandates
        {
            int partyId=PartiesByCoalition[i][k];
            countParties++;
            Party p=getGraph().getParty(partyId);
            sumMandates=+(p).getMandates();
        }
        if(sumMandates>=61)
            return true;
    }
    if(countParties==getGraph().getNumVertices()) //check if all the parties already joined some coalition
        return true;

    else
        return false;

}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    return PartiesByCoalition;
}

vector<int> Simulation::getCoalitionByAgent(int agentId)
{
    return PartiesByCoalition[agentId];
}

