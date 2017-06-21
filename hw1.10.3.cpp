/*
 * Problem 1.10.3
 * 
 * Matrix Market File
 * The matrix market data format is used to store dense and sparse matrices
 *  in ASCII format.
 * 
 * An example matrix market file is (saved in hw1.10.3_MatrixMarket.txt)
 * %%MatrixMarket matrix coordinate real general
    %
    % ATHENS course matrix
    %
        2025    2025    100015
        1       1       .9273558001498543E-01
        1       2       .3545880644900583E-01
 * 
 * The first line that does not start with % contains the number of rows, the
 *  number of columns, and the number of non-zeros elements on the sparse matrix.
 * Use fstream to read the header of a matrix market file and print the number
 *  of rows and coulumns, and the number of non-zeros on the screen.
 */


#include <iostream>
#include <fstream> //to read and write
#include <string>
#include <sstream> // for istringstream

using namespace std;

int main()
{
    ifstream infile("hw1.10.3_MatrixMarket.txt");
    string line;

    while (getline(infile, line))
    {
        istringstream iss(line);
        if (line[0]=='%') {continue;}
        else 
        {
            string row, col, nonzero;
            iss >> skipws >> row >> col >> nonzero;
            cout << "nRows: " << row << endl;
            cout << "nCols: " << col << endl;
            cout << "nNonZeros: " << nonzero << endl;
            break; // just read the first line with nrow, ncols, and nonzeros value.
        }
    }
    infile.close();

    return 0;
}