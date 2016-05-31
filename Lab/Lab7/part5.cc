#include <iostream>
#include <vector>
#include <iterator>

using namespace std; 

class my_set
{
    public:
        vector<int> first;
        vector<int> second;
        vector<int> v; 
        my_set(vector<int> f, vector<int> s)
         : first(f), second(s)
        {}
         
        void SU()
        {
            int v_size = first.size() + second.size(); 
            vector<int> v_new (v_size); 
            v.swap(v_new);                
            vector<int>::iterator it;

            //sort (first,first+5);     
            sort (first.begin(),first.end());     
            sort (second.begin(),second.end());   
          
            it=set_union (first.begin(), first.end(), second.begin(), second.end(), v.begin());
                                             
            v.resize(it-v.begin()); 
        }
        void DIFF()
        {
             int v_size = first.size() + second.size(); 
            vector<int> v_new (v_size); 
            v.swap(v_new);                
            vector<int>::iterator it;

            //sort (first,first+5);     
            sort (first.begin(),first.end());     
            sort (second.begin(),second.end());   
          
            it=set_difference (first.begin(), first.end(), second.begin(), second.end(), v.begin());
                                             
            v.resize(it-v.begin()); 
        }
        void INTER()
        {
             int v_size = first.size() + second.size(); 
            vector<int> v_new (v_size); 
            v.swap(v_new);                
            vector<int>::iterator it;

            //sort (first,first+5);     
            sort (first.begin(),first.end());     
            sort (second.begin(),second.end());   
          
            it=set_intersection (first.begin(), first.end(), second.begin(), second.end(), v.begin());
                                             
            v.resize(it-v.begin()); 
        }
        bool INCLU()
        {
            bool test = false; 
            for(unsigned i = 0; i < first.size(); ++i)
            {
                test = false; 
                int comp = first[i];
                for(unsigned j = 0; j < second.size(); ++j)
                {
                    if(comp == second[j])
                        test = true; 
                }
                if(test == false)
                    return false; 
            }
            return true; 
        }
        void print()
        {
            vector<int>::iterator it;
            for (it=v.begin(); it!=v.end(); ++it)
                cout << ' ' << *it;    
            cout << endl; 
        }
}; 

int main()
{
    vector<int> first; //= {5,10,15,20,25};
    first.push_back(5);   
    first.push_back(10);   
    first.push_back(15);
    first.push_back(20);
    first.push_back(25);
    
    vector<int> second;// = {50,40,30,20,10};
    second.push_back(50);
    second.push_back(40);
    second.push_back(30);
    second.push_back(20);
    second.push_back(10);
    my_set a(first, second); 
    a.SU(); 
    a.print(); 
    a.DIFF();
    a.print();
    a.INTER();
    a.print();
    if(a.INCLU() == false)
        cout << "is false\n";
    else
        cout << "is true\n"; 
    cout << endl; 
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    vector<int> c;
    c.push_back(3);  
    c.push_back(2);  
    c.push_back(1);
    my_set q(b, c); 
    if(q.INCLU()) 
        cout << "is true\n"; 
    else
        cout << "is false\n"; 
    
    

}
