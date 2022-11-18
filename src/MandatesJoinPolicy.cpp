#include "../include/MandatesJoinPolicy.h"
#include "../include/Party.h"
#include "../include/Agent.h"

void MandatesJoinPolicy::join(Party &p, Agent &agn) {
    p.setState(Joined);

    // clone agent
    Agent clonedAgn = new Agent(agn.getId(), agn.getPartyId(), agn.????????)
}
