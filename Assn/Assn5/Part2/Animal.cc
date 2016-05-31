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
* Filename : Animal.cc
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/

#include "Animal.h"
#include <iostream>

using namespace std; 

// constructor
Animal::Animal()
{}

// constructor
Animal::Animal(string n, string h, string bt)
 :name(n), habitat(h), blood_type(bt)
{}

// base class print function
void Animal::print() const
{
    cout << "Name: "       << name       << endl
         << "Habitat: "    << habitat    << endl
         << "Blood type: " << blood_type << endl;
}

//virtual destructor
Animal::~Animal()
{
}



