/*
* Course: CS 100 Summer Session 2 2013
*
* First Name: Ryan
* Last Name: Lee
* Username: rlee023
* email address: this must be your cs or UCR student email address
*
*
* Assignment: Assn 5
* Filename : Sea_creature.cc
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#include "Sea_creature.h"
// Sea creature constructor
Sea_creature::Sea_creature()
{}
// Sea creature constructor
Sea_creature::Sea_creature(string n, string h, string bt, string f, string sm)
 : Animal(n, h, bt), Family(f), swimming_method(sm)
{}

// Sea creature print function
void Sea_creature::print() const
{
    Animal::print(); 
    cout << "Family: "          << Family          << endl
         << "swimming method: " << swimming_method << endl; 
}





