// Lab 3. Below is a code to be debugged using gdb.

#include <iostream>
#include <vector>

using namespace std;  

class Calculator
{
  private:
    
  public:

  void divide(int a, int b)
  {
    int new_value = 0; 
    cout << "Enter two numbers you want to divide: "; 
    cin >> a; 
    cin >> b; 
    new_value = a/b; 
    cout << a << " / " << b << " = " << new_value; 
  }

  void add(int a, int b)
  {
    int new_value = 0; 
    cout << "Enter two numbers you want to add: "; 
    cin >> a; 
    cin >> b; 
    new_value = a+b; 
    cout << a << " + " << b << " = " << new_value; 
  }

  void subtract(int a, int b)
  {
    int new_value = 0; 
    cout << "Enter two numbers you want to subtract: "; 
    cin >> a; 
    cin >> b; 
    new_value = a-b; 
    cout << a << " - " << b << " = " << new_value; 
  }

void multiply(int a, int b)
  {
    int new_value = 0; 
    cout << "Enter two numbers you want to multiply: "; 
    cin >> a; 
    cin >> b; 
    new_value = a*b; 
    cout << a << " * " << b << " = " << new_value; 
  }

};

int main()
{
  vector<int> store; 
  int input; 

  //for(;;)  This should be a while loop with a q condition

  cout << "Keep entering numbers or enter -1.\n"; 
  
  while(input >= 0) // accidently set input to < 0  
  {
    cin >> input; 
    store.push_back(input);
  }

  string in; 

  cout << "Enter output if you want to show all the numbers "
       << "you entered."; 
  cin >> in; 

  if(in == "output")
  {
    // a vector has no -1 index position
    for(unsigned i = 0; i < store.size(); ++i)
    {
      if(store[i] != -1)
      cout << store[i] << " ";
    }
  }

  cout << endl; 
  cout << "Lee's Calculator \n";
  string get = ""; 
  // forgot to initialize a1 and b2 to zero.
  int a1 = 0; 
  int b2 = 0; 
  Calculator C; 
  
  while(get != "quit") // this creates a infinite loop 
  {
    cout << "Enter d to divide, a to add, s to subtract, "
         << "m to multiply, or q to quit.\n";
    cin >> get; 
    if(get == "s") // only had one = when if needs two == for
                   // comparisons.. 
    {
       C.subtract(a1, b2);
    }
    else if(get == "a")
    {
       C.add(a1, b2); 
    }
    else if(get == "m")
    {
       C.multiply(a1, b2);
    }
    else if(get == "d")
    {
       C.divide(a1, b2);
    }
    else if(get == "q")
    {
       cout << "You have successfully quited! ;)\n\n"; 
       get = "quit"; 
    }
    else
    {
       cout << "Invalid input.\n"; 
    }
  }
  
  cout << "This is a c++ pointer tutorial!! Here is an example"
       << endl; 
   
  cout << "Below a pointer p is created along with two arbirary"
       << " int variables. First, I set p to the address of "
       << "value1. Then I set *p to 10. I then set p to the "
       << "address of value2. After setting it to the address "
       << "of value 2, I set *p = 20. & is to get the address "
       << "of a variable. Finally, I will output int variable "
       << "and show the result below.\n\n"; 

  int value1, value2; 
  int * p; 

  // Tried to free null...

  *p = NULL; 
  delete p;  
  p = &value1; 
  *p = 10; 
  p = &value2; 
  *p = 20; 

  cout << "value 1 is: " << value1 << endl
       << "value 2 is: " << value2 << endl << endl
       << "Like magic! Hope this helps.\n"; 

  int x = 5; 
  //cant something by 0
  //   x/=0; 
  return 0;  

   // should just return 0!!!... 

   // return 12391231293;  
}
