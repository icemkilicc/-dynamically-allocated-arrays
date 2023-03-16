
#include <sstream>
#include <fstream>
#include "Reading.h"
#include "Game.h"


using namespace std;

void Clear(int** Mmatrix , int** Kmatrix,int keyMatrix_row,int mapMatrix_row){

    // deallocate memory using delete operator

    for (int i = 0; i < keyMatrix_row; i++) {
        delete[] Kmatrix[i];
    }
    delete[] Kmatrix;

    // deallocate memory using delete operator

    for (int i = 0; i < mapMatrix_row; i++) {
        delete[] Mmatrix[i];
    }
    delete[] Mmatrix;
}

int main(int argc, char** argv) {

    stringstream nums;  nums << argv[1];    int rowMap;
    nums >> rowMap; char y; nums >> y;  int columnMap;
    nums >> columnMap;

    stringstream obj;   int SizeOfKeyMatrix;    obj << argv[2];
    obj >> SizeOfKeyMatrix; obj.clear();

    string MapTxt = argv[3];    string keyTxt = argv[4];    string output = argv[5];


    Reading mapMatrix = Reading(rowMap,columnMap,MapTxt);    //Creating mapMatrix Object
    Reading keyMatrix = Reading(SizeOfKeyMatrix,SizeOfKeyMatrix,keyTxt);        //Creating keyMatrix Object

    int** Mmatrix = new int*[mapMatrix.row];            //Reading Mapmatrix
    Reading::Matrix(mapMatrix.row,mapMatrix.column,mapMatrix.nameOfFile,Mmatrix);

    int** Kmatrix = new int*[keyMatrix.row];    // Reading keyMatrix
    Reading::Matrix(keyMatrix.row,keyMatrix.column,keyMatrix.nameOfFile,Kmatrix);


    int total =0;  int active_row = 0 ; int active_column = 0;
    ofstream file1;
    file1.open(output.c_str());      // creating output file
    //Game Function is the function that makes the game run and Recursive part is there
    Game::Gaming(Mmatrix ,Kmatrix,mapMatrix,keyMatrix,total,active_row,active_column,file1);

    file1.close();

    //Clear matrix from memory
    Clear(Mmatrix,Kmatrix,keyMatrix.row,mapMatrix.row);

    return 0;
}
