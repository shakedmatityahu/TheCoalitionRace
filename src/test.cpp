#include "Simulation.h"
#include "Parser.h"

void test1()
{
    Simulation simulation=Parser::readSimulation("/home/parallels/CLionProjects/TheCoalitionRace/tests/01.json");
    simulation.step();
    simulation.step();
    simulation.step();
    simulation.step();
}
 int main()
 {
    test1();
 }