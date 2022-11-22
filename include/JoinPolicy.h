#pragma once
#include <vector>

class Graph;
using std::vector;

class JoinPolicy
{
public:
    virtual int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g) = 0;
    virtual ~JoinPolicy() = default;
    virtual char whoAmI()=0;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g);
    virtual ~MandatesJoinPolicy() = default;
    char whoAmI() override;
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
    int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g);
    virtual ~LastOfferJoinPolicy() = default;
    char whoAmI() override;
};