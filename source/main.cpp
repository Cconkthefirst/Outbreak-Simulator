////////////////////////
//
// Jacob - Tem - Cade
// December 2022
// CS 273-1
// Final Project (Zombie Sim)
// Resources Used:
// ---------------
// cplusplus.com
// Course textbook
//
////////////////////////


#include "../headers/simulator.h"

#include <ctime>
#include "stdio.h"
#include <fstream>

using std::ofstream;
using std::cout;

int main() {
    ofstream output;
    srand(time(NULL));                                                      //seeds the srand generator with epoch time value 
    Simulator curSimulator;                                                    //creates an object of class Simulator using the non-argumented default constructor defined in that class

    output.open ("simulationResults.txt", ofstream::out | ofstream::trunc); //clears the contents of the output file before each new simulation is compiled

    cout << "\n\nRUNNING SIMULATION...\n\n";

    freopen("simulationResults.txt", "w", stdout);
    curSimulator.run_sim(100, 200);                                            //argumented function call allows for no necessary user input.
                                                                            //if function is compiled with the parameters of 365 days and 2000 citizens, the program takes 13:55 to fully compute
    return 0;
}