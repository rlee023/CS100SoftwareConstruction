#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>

using namespace std; 

vector<string> Split(string mess, string token)
{
    string temp = ""; 
    vector<string> RET; 
    istringstream iss(mess); 

    while(iss >> temp)
    {
        if(temp != token)
            RET.push_back(temp);
    }
    return RET; 
}
void print(vector <string> s)
{
    for(unsigned i = 0; i < s.size(); ++i)
        cout << s[i] << " "; 
    cout << endl; 
}

int main()
{
    string message = "a.out &88 b.out &88 c.out"; 
    vector<string> s = Split(message, "&88"); 
    print(s);

    return 0; 
}
