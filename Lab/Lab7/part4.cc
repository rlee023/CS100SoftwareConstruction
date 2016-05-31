#include <map>
#include <iostream>
#include <iterator>

using namespace std; 

class phone_book
{
	public:
	map<string, int> book; 

	void push(string n, int p)
	{
		book.insert(pair<string, int> (n, p)); 
	}
	void pop_entry(string n)
	{
		book.erase(n);
	}
	void print()
	{
		for(map<string, int>::iterator it = book.begin(); it != book.end(); it++)
			cout << it->first << " " << it->second << endl; 
	}
	void find(string n)
	{
        int i = 0; 
    	for(map<string, int>::iterator it = book.begin(); it != book.end(); it++)
        {
            if(it->first == n)
            {
                cout << n << " is at index: " << i; 
            }
            i++; 
        }
        cout << endl; 
	}
};

int main()
{
    phone_book a; 
    a.push("John", 1212121); 
    a.push("Aaron", 13131313); 
    a.push("Ryan", 141414); 

    a.print(); 
    a.find("Aaron"); 
    a.pop_entry("Ryan"); 
    cout << endl; 
    a.print(); 
}
