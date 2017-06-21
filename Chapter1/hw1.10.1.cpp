/* 
 * File:   hw1.10.1.cpp
 * Author: Ramesh Koirala
 *
 * Created on June 7, 2017, 6:21 PM
 * 
 * Problem 1.10.1: Write a program that asks input from the keyboard and prints
 *      the result on the screen and writes it to a file. The question is "What 
 *      is your age?"
 */

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int age;
    cout <<  "What is your age?" <<endl; //print the question on screen.
    cin >> age;                          // Input required.
    cout << "My age is: "<< age << endl; // print input info on screen.
    
    // open a file called age.txt and save input information. 
    ofstream agefile("hw1.10.1_age.txt");              // open a file.
    agefile << "My age is: "<< age << endl;
    agefile.close();                          // close opened file.
    
    
    return 0;
}