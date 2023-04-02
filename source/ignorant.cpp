#include "../headers/ignorant.h"

Ignorant::Ignorant(){
    this->name = "Ignorant Denizen";
    this->currentDistrict = "None";
    this->state = "Ignorant";
}

Ignorant::Ignorant(string currentDistrict){
    this->name = "Ignorant Denizen";
    this->currentDistrict = currentDistrict;
}

const string Ignorant::getState(){
    return this->state;     //Return the state of the current class
}

void Ignorant::setState(string newState){
    this->state = newState;     //Set the value of the current state to the argument 
}

const void Ignorant::printDenizen(int index){
    cout << "Ignorant:"  << endl;
    cout << "--------"  << endl;
    cout << " ->Name: " << this->get_name(index) << endl;
    cout << " ->District: " << this->getDistrictName() << endl;
    cout << " ->State: " << this->getState() << endl;
}

void Ignorant::takeAction(Citizen* &vaidCit){
    return;
}