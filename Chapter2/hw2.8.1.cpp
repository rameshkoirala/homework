/* problem 2.8.1 polynomial

    Write a class for polynomial that should at least contain:
        a. A constructor giving the degree of the polynomial
        b. A dynamic array/vector/list of double to store the coefficient
        c. A destructor and
        d. A output function for ostream
*/

#include <iostream>

using namespace std;

class polynomial
{
public:
  polynomial(int deg=0): degree_(deg), index(-1) {array_ = new double [degree_+1];} //constructor
  ~polynomial() {delete [] array_;} //destructor
  void push(const double& item) {array_[++index]=item;}  

private:
  int degree_;
  double* array_;
  int index;
  friend ostream& operator<<(ostream& out, const polynomial& poly);
};

// See http://en.cppreference.com/w/cpp/language/operators for insertion and extraction operator
ostream& operator<<(ostream& out, const polynomial& poly)
{
  int deg = poly.degree_;
  out << "(";
  for (int i = 0; i < (deg - 1); ++i)
    {
    out << poly.array_[i] << ",";
    }
  if (deg>0)
    {
    out << poly.array_[deg-1];
    }
  out << ")";
  return out;
}

int main(){
  int deg=5;
  double coefficient [] = {1.4, 2.8, 0.5, 4, 11.3};
  polynomial P(deg);
  for (int i=0; i<deg; i++)
    {
      P.push(coefficient[i]);
    }
  cout << P << endl;
  return 0;
}
