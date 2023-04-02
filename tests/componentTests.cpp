#include "gtest/gtest.h"
#include "../headers/district.h"
#include "../headers/citizen.h"
#include "../headers/ignorant.h"
#include "../headers/zombie.h"
#include "../headers/alarmed.h"
#include "../headers/simulator.h"

// // // ------------------------------------------------ //
// // // COMMENT OUT MAIN IN MAIN.CPP BEFORE RUNNING THIS //
// // // ------------------------------------------------ //

//  int main(int argc, char **argv) {  
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
// }

// TEST (customeDistrict, district){
//    District d("Name");
//    string name;
//    EXPECT_EQ(name = "Name", name == d.getDistrictName());
// }

// TEST (customIgnorant, Ignorant){
//     Ignorant i("Downtown");
//     string name;
//     EXPECT_EQ(name = "Ignorant Denizen", name == i.getName());
// }

// TEST (customZombie, Zombie){
//     Zombie z("Downtown");
//     string name;
//     EXPECT_EQ(name = "Walker", name == z.getName());
// }

// TEST (customAlarmed, Alarmed){
//     Alarmed a("Downtown");
//     string name;
//     EXPECT_EQ(name = "Alarmed Denizen", name == a.getName());
// }

// TEST (alarmedActionTest, actionAlarm){
//     Citizen* a = new Alarmed("Downtown");
//     Citizen* i = new Ignorant("Downtown");
//     a->takeAction(i);
//     EXPECT_EQ(i->getState() == "Alarmed", i->getName() == "Alarmed Denezin");
// }

// TEST (zombieActionTest, actionBite){
//     Citizen* z = new Zombie("Downtown");
//     Citizen* i = new Ignorant("Downtown");
//     z->takeAction(i);
//     EXPECT_EQ(i->getState() == "Zombie", i->getName() == "Walker");
// }

// TEST (addAdistrictConnection, addConnection){
//     std::vector<District*> districts;
//     District* d = new District("Seattle");
//     District* s = new District("Spokane");
//     districts.push_back(d);
//     districts.push_back(s);
//     districts[0]->addDistrictConnections(districts, districts[1]);
//     districts[1]->addDistrictConnections(districts, districts[0]);
//     EXPECT_EQ(d->getConnectionMapSize() == 1, s->getConnectionMapSize() == 1);
// }

// TEST (addCitizenTest, addCitizen){
//     District* d = new District("Downtown");
//     Citizen* c = new Ignorant();
//     d->addCitizen(c);
//     EXPECT_EQ(d->getPopulationSize() == 1, c->currentDistrict == "Downtown");
// }

