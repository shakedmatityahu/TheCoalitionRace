#include "../include/Simulation.h"
#include "../include/Agent.h"
#include "../include/Party.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents),PartiesByCoalition()
{
    PartiesByCoalition = vector<vector<int>>();
    // You can change the implementation of the constructor, but not the signature!
}


void Simulation::step()
{
    int sizeAgents=mAgents.size();
    for(int i=0; i<sizeAgents; i++)
    {
        mAgents[i].step(*this);
    }
    mGraph.stepParty(*this);

}
void Simulation:: init()
{
    int sizeAgents=mAgents.size();
    for(int i=0; i<sizeAgents; i++)
    {
        vector<int> vec = vector<int>();
        vec.push_back(mAgents[i].getPartyId());
        PartiesByCoalition.push_back(vec);
    }
}
bool Simulation::shouldTerminate() const
{
    int countParties=0;
    int sizePartiesVector=PartiesByCoalition.size();
    for(int i=0; i<sizePartiesVector;i++)
    {
        int sumMandates=0;
        int sizePartiesVectorRow=PartiesByCoalition[i].size();
        for(int k=0;k<sizePartiesVectorRow;k++) //check if any coalition reached 61 mandates
        {
            int partyId=PartiesByCoalition[i][k];
            Party p=getGraph().getParty(partyId);
            sumMandates+=(p).getMandates();
            countParties++;
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

void Simulation:: addPartyToCoalition (int coalitionId, int partyId)
{
    PartiesByCoalition[coalitionId].push_back(partyId);
}
void Simulation::addAgentToVector(Agent agent) {
    mAgents.push_back(agent);
}
void Simulation::simAddOffer(int coalitionId, int partyId) {
    mGraph.graphAddOffer(coalitionId,partyId);
}




