#pragma once

class JoinPolicy
{
public:
    virtual void join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g) = 0;

};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    void join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g);

};

class LastOfferJoinPolicy : public JoinPolicy
{
public:

    void join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g);

};
