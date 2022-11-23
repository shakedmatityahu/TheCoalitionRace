#pragma once
#include <vector>

class Graph;
using std::vector;

class JoinPolicy
{
public:
    virtual int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g) = 0;
    virtual ~JoinPolicy() = default;
    virtual JoinPolicy* clone() const =0;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g);
    virtual ~MandatesJoinPolicy() = default;
    MandatesJoinPolicy* clone() const;
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
    int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g);
    virtual ~LastOfferJoinPolicy() = default;
    LastOfferJoinPolicy* clone() const;
};