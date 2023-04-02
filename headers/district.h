#ifndef DISTRICT_H
#define DISTRICT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <fstream>
#include <iomanip>
#include "../headers/citizen.h"

using std::cout;    //Access to standard library cout function
using std::cin;     //Access to standard library cin function
using std::endl;    //Access to standard library new line (endl) function
using std::string;   

class District {
    private:
        string name;                //Holds the name of the distric
        int numConnections = 0;     //Used to store the number of connections
        int total_population;       //Used to store the total population
 
    
    public:
        std::map<int, District*> districtConnections;   //Holds all the connections a district has
        std::list<Citizen*> population;                 //Stores the local population of the districts citizens
        
        //-------------------------
        //CONSTRUCTORS/DESTRUCTORS:
        //-------------------------

        //Default Constructor
        District();            

        //Argumented Constructor
        District(string name); 

        //Copy Constructor
        District(District& d);
        //-------------------------


        //------------------
        //GET/SET FUNCTIONS:
        //------------------

        //Used to access the name of district
        //Return: The name of district
        const string getDistrictName();

        //Used to access the size of the population in district
        //Return: Size of the linked list containing the citizens (Of int type)
        const int getPopulationSize();

        //Used to set the connections of each district
        //Return: The vector of district pointers will be updated to match
        void addDistrictConnections(std::vector<District*> connections, District* dist);

        //Used to print the list of connections a district has
        //Return: Prints the connected district name
        const void printConnections();

        //Funciton used to print the citizens contained in the linked list population
        //Return: Prints to the terminal the name of the citizen and what district they are in
        void printPopulation(int index);

        //Funciton used to access the map that holds districts connections to other districts
        //Return: The map districtConnections
        const std::map<int, District*> getDistrictConnections();

        //Function used to access the linked list representing the population in a district
        //Return: The linked list population
        const std::list<Citizen*> getPopulationList();

        const int getNumOfConnections();

        //Used to change the population - called after time clicks, when citizens move
        //Return: Population list will have removed old citizens and added the ones that moved in
        void addCitizen(Citizen* c);

        //Function used to remove a citizen from a districts population list
        //Return: The citizen pointer inside the population list will be gone ;)
        void removeCitizen(Citizen* c);

        //Function used to grab the size of the map districtConnections
        //Return: An int that represents how many connections a district has
        const int getConnectionMapSize();

        //Citizen* getRandomCit(int index);
        //------------------
        
};

#endif