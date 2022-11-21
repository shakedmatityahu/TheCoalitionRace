#include "../include/JoinPolicy.h"
#include "../include/Graph.h"

void LastOfferJoinPolicy::join(vector<int> &offs, vector<vector<int>> &partiesBy, Graph &g) {
    // the method selects the coalition that made the last offer
    return offs[offs.size() - 1];
}
