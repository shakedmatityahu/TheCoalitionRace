#include "../include/Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    PartiesByCoalition = new vector<vector<int>>;
    // You can change the implementation of the constructor, but not the signature!
}
 Simulation::~Simulation() //destructor
{
    if (PartiesByCoalition)
     delete PartiesByCoalition;
}

Simulation::Simulation(Simulation& other) :mGraph(other.mGraph)//copy constructor
{
    for(int i=0;i<other.mAgents.size();i++)
    {
        mAgents[i]=Agent(other.mAgents[i]);
    }
    PartiesByCoalition=new vector<vector<int>>;
    for(int i=0;i<other.mAgents.size();i++) {
        mAgents[i] = Agent(other.mAgents[i]);
    }
    for(int i=0;i<other.PartiesByCoalition->size();i++)
    {
        for (int k=0;k<(*(other.PartiesByCoalition))[i].size();k++)
        {
            (*PartiesByCoalition)[i][k]=(*(other.PartiesByCoalition))[i][k];

        }
    }

}

Simulation& Simulation::operator=(const Simulation &other) //assignment operator
{
    if(this==&other)
        return *this;
    for(int i=0;i<other.mAgents.size();i++)
    {
        mAgents[i]=Agent(other.mAgents[i]);
    }
    mGraph= Graph(other.mGraph);
    PartiesByCoalition=new vector<vector<int>>;
    for(int i=0;i<other.PartiesByCoalition->size();i++)
    {
        for (int k=0;k<(*(other.PartiesByCoalition))[i].size();k++)
        {
            (*PartiesByCoalition)[i][k]=(*(other.PartiesByCoalition))[i][k];

        }
    }
    return *this;

}

//move constructor other is a rvalue and therefore we dont need to delete it
Simulation :: Simulation(Simulation && other) : mGraph(other.mGraph)
{
    for(int i=0;i<other.mAgents.size();i++)
    {
        mAgents[i]=Agent(other.mAgents[i]);
    }
    PartiesByCoalition=other.PartiesByCoalition;
    other.PartiesByCoalition= nullptr;


}
// move assignment operator "Steal" Resources
Simulation& Simulation:: operator=(Simulation& other)
{
    if(this==&other)
        return *this;
    if(PartiesByCoalition)
        delete PartiesByCoalition;
    for(int i=0;i<other.mAgents.size();i++)
    {
        mAgents[i]=Agent(other.mAgents[i]);
    }
    mGraph=Graph(other.mGraph);
    PartiesByCoalition=other.PartiesByCoalition;
    other.PartiesByCoalition= nullptr;
    return *this;
}


void Simulation::step()
{
    for(int i=0; i<mAgents.size(); i++)
    {
        mAgents[i].step(*this);
    }
}
void Simulation:: init()
{

    int k=0;
    for (int i=0; i<mAgents.size(); i++)
    {
        (*PartiesByCoalition)[i][0]=mAgents[i].getPartyId();

    }
}
bool Simulation::shouldTerminate() const
{
    int countParties=0;
    for(int i=0; i<(*PartiesByCoalition).size();i++)
    {
        int sumMandates=0;
        for(int k=0;k<PartiesByCoalition[i].size();k++) //check if any coalition reached 61 mandates
        {
            int partyId=(*PartiesByCoalition)[i][k];
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
    return *PartiesByCoalition;
}

vector<int> Simulation::getCoalitioByAgent(int agentId)
{
    return (*PartiesByCoalition)[agentId];
}

