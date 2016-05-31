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
* Filename : main.cc
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#include <vector>
#include <list>
#include <iterator>
#include <typeinfo>
#include <iomanip>
#include "Animal.h"
#include "Mammal.h"
#include "Sea_creature.h"
#include "Bird.h"

using namespace std; 

// Calls the pure virtual function, print that has a different output for each 
// derived class
void interesting_polymorphic_function(list<Animal *> v)
{
    list<Animal *>::iterator it; 
    for(it = v.begin(); it != v.end(); it++) {
       (* it)-> print(); 
       cout << endl; 
    }   
}

int main()
{
    cout << "Welcome to Better-than-actual_Animal_Planet!\n\n"; 

    list < Animal *> Animal_Planet;

    Animal * I_1 = new Mammal(
        "Human", "Earth", "warm blooded", "walking/biking/driving/flying", int(75));
    Animal_Planet.push_back(I_1); 

    Animal * I_2 = new Sea_creature(
        "Octapus", "Ocean or someone's aquarium", "cold-blooded", "cuttle fish",
        "There arms or riding the current");
    Animal_Planet.push_back(I_2); 

    Animal * I_3 = new Bird(
       "Seagull", "Beaches", "Warm blooded", "Bombers", "5 inches");
    Animal_Planet.push_back(I_3); 

    Animal * I_4 = new Mammal(
        "Dog", "People's houses and backyards", "warm blooded", "on four legs"
        , 27); 
    Animal * I_5 = new Bird(
        "bald eagle", "Mountains", "Warm Blooded", "America", "35 inches"); 
    Animal_Planet.push_back(I_4); 
    Animal_Planet.push_back(I_5); 
    
    interesting_polymorphic_function(Animal_Planet);
   
    //Delete all of the pointers now that they have served their purpose
    list<Animal * >::iterator it; 
    for(it = Animal_Planet.begin(); it != Animal_Planet.end(); it++)
        delete (*it); 

    return 0; 
}
