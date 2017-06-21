/* 
 * File:   hw1.10.2.cpp
 * Author: Ramesh Koirala
 *
 * Created on June 7, 2017, 6:21 PM
 * 
 * Problem 1.10.2: 
 *  1. Write the following declaration: 
 *      pointer to a character, 
 *      array of 10 integers, 
 *      pointer to an array of 10 integers, 
 *      pointer to an array of character string, 
 *      pointer to pointer to a character, 
 *      integer constant,
 *      pointer to an integer constant, 
 *      constant pointer to an integer.
 *      Initialize all these objects.
 * 
 *  2. Make a small program that creates arrays on the stack (fixed-size arrays)
 *      and arrays on the heap (using allocation). Use valgrind to check what 
 *      happens when you do not delete them correctly.
 */

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    // Problem 1
    char *p0;
    shared_ptr<char> p1{new char};   // pointer to a character
    int array1[10];                  // array of 10 integers

    shared_ptr<int> p2{new int[10]}; // pointer to an array of 10 integers
    shared_ptr<char> p3{new char[5]}; // pointer to an array of character string
    char **p4;                       // pointer to pointer to a character
    const int x=10;                  // integer constant
    shared_ptr<const int> p5{new const int}; // pointer to an integer constant
    const shared_ptr<int> p6{new int};       // constant pointer to an integer
    
    delete p4;

    cout << "Here" << endl;
    //Problem 2
   
    return 0;
}