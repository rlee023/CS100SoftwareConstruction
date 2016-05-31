#include <iostream>
#include <vector>

using namespace std; 

class Stack
{
  private:
    int * array; 
    int size; 
    int capacity; 

  public:
    Stack(int c)
      : size(0), capacity(c+1)
    {
      array = new int[capacity]; 
    }

    int pop()
    {
      int return_value = 0; 
      int size_check = capacity/2;  

      if(size < size_check)
      {
       capacity = size_check; 
       vector<int> temp; 
        for(unsigned i = 0; i < size; ++i)
          temp.push_back(array[i]);
        array = new int[size_check];
        for(unsigned i = 0; i < size; ++i)
           array[i] = temp[i]; 
        cout << "The capacity has changed to: " << capacity << endl;  
      }
      return_value = array[size-1];
      array[size] = 0; 
      size--; 

      return return_value;
    }
    void push(int input)
    {
      int resize = capacity*2; 
      if(size == capacity)
      {
        vector <int> temp; 
        for(unsigned i = 0; i < size; ++i)
          temp.push_back(array[i]); 
        capacity = resize;
        array = new int[capacity]; 
        for(unsigned i = 0; i < size; ++i)
          array[i] = temp[i]; 
        cout << "Capacity has changed. It is now " << capacity << endl; 
        
      }
      array[size] = input; 
      size++; 
    }
    void print()
    {
      for(unsigned i = 0; i < size; ++i)
        cout << array[i] << endl; 
    }
    int operator[](int i)
    {
      return array[i]; 
    }
    int Length()
    {
      int l = capacity; 
      return l; 
    }
}; 

int main()
{
  Stack S(5);
  cout << "Capacity is: " << S.Length() << endl; 

  S.push(6); 
  S.push(5);
  S.push(4);
  S.push(3);
  S.push(2);
  S.push(1);
  S.push(10);

  S.pop(); 
  S.pop();   
   S.pop();    
 S.pop();
 S.pop();
 S.pop();
  return 0; 
}
