#include "../include/JoinPolicy.h"
#include "../include/Graph.h"

int LastOfferJoinPolicy::join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g) {
    // the method selects the coalition that made the last offer
    return offs[offs.size() - 1];
}
