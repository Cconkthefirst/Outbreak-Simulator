#include "../headers/simulator.h"

void Simulator::populateSim(Citizen* C){
    this->simPopulation.push_back(C);
}


int Simulator::random(int low, int high) {
    std::random_device rd;
    std::mt19937 gen(rd()); //uses mersenne twister algorithm from random library to seed random number generator
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}


void Simulator::populateDistricts(District* curDistrict, int total_population, float d){
    int district_pop = total_population * d;                        //Create a variable to hold the number of citizens in a district (Found by multiplying to total population of the sim by float d representing the percentage)
    if (curDistrict->getDistrictName() == "Medical Hill" )          //Check the district - if it is medical hill then enter the if statement
    {
        total_population = total_population - 1;                    //Subtract the total population by one because the code will be adding a zombie instead of base ignorant person
        Citizen* z = new Zombie(curDistrict->getDistrictName());    //Create a new class instance of a Zombie with the right district
        curDistrict->addCitizen(z);                                 //Add that zombie to the local population of the district
        populateSim(z);                                             //Add the same Zombie to tlobal population of the sim
    }
    else if (curDistrict->getDistrictName() == "University" )       //Check the district - if it is University then enter the if
    {
        total_population = total_population - 1;                    //Subtract the total population by one because the code will be adding an alarmed citizen instead of base ignorant person
        Citizen* a = new Alarmed(curDistrict->getDistrictName());   //Create a new class instance of a Alarmed with the right district
        curDistrict->addCitizen(a);                                 //Add that Alarmed to the local population of the district
        populateSim(a);                                             //Add the same Alarmed to tlobal population of the sim
    }
    for(int i =0; i < district_pop; i++) {                          //For loop will run for the entire length of district population
        Citizen* w = new Ignorant(curDistrict->getDistrictName());  //Create a citizen pointer with the argumented constructor citizen(string distname)
        curDistrict->addCitizen(w);                                 //Add the new citizen to the current districts population list
        populateSim(w);                                             //Add the new citizen to the sim population list
    }
    
    curDistrict->printPopulation(district_pop);                     //Print the population - mostly used for testing
    return;
}


template<typename T> void format_print(T t, const int& width) {
    //function that simplifies printing the get functions from the class operator
    //utilizes built in functions from iomanip to format
    //std::ofstream cout ("Simulation_results.txt");
    const char separator = ' ';
    cout << std::left << std::setw(width) << std::setfill(separator) << t;
    //left sets the beginning of the text to be left-aligned
    //setw is called with an int argument which can be changed depending on the amount of space desired between columns
    //setfill fills the width determined by setw with the character specified, when set to  an empty string this creates uniform blank space between the columns
}


void Simulator::printSimPopulation(int days, int index){
    std::list<Citizen*>::iterator it = this->simPopulation.begin();                                     //Create an iterator for a list of citizen pointers - set it to the begining of the simulators total pop. list
    
    while (it != simPopulation.end())                                                                   //Run this while loop until it reaches the end of the population list inside of Simulator class
    {   
        const int nameWidth =24;
        const int numWidth =18;

        format_print((*it)->get_name(index), nameWidth);
        format_print((*it)->getState(), numWidth);
        format_print((*it)->currentDistrict, numWidth);

        cout << "\n";
        //cout << "Name: " << (*it)->name << " | " << "Dist: " << (*it)->currentDistrict << " | " << "State: " << (*it)->getState() << endl;
        it++;
        index--;
    }
    return;
}


void Simulator::createMap(int total_population){
    //std::ofstream cout ("Simulation_results.txt");
    //----------
    //MAP SETUP:
    //----------
    simMap.push_back(new District("Downtown"));             //Add a pointer to Downtown to the map
    simMap.push_back(new District("Medical Hill"));         //Add a pointer to Medical Hill to the map
    simMap.push_back(new District("University"));           //Add a pointer to University to the map
    simMap.push_back(new District("The Burbs"));            //Add a pointer to The Burbs to the map
    setMapConnections();                                    //Set the connections of all the districts in the map
    //----------


    cout << "\n\n\n DOWNTOWN POPULATION: \n";
    cout << "----------------------\n";
    populateDistricts(simMap[0], total_population, 0.62);   //Call populate districts and pass in Downtown, the total population, and .62 the percentage of the population assigned to this district
    cout << "\n\n\n MEDICAL HILL POPULATION: \n";
    cout << "--------------------------\n";
    populateDistricts(simMap[1], total_population, 0.06);   //Call populate districts and pass in Medical Hill, the total population, and .62 the percentage of the population assigned to this district
    cout << "\n\n\n UNIVERSITY POPULATION: \n";
    cout << "------------------------\n";
    populateDistricts(simMap[2], total_population, 0.10);   //Call populate districts and pass in University, the total population, and .62 the percentage of the population assigned to this district
    cout << "\n\n\n THE BURBS POPULATION: \n";
    cout << "-----------------------\n";
    populateDistricts(simMap[3], total_population, 0.22);   //Call populate districts and pass in The Burbs, the total population, and .62 the percentage of the population assigned to this district
    return;
}


