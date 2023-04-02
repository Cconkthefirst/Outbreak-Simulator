////////////////////////////////
// 
// simulator.h is a base class which...
// author: Jacob Janzen 
// last updated: Fall 2022
//
////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <list>
#include <string>
#include <iomanip>
#include <fstream>
#include <random>
#include "../headers/district.h"
#include "../headers/citizen.h"
#include "../headers/zombie.h"
#include "../headers/alarmed.h"
#include "../headers/ignorant.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

#ifndef SIMULATOR_H
#define SIMULATOR_H

class Simulator {
    private:
    std::list<Citizen*> simPopulation;
    std::vector<District*> simMap;

public:
    
    //Default Constructor
    Simulator() { }

    //Function used to add a citizen to the list of citizen pointers representing the total population of all the districts
    //Argument: A pointer to a citizen
    //Return: The new citizen pointer will be added to the population list
    
    void populateSim(Citizen* C);
    void moveCitizens();
    void printSimPopulation(int days, int index);
    void run_sim(int days, int total_population);
    void createMap(int total_population);
    void setMapConnections();
    void populateDistricts(District* curDistrict, int total_population, float d);  
    void citizenAction();
    int random(int low, int high);
    Citizen* getRandomCit(int index);

};
#endif