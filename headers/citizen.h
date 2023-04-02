#ifndef CITIZEN_H
#define CITIZEN_H

#include <iostream>
#include <vector>
#include <fstream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;



class Citizen {
    public:
        string name;
        string currentDistrict;
    
        Citizen();

        const string getDistrictName();

        virtual const string getState() = 0;

        virtual const void printDenizen(int index) = 0;

        virtual void setState(string newState) = 0;

        virtual void takeAction(Citizen* &validCit) = 0;

        void name_citizens(vector<string> &names);

        void set_name(vector<string>names) { this->name_citizens(names); }

        const string get_name(int index);

        vector<string> makeVector(int index);

};

#endif