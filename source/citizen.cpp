#include "../headers/citizen.h"

Citizen::Citizen(){
    this->name = "None";
    this->currentDistrict = "None";
}

const string Citizen::getDistrictName(){
    return this->currentDistrict;
}

const string Citizen::getState(){
    return 0;
}

const void Citizen::printDenizen(int index){
    return;
}

void Citizen::setState(string newState){
    return;
}

void Citizen::takeAction(Citizen* &validCit){
    return;
}


void Citizen::name_citizens(vector<string> &names) {
    string line;

    //std::ofstream object;
    //object.open("citizen_directory.txt", std::ofstream::out | std::ofstream::trunc);
    std::ifstream inFile("randCitizenNamesList.txt"); //Open the text file for editing

    if(!inFile.is_open()) {
        std::cerr << "\nERROR inFile was not opened.\n" << std::endl;
    }

    while (getline(inFile, line)){
        //only allows vector to be filled with contents of .txt file while the end of the file has not been reached
        if (line.size() > 0)
            //iterates through the file line by line adding each line to the end of the vector as a separate index
            names.push_back(line);
    }
}

vector<string> Citizen::makeVector(int index) {
    vector <string>vect;
    name_citizens(vect);
    return vect;
}


const string Citizen::get_name(int index) {
    vector<string>names;
    name_citizens(names);
    return names[index];
}