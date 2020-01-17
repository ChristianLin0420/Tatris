#include <iostream>

#include "GameInitial.hpp"

using namespace std;

int** CreateTatrisBoard(int row, int column) {  // Creating a board filled with 0 according to given row and column
    int** TatrisBoard = new int*[row];
    
    for(int i = 0; i < row; i++)
        TatrisBoard[i] = new int[column];
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            TatrisBoard[i][j] = 0;
        }
    }
    
    return TatrisBoard;
}

void DrawCurrentStateOfBoard(int** currentBoard, int row, int column) { // Print out the current board by double pointer
    for (int i = 3; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (currentBoard[i][j] == -1) cout << 0;
            else if (currentBoard[i][j] == -2) cout << 1;
            else cout << currentBoard[i][j];
        }
        cout << endl;
    }
}

