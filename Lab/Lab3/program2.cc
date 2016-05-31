#include <iostream>
#include <vector>
using namespace std;

class class1
{
private:
        string word;
public:
        class1()
        :word()
        {}
        class1(string word)
        :word(word)
        {}
        void upper()
        {
                //has to be < instead of <=
                for(unsigned i = 0; i < word.size(); i++)
                {
                        if(islower(word.at(i)))
                        {
                                word.at(i) += 1;
                        }
                }
        }
	void lower()
	{
		int i = 0;
		while( i < word.size())
		{
			word.at(i) -=1;
			i++;//i++ had to at the end of the loop instead
			    // of the beginning 
		}
	}
	void print()
	{
		unsigned i = 0;
		while(i < word.size())
		{
			cout << word.at(i);
			i += 1;//changed from i =1 to i +=1
		}
		cout << endl;
	}
};


class class2
{
private:
	vector<int> number;
public:
	class2()
	:number()
	{}
	class2(int a)
	:number()
	{
		number.push_back(a);
	}

	void add(int a)
	{
		number.push_back(a);
	}

	void sum()
	{
		int total = 0; // initalze to 0 instead of just declaring
		for(unsigned i = 0; i < number.size(); i++)
		{
			total += number.at(i);
		}
		cout << total << endl;
	}

	void list_even()
	{
		for(int i = 0; i < number.size(); i++)
		{
			if(number.at(i) % 2 == 0);//chaneged 1 to 0
			cout << number.at(i) << " ";
		}
		cout << endl;
	}

	void print()
	{
		for(int i = 0; i < number.size(); i++)
		{
			cout << number.at(i) << " ";
		}
		cout << endl;
	}
	
	void power(int a)
	{
		while(a > 1)//0 should be 1
		{
			for(int i = 0; i < number.size(); i++)
			{
				number.at(i) *= number.at(i);
				if(a == 0)
				{
					number.at(i) == 0;
				}
			}
			a--;//a++ should be a--
		}
	}
};

int main()
{
        string input;
        cout << "This program turn any letters inputed into the ones before"
                << " it! \n Then it them all back! \ninput: ";
        getline(cin,input);
	class1 test;
	class1 actual1(input);
	//changes to upper
	cout << "upper: "; 
	actual1.upper();
	actual1.print();
	//changes to lower
	cout << "\nlower: ";
	actual1.lower();
	actual1.print();

	cout << "This program takes in 5 numbers then it prints them out!:" ;
	int a;
	cout << "\nInput 5 numbers: ";
	cin >> a;
	class2 actual(a);
	cin >> a;
	actual.add(a);
	cin >> a;
	actual.add(a);
	cin >> a;
	actual.add(a);
	cin >> a;
	actual.add(a);
	actual.print();
	cout << "Now choose a number put each of the the numbers to the"
		<< "power of: ";
	cin >> a;
	actual.power(a);
	cout << "To the power of " << a << ": ";
	actual.print();
	cout << "The new sum of all of the powered up numbers is ";
	actual.sum();
}

