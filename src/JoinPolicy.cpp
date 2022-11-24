#include "../include/JoinPolicy.h"
#include "../include/Graph.h"

int MandatesJoinPolicy::join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g) {
    // the method selects the coalition with the largest number of mandates
    int max = 0;
    int sum = 0;
    int chosenCoa = -1;
    int curParty = -1;

    // iterating only the coalitions that offered
    int sizeOffers=offs.size();
    for (int i = 0; i < sizeOffers; i++) {
        // iterating the party numbers in that coalition
        int sizeCoalition=partiesBy[i].size();
        for (int j = 0; j <sizeCoalition; j++) {
            curParty = partiesBy[i][j];
            sum += g.getMandates(curParty);
        }
        if (sum > max) {
            max = sum;
            chosenCoa = i;
        };
    }
    return chosenCoa;
}

MandatesJoinPolicy* MandatesJoinPolicy::clone() const
{
    return new MandatesJoinPolicy(*this);
}

int LastOfferJoinPolicy::join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g) {
    // the method selects the coalition that made the last offer
    return offs[offs.size() - 1];
}

LastOfferJoinPolicy* LastOfferJoinPolicy::clone() const
{
    return new LastOfferJoinPolicy(*this);
}