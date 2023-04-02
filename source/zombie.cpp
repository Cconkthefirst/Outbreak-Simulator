#include "../headers/zombie.h"

Zombie::Zombie(){
    this->name = "Walker";          //Set the Name to Walker for a Zombie
    this->currentDistrict = "None"; //Set the current district to None
}

Zombie::Zombie(string currentDistrict){
    this->name = "Walker";                      //Set the name to Walker for a Zombie
    this->currentDistrict = currentDistrict;    //Set the currentDistrict to the parameter
}

Zombie::~Zombie(){}

const string Zombie::getState(){
    return this->state;     //Return the state of a combie
}

void Zombie::setState(string newState){
    this->state = newState; //Set the new state of a zombie to the newState in the argument
}

const void Zombie::printDenizen(int index){
    cout << "Zombie:"  << endl;
    cout << "--------"  << endl;
    cout << " ->Name: " << this->get_name(index) << endl;
    cout << " ->District: " << this->getDistrictName() << endl;
    cout << " ->State: " << this->getState() << endl;
}

void Zombie::takeAction(Citizen* &validCit){
    int curCR, otherCR = 0;                             //Declare the two variables to represent the dice rolls for this citizen and the citizen being acted upon
    curCR = rand()%4;                                   //Set the value of current citizen roll(curCR) to a random value between 0-4
    otherCR = rand()%2;                                 //Set the value of other citizen roll(otherCR) to a random value between 0-4

    if (curCR % 2 == 0 && otherCR % 2 == 0)             //If both the die rolls are divisable by two then enter if
    {
        validCit->name = "Walker";
        validCit->setState("Zombie");                            //Return the pointer that points to the citizen a zombie just acted upon
    }
}
