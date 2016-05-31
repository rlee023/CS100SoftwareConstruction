/*
* Course: CS 100 Summer Session 2 2013
*
* First Name: Ryan
* Last Name: Lee
* Username: rlee023
* email address: this must be your cs or UCR student email address
*
*
* Assignment: assn 5
* Filename : Sea_creature.cc
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#ifndef SEA_CREATURE_H
#define SEA_CREATURE_H
#include <iostream>
#include "Animal.h"

using namespace std; 
// Sea Creature is the derived class, Animal is the base class
class Sea_creature : public Animal
{
    private:
        string Family; 
        string swimming_method; 
    public:
        Sea_creature(); 
        Sea_creature(string n, string h, string bt, string f, string sm); 
        virtual void print() const; 
};
#endif
