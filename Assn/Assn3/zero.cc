/*
 * Course: CS 100 Summer Session 2 2013
 *
 * First Name: Ryan 
 * Last Name: Lee
 * Username: rlee023
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: assn 3
 * Filename : zero.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
#include "pq_HEAP.H"
   
//  Test top
void helper_test_1( pq_zero<char> pq)
{
    cout << "\ntop is: " << pq.top() << endl << endl; 
}

// Test pop
void helper_test_2( pq_zero<char> pq)
{
    cout << "pop top. Now pq is: \n"; 
    pq.pop(); 
    pq.print();    
}

// Test push
void helper_test_3( pq_zero<char> pq)
{
    cout << "Insert k with priority 0. \n";
    pq.push('k', 0);
    pq.print(); 
}
// test 1. Build heap test.
void test_1()
{
    vector<char>letters;
    vector<float>numbers;
    
    letters.push_back('b');
    letters.push_back('f');
    letters.push_back('a');
    letters.push_back('d');
    letters.push_back('g');
    letters.push_back('c');
    letters.push_back('e');
    letters.push_back('i');
    letters.push_back('h');

    numbers.push_back(5);
    numbers.push_back(8);
    numbers.push_back(9);
    numbers.push_back(7);
    numbers.push_back(3);
    numbers.push_back(2);
    numbers.push_back(1);
    numbers.push_back(0);
    numbers.push_back(4);

    pq_zero<char> pq (letters, numbers);
    pq.print();
    
    helper_test_1(pq); 
    helper_test_2(pq); 
}

// Build a min heap and output it
void helper_func_2(vector<float> p1, vector<int> p2)
{
    cout << "\nUsing the example of building a min heap from the slides, the output is the following: \n\n";
    pq_zero<int> build(p2, p1); 
    build.print();  
}

void test_2()
{
    vector<float> p1; 
    p1.push_back(10);
    p1.push_back(7);
    p1.push_back(14);
    p1.push_back(13);
    p1.push_back(9);
    p1.push_back(6);
    p1.push_back(12);
    p1.push_back(2);
    p1.push_back(19);
   
    vector<int> p1_shadow; 
    p1_shadow.push_back(10);
    p1_shadow.push_back(7);
    p1_shadow.push_back(14);
    p1_shadow.push_back(13);
    p1_shadow.push_back(9);
    p1_shadow.push_back(6);
    p1_shadow.push_back(12);
    p1_shadow.push_back(2);
    p1_shadow.push_back(19);

// test general min heap.
    helper_func_2(p1, p1_shadow);
}

// test pq by pushing in items with the same priority.
void test_3()
{
    cout << "\nCreated a new pq and inserted a, b, c with priorities 1, 1, and 1 respectively. \n\n";

    pq_zero<char> test; 
    test.push('a', 1);
    test.push('b', 1); 
    test.push('c', 1);
    test.print(); 
}
// Test popping off an empty pq 
void test_4()
{
    cout << "\nTest popping of an empty pq: \n";
    pq_zero<char> pq; 
    pq.pop();
}
// Test taking a top of an empty pq
void test_5()
{
    cout << "\n\nTest taking top of an empty pq: \n"; 
    pq_zero<char> pq; 
    pq.top(); 
}

int main()
{
    test_1();
    test_2();
    test_3(); 
    test_4(); 
    test_5(); 
    
    return 0;
}
