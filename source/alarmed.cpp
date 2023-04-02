#include "../headers/alarmed.h"

Alarmed::Alarmed(){
    this->name = "Alarmed Denezin"; //Set the default name to that in the " "
    this->currentDistrict = "None"; //Set the default district to none
    this->state = "Alarmed";        //Set the default value of state to alarmed
}

Alarmed::~Alarmed(){}

Alarmed::Alarmed(string currentDistrict){
    this->name = "Alarmed Denezin";             //Set the name of class to value in " "
    this->currentDistrict = currentDistrict;    //Set the current district to that of the arguemnt
}


const string Alarmed::getState(){
    return this->state; //Return the current state of class
}

const void Alarmed::printDenizen(int index){
    cout << "Alarmed:"  << endl;
    cout << "--------"  << endl;
    cout << " ->Name: " << this->get_name(index) << endl;
    cout << " ->District: " << this->getDistrictName() << endl;
    cout << " ->State: " << this->getState() << endl;
}

void Alarmed::setState(string newState){
    this->state = newState;
}

void Alarmed::takeAction(Citizen* &validCit){
    int curCR, otherCR = 0;                             //Declare the two variables to represent the dice rolls for this citizen and the citizen being acted upon
    curCR = rand()%4;                                   //Set the value of current citizen roll(curCR) to a random value between 0-4
    otherCR = rand()%4;                                 //Set the value of other citizen roll(otherCR) to a random value between 0-4

    if (curCR % 2 == 0 && otherCR % 2 == 0)             //If both the die rolls are divisable by two then enter if
    {
        validCit->name = "Alarmed Denezin";
        validCit->setState("Alarmed");  //Set the valid citizen to a new instance of a alarmed with the same distric
    }
}

