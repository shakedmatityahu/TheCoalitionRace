#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;

class Simulation
{
public:

    Simulation(Graph g, vector<Agent> agents);
    //Rule of 5______________________
    ~Simulation(); //destructor
    Simulation (const Simulation& other); //copy constructor according to rule of 5 we do need it but do we?
    Simulation (Simulation && other) ;//move constructor
    Simulation& operator= (const Simulation& other); // copy assignment operator
    Simulation& operator=( Simulation& other); // move assignment operator

    //______
    void init();
    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    vector<int> getCoalitioByAgent(int agentId) ;




private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<vector<int>> PartiesByCoalition;

};
