// Lab done by Allyn Sattler and Ryan Lee

//ex2: Program takes up to MAXSIZE number of integers and outputs their sum

#include <iostream>

using namespace std;

int arraysum(const int n, const int a[]);    // Added header to make main 
                                             // function legal. 

int main()
{
	const int MAXSIZE = 50;
	int a[MAXSIZE];
	int n = 0;
	cout << "Enter up to " << MAXSIZE << 
		" integers, ctrl-D to end:\n";
	while ((n < MAXSIZE) && (cin >> a[n])) 
		n++; 
	if (n == 0)
		cout << "nothing entered!\n";
	else
		cout << "sum of input integers = " << 
			arraysum(n, a) << endl;
	return 0 ;
}

// ---- function definition ----

int arraysum(const int n, const int a[])
{
	if (n == 0)
		return 0;           // Changed to 0
	else
		return a[n-1] + arraysum(n-1, a);
}
