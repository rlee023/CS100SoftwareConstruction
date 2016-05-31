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
* Filename : Mammal.cc
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#include "Mammal.h"
// Mammal class constructor
Mammal::Mammal(string n, string h, string bt, string mm, int ls)
 : Animal(n, h, bt), moving_method(mm), life_span(ls)
{}
// Mammal class print function
void Mammal::print() const
{
    Animal::print(); 
    cout << "Moving method: " << moving_method << endl
         << "life span "      << life_span     << endl;  
}

//Mammal class destructor
Mammal::~Mammal()
{} 

