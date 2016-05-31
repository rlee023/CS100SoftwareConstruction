// Lab done by Allyn Sattler and Ryan Lee
/* ex1
 * This program reads in a list of grades, calculates the average, and prints it to the terminal. 
 * Create your own inputs to test the program and make sure it runs correctly.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
   int grade;
   int numberOfGrades = 0;   // 
   int totalGrades;
   float averageGrade;
   ifstream inputFile;

   const int SENTINEL = -999;

//  open the input file
   inputFile.open("gradesen.dat");

//  read in the grades, total them, and count how many grades there are
//  stop the loop when the sentinel is read
   inputFile >> grade;
   while (grade != SENTINEL)
   {
      cout << "Grade is:  " << grade << endl;
      totalGrades = totalGrades + grade;
      numberOfGrades = numberOfGrades + 1;
      inputFile >> grade;
   }
   cout << "totalGrades: " << totalGrades << endl 
        << "numberOfGrades: " << numberOfGrades << endl;  
    inputFile.close(); 
//  calculate and print the average
   averageGrade = totalGrades / numberOfGrades;
   cout << setiosflags(ios::fixed);
   cout << setiosflags(ios::showpoint);
   cout << setprecision(1);
   cout << "The average grade for the exam is :  " << averageGrade << endl;
}
