
#include "Reading.h"
#include <iostream>
#include <fstream>


using namespace std;

Reading::Reading(int rowC , int columnC , string nameOfFileC){
    row = rowC;
    column = columnC;       //Constructor
    nameOfFile = nameOfFileC;
}

void Reading::Matrix(int row, int column , const string& nameOfFile , int** Mmatrix) {

    ifstream infile;
    infile.open(nameOfFile.c_str());

    // dynamically allocate memory of size `N` for each row
    for (int i = 0; i < row; i++) {
        Mmatrix[i] = new int[column];
    }

    int Msize = 0;        // The program reads file and insert new values to new matrix
    int Mrow = 0;

    if(infile.is_open()){
        int x;              // Every x is an integer from matrix txt file

        while (infile >> x){
            Mmatrix[Mrow][Msize] = x; //inserting
            Msize++;
            if(Msize%column == 0){
                Msize = 0;
                Mrow++;
            }
        }
        infile.close();
    }

    else{
        cout << "The file is not found";
    }
}