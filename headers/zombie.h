#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "../headers/citizen.h"
#include "../headers/simulator.h"
#include "stdio.h"


class Zombie : public Citizen {
    private:
        string state = "Zombie";


    public:
        Zombie();

        ~Zombie();

        Zombie(string currentDistrict);

        const string getState();

        const void printDenizen(int index);

        void setState(string newState);

        void takeAction(Citizen* &validCit);


};

#endif