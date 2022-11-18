#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    ~Simulation();
    void init();
    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;



private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<vector<int>>* PartiesByCoalition;

};
