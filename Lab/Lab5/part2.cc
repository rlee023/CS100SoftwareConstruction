#include <iostream>
#include <vector>
#include <sstream>

using namespace std; 

string Join(vector<string> v, string token)
{
	string Vec = ""; 

	for(unsigned i = 0; i < v.size(); ++i)
	{
		Vec += v[i]; 
		Vec += " "; 
	}

	istringstream iss(Vec); 
	string temp = ""; 
	string RET = ""; 
	while(iss >> temp)
	{
		RET += temp; 
		RET += token; 
	}
	 
	return RET.substr(0, RET.size()-token.size()); 
}

int main()
{
	vector <string> fill; 
	fill.push_back("apple");
	fill.push_back("orange");
	fill.push_back("grapefruit");

    cout << Join(fill, "AND") << endl;	
	return 0; 
}
