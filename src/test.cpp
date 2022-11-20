#include "Simulation.h"
#include "Parser.h"
#include "Party.h"
void test1()
{
    Simulation simulation=Parser::readSimulation("/home/parallels/CLionProjects/TheCoalitionRace/tests/01.json"); //move assignment operator
//    Party p1=Party(1,"1",20, nullptr);
//    std::cout <<"Party name " << p1.getName() << " Party state "<< p1.getState()<<std::endl;
//    Party p2=p1;
//    std::cout <<"Party name " << p2.getName() << " Party mandates "<< p2.getMandates()<<std::endl;
//    State s= State(1);
//    p1.setState(s);
//    std::cout <<"Party name " << p1.getName() << " Party State "<< p1.getState()<<std::endl;
//    std::cout <<"Party name " << p2.getName() << " Party State "<< p2.getState()<<std::endl;
//     p1=Party(2,"2",40,nullptr);
    Simulation s=simulation; //copy operator




//    simulation.step();
//    simulation.step();
//    simulation.step();
//    simulation.step();
}
 int main()
 {
    test1();
     std::vector<int> v = {2, 1, 3, 6, 7, 9, 8};

     int max = *max_element(v.begin(), v.end());

     std::cout << max << std::endl;
 }