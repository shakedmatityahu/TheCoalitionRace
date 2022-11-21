#pragma once
#include <vector>

class Graph;

class JoinPolicy
{
public:
    virtual void join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g) = 0;
    virtual ~JoinPolicy();
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    void join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g);
    ~MandatesJoinPolicy();
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
    void join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g);
    ~LastOfferJoinPolicy();
};