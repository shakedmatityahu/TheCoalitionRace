#pragma once

class JoinPolicy
{
public:
    virtual void join(Party &p, Agent &agn) = 0;
};

class MandatesJoinPolicy : public JoinPolicy
{
public:
    void join(Party &p, Agent &agn);
};

class LastOfferJoinPolicy : public JoinPolicy {};