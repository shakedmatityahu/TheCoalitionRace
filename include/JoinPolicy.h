#pragma once
#include <vector>

class Graph;
using std::vector;

class JoinPolicy
{
public:
    virtual int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g) = 0;
    virtual ~JoinPolicy();
    virtual char whoAmI()=0;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g);
    ~MandatesJoinPolicy();
    char whoAmI() override;

};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
    int join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g);
    ~LastOfferJoinPolicy();
    char whoAmI() override;

};