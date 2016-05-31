#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

bool is_number(char * c)
{
    if(!(*c <= '9' && *c >= '0'))
    {
        return false; 
    }
    return true; 
}

int convert(int argc, char * argv [])
{
    string arg = ""; 
    int sum = 0; 
    int get = 0; 
    
    for(unsigned i = 1; i < argc; ++i)
    {
        if(is_number(argv[i]) == false)
        {
            cerr << "Invalid input\n"; 
            exit(-1); 
        }
    }
    for(unsigned i = 1; i < argc; ++i)
    {
        arg+=argv[i]; 
        arg += " "; 
    }
    
    arg = arg.substr(0, arg.size() - 1); 
    istringstream iss(arg);
    
    for(unsigned i = 0; i < argc; ++i)
    {
        iss >> get; 
        sum += get;
        if(i == argc-1)
            sum -= get; 
    }
    return sum; 
}

int main(int argc, char * argv [])
{
    cout << "sum is: " << convert(argc, argv) << endl; 
    return 0; 
}
