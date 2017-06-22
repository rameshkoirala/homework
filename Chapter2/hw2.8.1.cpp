/* problem 2.8.1 polynomial

    Write a class for polynomial that should at least contain:
        a. A constructor giving the degree of the polynomial
        b. A dynamic array/vector/list of double to store the coefficient
        c. A destructor and
        d. A output function for ostream
*/

#include <iostream>
#include <vector>

using namespace std;

class polynomial 
{
    public:
        int index=0; //initial value required.
        int degree=0;
        double *coeff_array;  //in future try replacing this with vector.
        
        //constructor
        polynomial(int degree): degree(degree){coeff_array = new double [degree+1];} 
        
        //fill empty array with coefficient
        void push(const double& item) {coeff_array[index++]=item;} 
                
        //destructor
        ~polynomial(){}                
};

//operator overloading to print list of coefficient on the screen.
ostream& operator<<(ostream& out, const polynomial& poly)
{
  int deg = poly.degree;
  out << "( ";
  for (int i = 0; i < deg; ++i)
    {
    out << poly.coeff_array[i] << ", ";
    }
  out << ")";
  return out;
}
       
int main() 
{
    int deg = 5;
    double coefficient [] = {1.4, 2.8, 0.5, 4, 11.3};
    
    //instantiate a class polynomial with 'deg' degree.
    polynomial P(deg);
    
    //Fill coefficient array with the given coefficient. 
    for (int i=0; i<=deg; ++i)
    { 
        P.push(coefficient[i]);   
    }
    
    // Print out the final coefficient array.
    cout << P << endl; // This magic is done due to operator<<
    
    return 0;
}