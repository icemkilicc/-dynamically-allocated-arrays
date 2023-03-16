#include <iostream>
#include <fstream>
#include "Reading.h"
#include "Game.h"

using namespace std;

void Writer(ofstream &file,int active_row,int key_row,int active_column,int key_column,int total) {

    //Writing output file
    file << active_row+((key_row-1)/2) << "," << active_column+((key_column-1)/2) << ":" << total << endl;

}


void Game::Gaming (int** Mmatrix , int** Kmatrix,const Reading& map, const Reading& key,int &total,int &active_row,int &active_column,ofstream &fileM){


    for(int i = 0 ; i <key.row ; i++){
        for(int j = 0 ; j <key.column ; j++){  // Dot product
            total += (Mmatrix[active_row+i][active_column+j])*(Kmatrix[i][j]); // Multiple of two matrix
        }
    }

    Writer(fileM,active_row,key.row,active_column,key.column,total);

    if(total < 0){
        total = (total%5)+5;
    }

    if(total%5 == 0){
        return;
    }
    else if(total%5 == 1){
        active_row -=key.row;
        if(active_row < 0){             // Five Condition to move on matrix
            active_row +=key.row*2;     // If THE Remainder is not 0, the function call itself again
        }                               // If the remainder is 0 the function return nothing
    }
    else if(total%5 == 2){
        active_row +=key.row;
        if(active_row == map.row){
            active_row -=key.row*2;
        }
    }
    else if(total%5 == 3){
        active_column +=key.column;
        if(active_column == map.column){
            active_column -=key.column*2;
        }
    }
    else if(total%5 == 4){
        active_column -=key.column;
        if(active_column < 0){
            active_column +=key.column*2;
        }
    }
    total = 0;

    Gaming(Mmatrix ,Kmatrix,map,key,total,active_row,active_column,fileM);

}