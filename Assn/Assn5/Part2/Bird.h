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
* Filename : Bird.h
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#ifndef BIRD_H
#define BIRH_H
#include <iostream>
#include "Animal.h"

using namespace std; 

/* Derived class Bird. Base class is Animal */
class Bird : public Animal
{
    private:
        string Family; 
        string wing_span; 
    public:
        Bird(); 
        Bird(string n, string h, string bt, string f, string ws); 
        virtual void print() const; 
};
#endif 
