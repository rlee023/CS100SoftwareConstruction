#include <iostream>
#include <vector>
#include <stack>
#include <iterator>

using namespace std; 

template <typename T>
class mystack
{
    stack<T, vector<T> > astack; 

    public:
    T return_top()
    {
        astack.top(); 
    }
    void pop_stack()
    {
        astack.pop(); 
    }
    void push_stack(T input)
    {
        astack.push(input); 
    }
    void reverse_print()
    {
        
        for(unsigned i = 0; i < astack.size()+1; ++i)
        {
            cout << astack.top() << " "; 
            astack.pop(); 
        }
    }
};

int main()
{
  mystack <char> a; 
  
  a.push_stack('a'); 
  a.push_stack('b'); 
  a.push_stack('c'); 
  a.push_stack('d'); 

  cout << "The top is: " << a.return_top() << endl; 

  cout << "pop the back.\n"; 

  cout << "Reverse_print: " << endl; 
  a.reverse_print(); 
  

  return 0; 
}

