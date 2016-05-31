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
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
#include "pq_HEAP.H"
#include <set>
#include <iostream>
#include <climits>
#include <queue>

// This is a struct vertex class. It takes the word and the previous word and 
// the distance. 
struct vertex
{
    string word;
    string prev;
    int distant;
    bool operator < ( vertex v2) const
    {
        if(this -> distant > v2.distant)
            return true;
        return false;
    }
};

// This is my dijkstra function that find teh shortest path. 
map<string, string> dijkstra(map<string, set<string> >neighbors, map<string, int> dictionary,  string begin, string end)
{
  /* 
        I set my source word to the start of the word and and set the distance to
        to zero and the previous word to "", since it's the first word.  
   */
    map<string, string> parent;
    priority_queue<vertex> pq;
    vector< vertex> vertices;

    vertex source;
    source.word      = begin; 
    source.prev     = "";
    source.distant  = 0;
    //Firstly, I push the source into my priority queue and then I loop while 
   // the priority queue is not empty. 
    pq.push(source);
 
    // Then, I create an arbirtrary vertex and get the top element followed by a 
   // pop. I push back into my vector of verticies and have a conditition that 
   // checks if my end word is found, in which case I want to break. If that 
   // condition is not met, I iterate through my neighbor map and push back all 
   // the neighbors as long as it is equal to INT_MAX, because they have not yet
   // been visited. 
    while(!pq.empty())
    {
        vertex v = pq.top();
        pq.pop();
        vertices.push_back(v);
        if(v.word==end)
            break;
        for( set<string>::iterator it = neighbors.find(v.word)-> second.begin(); it!= neighbors.find(v.word)->second.end(); it++)
        {
            if( dictionary.find(*it)-> second == INT_MAX)
            {
                dictionary.find(*it) -> second = v.distant + 1;
                vertex temp;
                temp.word       = dictionary.find(*it) -> first;
                temp.prev       = v.word;
                temp.distant    = dictionary.find(*it) -> second;
                pq.push(temp);
            }
        }
    }
   // 
    int steps = vertices[vertices.size()-1].distant;
    parent.insert(pair<string,string>(end,""));
    string link = end;
    for( int i = 0; i< steps; i++)
    {
        unsigned int position;
        for(position = 0; vertices[position].word != link; position++);

        parent.insert(pair<string,string>(vertices[position].prev, vertices[position].word));
        link = vertices[position].prev;
    }
        
    return parent;
}
// This is a helper function that prints out all the neighbors. It is more for
// testing purposes and I chose to leave it here, because it shows an important
// step I took to completing the assignment
void print_neighbors( map< string, set<string> > neighbors)
{
    map<string, set<string> >::iterator it;
    for( it = neighbors.begin(); it != neighbors.end(); it++)
    {
        cout << "The neighbors of " << it-> first << " are: " << endl;
        set<string>::iterator it2;
        for(it2 = it->second.begin(); it2!= it-> second.end(); it2++)
            cout << (*it2) << endl;
    }
}
// This is a helper function that checks if the word is a neighbor. The logic
// is very straightforward. I just have  counter for the difference and return
// true if the the difference is only one, which means that the word is only one
// letter different making that a neighbor. 
bool one_word_diff(string first, string second)
{
    int i = 0;
    int diff = 0;

    for(; i< 5; i++)
    {
        if(first[i] != second[i])
            diff++;
    }
    
    if(diff==1)
        return true;
    else 
        return false;
}
// this helper function fills all the neighbors into neighbor_list using 
// in_dictionary. 
void fill_neighbors(string word, map<string, int> in_dictionary, set<string> & neighbor_list)
{
    map<string,int>::iterator it;
    for( it = in_dictionary.begin(); it != in_dictionary.end(); it++)
    {
        if(one_word_diff(word, it-> first))
        {
            neighbor_list.insert(it-> first);
        }
    }
}

// printing helper function
void print_parent(map<string, string> parent, string begin, string end)
{
    map<string, string>::iterator it;
    for(string s = begin; s != "" ; s = parent.find(s)-> second)
    {
        cout << s << endl;
        if(s == end) exit(0);
    }
    cerr << "No such ladder found." << endl;
    exit(1);
}
// The main is pretty much identical to the one provided in the specs. The only
// difference is that I insert all the words into in_dictionary and how I call
// my functions, because I added a few more parameters to some function  
int main(int argc, char * argv[])
{
    if(argc != 3){
        cerr << argv[0] << "usage: start end < dictionary\n"; 
        exit(-1); 
    }

    map<string, int> in_dictionary; // easier than a set
    map<string, set<string> > neighbors;

    for( string s ; cin >> s;)
    { 
        in_dictionary.insert(pair<string, int> (s, INT_MAX));
    }
    
    map<string, int>:: iterator it;
    set<string> neighbor_list;
    for( it = in_dictionary.begin(); it != in_dictionary.end(); it++)
    {
        fill_neighbors( it-> first, in_dictionary, neighbor_list);  
        neighbors.insert(pair<string, set<string> >(it-> first, neighbor_list));
        neighbor_list.clear();
    }

   // print_neighbors(neighbors); 

    map<string, string> parent = dijkstra( neighbors, in_dictionary, string(argv[1]), string(argv[2]));

    
    for( string s = argv[1]; s!=""; s= parent.find(s)-> second)
        cout << s << endl;

   
    return 0; 
}
