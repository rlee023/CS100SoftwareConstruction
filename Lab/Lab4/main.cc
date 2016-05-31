#include <iostream>
#include "myCString.h"

using namespace std; 

int main()
{
        char * d = new char;
        d = "Old_name";
        char * s = new char; 
        s= "New_name";

        cout << "destination: " << d << endl
             << "Source: "      << s << endl;
         Strcpy(d, s);    
        cout << "destination is now: " << d << endl << endl; 

        char str[80] = "Hello";
        strCat(str, "World!");
        cout << str << endl << endl; 

        char * c1 = new char; 
        c1 = "apple";
        char * c2 = new char; 
        c2 = "apple"; 
        if(Strcmp(c1, c2) == 0)
                cout << "c1 == c2, which is apple\n";
                
        char * C1 = new char; 
        C1 = "zebrahhhhhhhh";
        char * C2 = new char; 
        C2 = "apple"; 
        if(Strcmp(C1, C2) == 1)
                cout << "C1 > C2, which is true. Zebrahhhhhhhh > apple.\n\n";

       char * a = new char;
       a = "simple";
       char * b = new char; 
       b = "this is not simple"; 
       cout << Strstr(b, a);
       cout << endl;

       char * x = new char;
       x = "This is a test";
       cout << strchr(x, 'a'); 

       return 0;
}
