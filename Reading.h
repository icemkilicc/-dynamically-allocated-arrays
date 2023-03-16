
#ifndef DYNAMICMEMORY_READING_H
#define DYNAMICMEMORY_READING_H

#include <string>

using namespace std;


class Reading{
public:
    // Declaration of constructor and other variable
    int row;
    int column;
    string nameOfFile;

    Reading(int row, int column,string nameOfFile);
    static void Matrix(int row, int column, const string& nameOfFile ,int** Mmatrix);

};


#endif //DYNAMICMEMORY_READING_H
