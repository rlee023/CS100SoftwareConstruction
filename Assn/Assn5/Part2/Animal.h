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
* Filename : Animal.h
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
/*
This is my Base class. 
*/
using namespace std;

class Animal
{
	protected:
		string name; 
		string habitat;
		string blood_type; 
		
	public: 
		 Animal();
		 Animal(string n, string h, string bt);
		 virtual void print() const = 0;
		 virtual ~Animal(); 
};
#endif 
