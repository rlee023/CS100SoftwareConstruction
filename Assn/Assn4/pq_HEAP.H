/*
 * Course: CS 100 Summer Session 2 2013
 *
 * First Name: Ryan 
 * Last Name: Lee
 * Username: rlee023
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: assn 4
 * Filename : pq_HEAP.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
 
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
#include <stdexcept>

using namespace std;

template< class Item >
class pq_zero 
{
private:
    vector<Item> heap; // The heap expands/shrinks to fit data
    typedef int indx; // index with heap
    map<Item,indx> index; // records each Item's place in heap
    map<Item,float> priority; // records each Item's priority
    vector<float>p;	      // used for percolate_up and percolate_down

	
    // get's the parent index and returns it.
    int parent(int i)     { return (i-1)/2; }
    // get's the child's index and returns it
    int left_child(int i) { return 2*i+1;   }
    // get's the left child's index and returns it.
    int right_child(int i){ return 2*i+2;   }
    
	// erases whatever is already in the index map. Then it fills it in with 
	// what is currently in the heap vector.
    void reset_index()
    {
        typename map<Item, indx>::iterator it = index.begin(); 
        index.erase(it, index.end()); 

        for(unsigned i = 0; i < heap.size(); ++i)
        {
            index.insert(pair <Item, indx> (heap[i], i) );
        }
    }

    void percolate_up( indx i )
    {
		/* I get the compare item by setting a arbitrary variable, comp, to
		p[i]. Then, I use a while loop while comp less than the parent.
		*/
        float comp = p[i];
        while(i > 0 && comp < p[i/2])
        {
		//essentially, swapping the parent and child while the condition mentioned
		// above holds.
            p[i] = p[i/2]; 
            i /= 2;
        }
        p[i] = comp; 

		// Basically, I just compare the items in the priority map with my
		// priorities vector and fill a sub vector accordingly with the proper
		// min heap values. Then, I perform a vector swap. 
        vector<Item> sub; 
        typename map<Item, float>::iterator it; 
        for(unsigned j = 0; j < p.size(); ++j)
        { 
            for(it = priority.begin(); it != priority.end(); it++)
            {
                if(it->second == p[j])
                    sub.push_back(it->first);
            }
        }
        heap.swap(sub);    
        reset_index(); 
    }     

    void percolate_down( indx i )
    {
	   /* 
	   	 percolate down by looping until my priorities vector's size. I set 
		 lc and rc accordingly each time. It breaks if lc is equal to the priorities
		 size or if p[target] is not less than my comparision value. At this point,
		 when the while loop completes, p[i] is now where I want to insert my comp
		 value, so I do so. 
	   */
       int target = 0;
       int comp = p[i];
       while( (2 * i) <= p.size())
       {
           float lc = left_child(i);
           float rc = right_child(i);
		
           if( rc <= p.size() && p[rc] < p[lc])
               target = rc;
           else if( lc == p.size())
               break;
           else
               target = lc;
	
           if(p[target] < comp)
           {
               p[i] = p[target];
               i = target;
           }
           else 
               break;
       }
       p[i] = comp;
      // Here, I simply find the associated values with my map and create by 
	  // heap. I then swap it with the heap at the end and reset my index using
	  // reset_index. 
       vector<Item> sub; 
       typename map<Item, float>::iterator it; 
       for(unsigned j = 0; j < p.size(); ++j)
       {
            for(it = priority.begin(); it != priority.end(); it++)
            {
                if(it-> second == p[j])
                    sub.push_back(it->first);
            }
       }
       heap.swap(sub); 
       reset_index(); 
    }

