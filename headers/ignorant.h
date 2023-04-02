#ifndef IGNORANT_H
#define IGNORANT_H
#include "../headers/citizen.h"

class Ignorant : public Citizen {
    private:
        string state = "Ignorant";

    public:

        Ignorant();

        Ignorant(string currentDistrict);

        const string getState();

        const void printDenizen(int index);

        void setState(string newState);

        void takeAction(Citizen* &validCit);


};

#endif