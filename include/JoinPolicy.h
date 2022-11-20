#pragma once

class JoinPolicy
{
public:
    virtual void join(vector<Offer> offs, Party &p) = 0;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    void join(vector<Offer> offs, Party &p);
};

class LastOfferJoinPolicy : public JoinPolicy {};