public:
    // These use the min-heap functions above.
    pq_zero(vector<Item> h, vector<float> priorities)
     : heap(h), p(priorities)
    {
        for(unsigned i = 0; i < priorities.size(); ++i)
        {
            priority.insert(pair<Item, float> (heap[i], p[i]));
        }
        build_heap(); 
    }

    pq_zero()
    {}
	// This just build's a heap and is called by a constructor. 
    void build_heap()
    {
        // build a min heap using the priority vector using percolate down. 
	    for( int x = (p.size()/2)-1; x >= 0; --x)
            percolate_down(x);
    }
	// The heap is necessary for the test harness. I know no other way of conducting
	// legitamate tests and proving I actually a test harness without a print 
	// function. The print function outputs the values in the priority map, index, 
	// and my heap. 
    void print()
    {
        cout << "priorities: " << endl;
        typename map<Item, float>::iterator it ;
       
        for(it = priority.begin(); it!= priority.end(); it++)
        {
            cout << it -> first << '\t' << it -> second << endl;
        }
        cout << endl << endl << endl;
        cout << "index: " << endl;
        typename map<Item, indx>::iterator it2;
        for(it2 = index.begin(); it2!= index.end();it2++)
        {
            cout << it2 -> first << '\t' << it2 ->second << endl;
        }

        cout << endl << endl << endl;
        cout << "heap: " << endl;
        
        for(unsigned int i = 0; i< heap.size(); i++)
        {
            cout << heap[i]  << endl;
        }
    }
    // I return the size of heap. 
    int size() const { return heap.size();  }

    bool empty() const
    {
        if(size()==0)
            return true;
        return false;
    }
   // I return top. Since it is hq_zero, it's heap[0], not heap[1]. I also try
   // and catch for an underflow error. 
    const Item& top() const 
    {
        try{    
          if(empty())
            throw("Underflow error..");
          else
            return heap[0]; 
        }
        catch(underflow_error & x)
        {
            cerr << "Can't take top of an empty priority queue!" << x.what() << endl; 
        }
        catch(...)
        {
            cerr << "Can't get the top of an empty priority queue..\n"; 
        }
    }
    //Check if it's empty and throw an underflow if it is. Otherwise, I erase
    // the first position in the heap-- heap[0]
	void pop()
    {
          try 
          {
            if(empty())
                throw("underflow error..");
            else
             {
		         Item t = heap[0]; 
		         heap.erase(heap.begin());  
		         priority.erase(t); 
		         index.erase(t); 
            }
          }
          catch(underflow_error & a)
          {
            cerr << "Can't pop from an empty priority queue!" << a.what() << endl; 
          }
          catch(...)
          {
            cerr << "Can't get the pop of an empty priority queue."; 
          }
   }
   //This function resets my priority vector. 
   void reset_p() 
   {
        p.clear(); 
        for(typename map<Item, float>::iterator it = priority.begin(); it != priority.end(); it++)
        {
            p.push_back(it->second); 
        }
    }
    //This function checks if the priority passed in already exists in the priority 
    // vector. 
    bool check_insert(float prio)
    {
        for(unsigned i = 0; i < p.size(); ++i)
        {
            if(prio == p[i])
                return false; 
        }
        return true; 
    }
    
    // Since it's p_zero, I want to push_back to my heap no matter what. If 
	// my priority map is not empty, I check the priority being inserted is 
	// equal to a priority already in my heap. If it is, I find an appropriate 
	// new value for the item being inserted. In which case it should be less.
	// I percolate up if it's not empty() and I reset my index at the end. 
    void push( const Item& w, float prio )
    {
        heap.push_back(w); 
        if(priority.empty() )
        {
            pair<Item, float> a (w, prio); 
            priority.insert(a);
            pair<Item, indx> b (w, 0);
            index.insert(b); 
            p.push_back(prio); 
        }
        else
        {
            typename map<Item, float>::iterator it;
            for(it = priority.begin(); it != priority.end(); it++)
            {
                if(it->second == prio)
                {
                    while(check_insert(prio) == false)
                        prio-=1; 
                }
            }    
            pair<Item, float> a (w, prio); 
            priority.insert(a);
            reset_p();
            indx i = heap.size()-1;
            percolate_up(i);
        }
        reset_index(); 
	}
};
