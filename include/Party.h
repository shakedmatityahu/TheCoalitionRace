#pragma once
#include <string>
#include <vector>

using std::string;
using namespace std;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *);
    // Rule of 5
    ~Party(); //destructor
    Party(const Party& other); //copy constructor
    Party& operator=(const Party& other); //copy assignment operator
    Party (Party& other);//move constructor
    Party& operator=(Party && other);//move assignment operator
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    vector<int> getOffers() ;
    void addOffer(int coalitionId);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<int> offers;
    int timer;
};
