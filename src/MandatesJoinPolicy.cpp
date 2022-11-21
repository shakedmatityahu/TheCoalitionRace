#include "../include/JoinPolicy.h"
#include "../include/Graph.h"

int MandatesJoinPolicy::join(vector<int> &offs, vector<vector<int>> partiesBy, const Graph &g) {
    // the method selects the coalition with the largest number of mandates
    int max = 0;
    int sum = 0;
    int chosenCoa = -1;
    int curParty = -1;

    // iterating only the coalitions that offered
    for (int i = 0; i < offs.size(); i++) {
        // iterating the party numbers in that coalition
        for (int j = 0; i < partiesBy[i].size(); i++) {
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

char  MandatesJoinPolicy:: whoAmI()
{
return 'M';
}