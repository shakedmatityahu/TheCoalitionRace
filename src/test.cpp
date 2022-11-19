#include "Simulation.h"
#include "Parser.h"

void test1()
{
    Simulation simulation=Parser::readSimulation("tests/01.json");
    simulation.step();
    simulation.step();
    simulation.step();
    simulation.step();
}
 int main1()
 {
    test1();
 }