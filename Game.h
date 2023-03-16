//
// Created by lenovo on 26.10.2022.
//

#ifndef DYNAMICMEMORY_GAME_H
#define DYNAMICMEMORY_GAME_H


class Game {
public:
    // Declaration of constructor
    static void Gaming(int** Mmatrix , int** Kmatrix,const Reading& map, const Reading& key,int &total,int &active_row,int &active_column,ofstream &fileM);
};


#endif //DYNAMICMEMORY_GAME_H
