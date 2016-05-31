#include <iostream>
#include <iterator>
#include <vector>

using namespace std; 

int main()
{
	vector<int>v; 
	v.push_back(1); 
	v.push_back(2); 
	v.push_back(3); 
	v.push_back(4); 
	v.push_back(5); 

	vector<int>::iterator it = v.begin();
	it = v.insert(it, 100); 

	for(vector<int>::iterator it2 = v.begin(); it2 != v.end(); it2++)
		cout << " " << *it2; 
	cout << endl; 
	
	v.erase(v.begin()+3);
	
	for(vector<int>::iterator it2 = v.begin(); it2 != v.end(); it2++)
		cout << " " << *it2; 
	cout << endl; 

	vector<int> foo; 
	for(unsigned i = 10; i < 20; i++)
		foo.push_back(i); 

	foo.swap(v); 

	cout << "\nfoo now contains: \n"; 
	for(vector<int>::iterator it2 = foo.begin(); it2 != foo.end(); it2++)
		cout << " " << *it2; 
	cout << endl << endl; 

	cout << "v now contains: \n"; 
	for(vector<int>::iterator it2 = v.begin(); it2 != v.end(); it2++)
		cout << " " << *it2; 
	cout << endl; 

	cout << "clear v: \n"; 
	v.clear(); 

	for(vector<int>::iterator it2 = v.begin(); it2 != v.end(); it2++)
		cout << " " << *it2; 
	cout << endl; 

	cout << "v is now empty after calling clear.\n"; 

	return 0; 
}
