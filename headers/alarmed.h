#ifndef ALARMED_H
#define ALARMED_H
#include "../headers/citizen.h"

class Alarmed : public Citizen {
    private:
        string state = "Alarmed";   //Holds the value classes state (Ignorant, Alarmed, or Zombie)

    public:
        //Default Constructor
        Alarmed();

        //Destructor
        ~Alarmed();

        //Argumented Constructor
        Alarmed(string currentDistrict);

        //Used to access the classes private vairable state
        const string getState();

        const void printDenizen(int index);

        void setState(string newState);

        void takeAction(Citizen* &validCit);

};

#endif