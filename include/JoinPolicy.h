#pragma once

class JoinPolicy
{
public:
<<<<<<< Updated upstream
    virtual void join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g) = 0;

=======
    virtual int join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g) = 0;
>>>>>>> Stashed changes
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
<<<<<<< Updated upstream
    void join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g);

=======
    int join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g);
>>>>>>> Stashed changes
};

class LastOfferJoinPolicy : public JoinPolicy
{
public:
<<<<<<< Updated upstream

    void join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g);

};
=======
    int join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g);
};
>>>>>>> Stashed changes
