/* problem 2.8.2 polynomial

    Write a move assignment operator for the polynomial in Exercise 2.8.1
    Define the copy constructor as default. To test whether your assignment is
    used write a function polynomial f(double c2, double c1, double c0) that
    takes three coefficient and returns a polynomial. Print out a message in
    your move assignment or use a debugger to make sure your assignment is used.
    
----------------------------------------------------------------------
Move Assignment Operator:
    Wiki: Move assignment operator = is used for transferring a temporary object to an existing 
    object. The move assignment operator, like most C++ operators, can be overloaded.
    
    https://blog.smartbear.com/c-plus-plus/c11-tutorial-introducing-the-move-constructor-and-
        the-move-assignment-operator/
    The move assignment operator performs four logical steps:
        1. Release any resources that *this currently owns.
        2. Pilfer polynomial‘s resource.
        3. Set polynomial to a default state.
        4. Return *this.
    
Copy Constructor:
    The copy constructor is a constructor which creates an object by initializing it with 
    an object of the same class, which has been created previously. The copy constructor 
    is used to:
        1. Initialize one object from another of the same type.
        2. Copy an object to pass it as an argument to a function.
        3. Copy an object to return it from a function.
    If a copy constructor is not defined in a class, the compiler itself defines one
*/

#include <iostream>

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
                
        //move assignment 
        polynomial& operator= (polynomial&& p)
        {
            delete[] coeff_array;
            degree = p.degree;
            coeff_array = p.coeff_array;
            p.degree = 0;
            p.coeff_array = NULL;
            cout << "Move assignment is used" << endl;
            return *this;
        }
        
        //Copy constructor
        polynomial (const polynomial &p);
        
        //destructor
        ~polynomial(){}
        
};


polynomial f(polynomial p) {return 0;}

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
    int deg = 3;
    double coefficient [] = {1.4, 2.8, 0.5};
    
    //instantiate a class polynomial with 'deg' degree.
    polynomial P(deg);
    
    //Fill coefficient array with the given coefficient. 
    for (int i=0; i<=deg; ++i)
    { 
        P.push(coefficient[i]);   
    }
    
    // Print out the final coefficient array.
    cout << P << endl; // This magic is done due to operator<<
    
    P = f(polynomial(deg)); //This is the place where move assignment is used.
        
    return 0;
}