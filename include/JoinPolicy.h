#pragma once
#include <vector>

class Graph;

class JoinPolicy
{
public:
    virtual int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g) = 0;
    virtual ~JoinPolicy();
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g);
    ~MandatesJoinPolicy();
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
    int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g);
    ~LastOfferJoinPolicy();
};