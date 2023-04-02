#include "../headers/district.h"

//-------------------------
//CONSTRUCTORS/DESTRUCTORS:
//-------------------------
District::District(){
    name = "None";          //Set default name to None 
    numConnections = 0;     //Set the number of connnections of a default district to 0
    total_population = 0;   //Set the default population size to 0
}

District::District(string name){
    this->name = name;      //Set the name to the argument
}


District::District(District& d){
    this->name = d.getDistrictName();                       //Set the district name to that of the district in the argument
    this->numConnections = d.getNumOfConnections();         //Set the number of connections this district has to the number of connections to that of the argument
    this->districtConnections = d.getDistrictConnections(); //Set the connections list equal to that of the arguments
    this->population = d.getPopulationList();               //Set the population list equal to that of the arguments
}
//-------------------------


//------------------
//GET/SET FUNCTIONS:
//------------------
const string District::getDistrictName(){
    return this->name;      //Return the name of current district
}


const int District::getPopulationSize(){
    return this->population.size(); //Return the size of the list holding the citizens
}

void District::addDistrictConnections(std::vector<District*> connections, District* dist){
    this->numConnections++;                                   //Increase the number of connections a district has
    this->districtConnections[numConnections] = dist;         //Add the new district pointer to the map of district connections
}


void District::addCitizen(Citizen* c){
    this->population.push_back(c);      //Add the citizen pointer to the population list
}


void District::removeCitizen(Citizen* c){
    this->population.remove(c);         //Remove the node holding the citizen pointer from the argument
}


const int District::getConnectionMapSize(){
    return this->districtConnections.size();    //Return the size of districtConnections
}


const std::map<int, District*> District::getDistrictConnections(){
    return this->districtConnections;       //return the map districtConnections
}


const std::list<Citizen*> District::getPopulationList(){
    return this->population;        //Return the list of population
}


const int District::getNumOfConnections(){
    return this->numConnections;
}
//------------------


const void District::printConnections(){
    std::map<int, District*>::iterator it = this->districtConnections.begin();  //Create an iterator to cycle through districtConnections - start the iterator at the begining
    while (it != districtConnections.end()) {                                   //While loop runs until end of the list is found
        cout << it->second->getDistrictName() << endl;                          //Derefrence the iterator then derefrence that again and print the name of the current connection
        it++;                                                                   //Move it to the next node in list (districtConnections)
    }
}


template<typename T> void format_print(T t, const int& width) {
    //std::ofstream cout ("Simulation_results.txt");
    //function that simplifies printing the get functions from the class operator
    //utilizes built in functions from iomanip to format
    const char separator = ' ';
    cout << std::left << std::setw(width) << std::setfill(separator) << t;
    //left sets the beginning of the text to be left-aligned
    //setw is called with an int argument which can be changed depending on the amount of space desired between columns
    //setfill fills the width determined by setw with the character specified, when set to  an empty string this creates uniform blank space between the columns
}


void District::printPopulation(int index){
    std::list<Citizen*>::iterator it = this->population.begin();                                                                //Create an iterator to move through the linked list that is population
    cout << endl;                                                                                                               //Spacing
    while (it != population.end()) {                                                                                            //Run while loop until it reaches the end of the list
        const int nameWidth =24;
        const int numWidth =18;

        format_print((*it)->get_name(index), nameWidth);
        format_print((*it)->getState(), numWidth);
        format_print((*it)->currentDistrict, numWidth);

        cout << "\n";
        //cout << (*it)->name << " | Dist: " << (*it)->getState() << " | State: " <<(*it)->currentDistrict << endl;
        it++;
        index--;
    }
}
