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
* Filename : Bird.cc
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#include "Bird.h"

Bird::Bird()
{}

Bird::Bird(string n, string h, string bt, string f, string ws)
 : Animal(n, h, bt), Family(f), wing_span(ws)
{}
/* Bird class' print function */
void Bird::print() const
{
    Animal::print(); 
    cout << "Family: " << Family << endl
         << "Wing span: " << wing_span << endl; 
}