void Simulator::setMapConnections(){
    //Index Key:
    //--------------------------
    //Downtown     = simville[0]
    //Medical Hill = simville[1]
    //University   = simville[2]
    //The Burbs    = simville[3]
    //--------------------------

    //Downtown Connections = Medical Hill, University, and The burbs
    simMap[0]->addDistrictConnections(simMap, simMap[1]);         //Add a connection to Medical Hill
    simMap[0]->addDistrictConnections(simMap, simMap[2]);         //Add a connection to the University
    simMap[0]->addDistrictConnections(simMap, simMap[3]);         //Add a connection to the Burbs

    //Medical Hill Connections = Downtown
    simMap[1]->addDistrictConnections(simMap, simMap[0]);         //Add a connection to Downtown

    //University Connections = Downtown, The Burns
    simMap[2]->addDistrictConnections(simMap, simMap[0]);         //Add a connection to Downtown
    simMap[2]->addDistrictConnections(simMap, simMap[3]);         //Add a connection to the Burbs

    //The Burbs Connections = University, Downtown
    simMap[3]->addDistrictConnections(simMap, simMap[0]);         //Add a connection to Downtown
    simMap[3]->addDistrictConnections(simMap, simMap[2]);         //Add a connection to the University
    return;
}


void Simulator::moveCitizens(){
    //Map Refrence:
    //-----------------------------------------------------
    //Downtown     = simville[0]->Connections = [1],[2],[3]|
    //Medical Hill = simville[1]->Connections = [0]        |
    //University   = simville[2]->Connections = [0],[3]    |
    //The Burbs    = simville[3]->Connections = [0],[2]    |
    //-----------------------------------------------------

    int a, x = 0;                                                       //Declares two int variables that are used to create a random index that will represent the district being moved to
    District* curDist;                                                  //This makes a district class point that represents the current district a citizen is in
    std::map<int, District*>::iterator nextDist;                        //Creats a map iterator used to access district population elements and find the next district a citizen will move to
    std::list<Citizen*>::iterator cit = this->simPopulation.begin();    //Makes a list iterator for the simPopulation list

    while (cit != simPopulation.end())                                  //This while loop runs for the entire length of simPopulation(Total Population of all the Districts)
    {
        if ((*cit)->getDistrictName() == "Downtown")                    //If the citizens current district is equal to downtown enter this if statement
        {
            curDist = simMap[0];                                        //Since citizen is in Downtown set their current district equal to downtown - Which according to the simMap = index [0]
        }
        else if ((*cit)->getDistrictName() == "Medical Hill")           //If the citizens current district is equal to Medical Hill enter this if statement
        {
            curDist = simMap[1];                                        //Since citizen is in Medical Hill set their current district equal to downtown - Which according to the simMap = index [1]
        }       
        else if ((*cit)->getDistrictName() == "University")             //If the citizens current district is equal to University enter this if statement
        {
            curDist = simMap[2];                                        //Since citizen is in University set their current district equal to downtown - Which according to the simMap = index [2]
        }
        else if ((*cit)->getDistrictName() == "The Burbs")              //If the citizens current district is equal to The Burbs enter this if statement
        {
            curDist = simMap[3];                                        //Since citizen is in The Burbs set their current district equal to downtown - Which according to the simMap = index [3]
        }
        x = curDist->districtConnections.size();                        //X acts as a divisor, so this sets the value of X to the number of connections a district has
        a = random(1, x);                                               //This sets a to a random index - represented by a random number between 1-X (The number of connections a dist has)
       
        nextDist = curDist->districtConnections.find(a);                //Set the next district equal to the index a that was just found in the line above
        (*cit)->currentDistrict = nextDist->second->getDistrictName();  //Set the name of a citizens current district equal to that of next district
        nextDist->second->addCitizen(*cit);                             //Add the citizen that just moved to their new district population list
        curDist->population.remove(*cit);                               //Remove the citizen that just moved from the previous district 
        cit++;                                                          //Set Cit to the next citizen in the simPopulation
    }
    return;
}


void Simulator::citizenAction(){
    int a = 0;
    District* curDist;
    Citizen* otherCit;
    std::list<Citizen*>::iterator cit = this->simPopulation.begin();

    while (cit != this->simPopulation.end())
    {
        a = (rand()% this->simPopulation.size());
        otherCit = this->getRandomCit(a);
        if ((*cit)->getDistrictName() == otherCit->getDistrictName())
        {
            (*cit)->takeAction(otherCit);
        }
        cit++;
    }
}


void Simulator::run_sim(int days, int total_population) {
    int dayCount =0;
    int hourCount =0;
    int weekCount =0;

    this->createMap(total_population);

    while(dayCount < days) {
        for(int hours=0; hours<24; hours++) {
            this->moveCitizens();
            this->citizenAction();
            hourCount++;
        }
        dayCount++;
    }

    weekCount = dayCount /7;
    int totalDays = dayCount % weekCount;

    cout << "\n\n\n\n UPDATED POPULATION AFTER " << dayCount << " DAYS: \n";
    cout << "-------------------------------------\n\n";

    this->printSimPopulation(days, total_population);

    cout << "\n\n" << weekCount << " weeks and " << totalDays << " days (a total of " << hourCount << " hours) " << "have elapsed since the beginning of the simulation.\n\n\n";
    cout << "\n\n\nEND SIMULATION\n\n\n";

    cout << "\n" << "There are " << simMap[0]->getPopulationSize() << " citizens currently in Downtown.\n";
    cout << "\n" << "There are " << simMap[1]->getPopulationSize() << " citizens currently in Medical Hill.\n";
    cout << "\n" << "There are " << simMap[2]->getPopulationSize() << " citizens currently in the University District.\n";
    cout << "\n" << "There are " << simMap[3]->getPopulationSize() << " citizens currently in The Burbs.";


    return;
}

Citizen* Simulator::getRandomCit(int index){
    std::list<Citizen*>::iterator it = this->simPopulation.begin();
    for (int i = 0; i < index; i++)
    {
        it++;
    }
    Citizen* c = (*it);
    return c;
}