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
* Filename : Mammal.h
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#ifndef MAMMAL_H
#define MAMMAL_H
#include <iostream>
#include "Animal.h"

using namespace std;
// Mammal Class is the derived class, Animal is the base class
class Mammal : public Animal
{
    private: 
        string Family; 
        string moving_method; 
        int life_span; 
    
    public:

        Mammal(string n, string h, string bt, string mm, int ls); 
        virtual void print() const; 
        //virtual void identifying_quality() const; 
        virtual ~Mammal(); 
};
#endif

