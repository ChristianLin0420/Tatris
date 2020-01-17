#include <iostream>

#include "ProcessGameCommends.hpp"
#include "GameInitial.hpp"

using namespace std;


int** detectLineMatch(int** currentBoard, int Board_row, int Board_column) { // Check whether the column is filled with 1 only, if yes, delete it.
        
    bool isLineMatched = true;
    int existRowArray[43] = {0}, existRowArrayCurrentIndex = 0;
    
    for (int row = Board_row - 1 ; row != -1; row--) {
        for (int column = 0; column < Board_column; column++) {
            if (currentBoard[row][column] == 0) {
                isLineMatched = false;
                existRowArray[existRowArrayCurrentIndex++] = row + 1; // Record which line is not filled with 1 only
                break;
            }
        }
    }
            
    int** newBoard = CreateTatrisBoard(Board_row, Board_column); // Create new board to store the row which wasn't filled with 1 only
    int oldFillRowIndex = 0, currentFillRowIndex = Board_row - 1;
        
    while (existRowArray[oldFillRowIndex] != 0 && oldFillRowIndex < 43) {
        for (int column = 0; column < Board_column; column++) {
            newBoard[currentFillRowIndex][column] = currentBoard[existRowArray[oldFillRowIndex] - 1][column];
        }
        currentFillRowIndex--;
        oldFillRowIndex++;
    }
    
    return newBoard;
}

int** detectGameOver(int** currentBoard, int Board_row, int Board_column) {
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < Board_column; j++) {
            if (currentBoard[i][j] == 1) {
                if (currentBoard[3][0] == 1) currentBoard[3][0] = -2;
                else if (currentBoard[3][0] == 0) currentBoard[3][0] = -1;
                return currentBoard;
            }
        }
    }
    
    return currentBoard;
}

int** drawTatrisOnBoard(int** currentBoard, int Board_row, int Board_column, TatrisElement newTatrisElement) { // Add new Tatris blocks in the Tatris board.
    
    if (newTatrisElement.Start_x_coordinate - 1 >= Board_column) { // Check whether the x_coodinate of new Tatris is out of bound or not.
        currentBoard[0][0] = -1;
        return currentBoard;
    }
    
    int row;
    int detectY_coordinate = 0;
    bool foundMatchingY = false;
    
    while (!foundMatchingY) {
        for (detectY_coordinate = newTatrisElement.RowSize - 1; detectY_coordinate < Board_row; detectY_coordinate++) {
            if (foundMatchingY) break;
            
            bool found = false;
            for (int current_row = newTatrisElement.RowSize - 1; current_row != -1; current_row--) {
                for (int current_column = 0; current_column < newTatrisElement.ColumnSize; current_column++) {
                    if (currentBoard[detectY_coordinate + current_row - newTatrisElement.RowSize + 1][newTatrisElement.Start_x_coordinate - 1 + current_column] == newTatrisElement.ElementArray[current_row][current_column] && newTatrisElement.ElementArray[current_row][current_column] == 1) {
                        found = true;
                    } else if (detectY_coordinate == Board_row - 1) {
                        found = true;
                    }
                    if (found) break;
                }
                if (found) break;
            }
            
            if (found) {
                foundMatchingY = true;
                break;
            }
        }
    }
        
    for (row = detectY_coordinate; row != 0; row--) { // Start to set new Tatris and check whether new Tatrsi will overlap with existed cell, if so, then move up until fine a corresponed place to set.
        if (row > -1) {
            bool isValidToDraw = true;
            for (int newTatris_row = newTatrisElement.RowSize - 1; newTatris_row != - 1; newTatris_row --) {
                if (isValidToDraw) {
                    for (int newTatris_column = 0; newTatris_column < newTatrisElement.ColumnSize; newTatris_column++) {
                        if (row + newTatris_row - newTatrisElement.RowSize + 1 > -1) {
                            if (currentBoard[row + newTatris_row - newTatrisElement.RowSize + 1][newTatrisElement.Start_x_coordinate - 1 + newTatris_column] == newTatrisElement.ElementArray[newTatris_row][newTatris_column] && newTatrisElement.ElementArray[newTatris_row][newTatris_column] == 1) {
                                isValidToDraw = false;
                                break;
                            }
                        }
                    }
                } else {
                    break;
                }
            }
            
            if (isValidToDraw) break;
        }
    }
    
    for (int newTatris_row = newTatrisElement.RowSize - 1; newTatris_row != - 1; newTatris_row --) { // Check whether new Tatris will be set out of bound, if so, then we return immdiatelly and Game is over.
        for (int newTatris_column = 0; newTatris_column < newTatrisElement.ColumnSize; newTatris_column++) {
            
            if (row + newTatris_row - newTatrisElement.RowSize + 1 < 0) {
                if (currentBoard[0][0] == 0) currentBoard[0][0] = -1;
                else currentBoard[0][0] = -2;
                return currentBoard;
            }
            
            if (newTatrisElement.ElementArray[newTatris_row][newTatris_column] == 1) {
                currentBoard[row + newTatris_row - newTatrisElement.RowSize + 1][newTatrisElement.Start_x_coordinate - 1 + newTatris_column] = newTatrisElement.ElementArray[newTatris_row][newTatris_column];
            }
        }
    }
    
    currentBoard = detectLineMatch(currentBoard, Board_row, Board_column); // After adding new Tatris in the board, then we need to check
    int** currentBoard_temp = detectGameOver(currentBoard, Board_row, Board_column); // Check whether currentBoard is gameover or not
    
    return currentBoard_temp;
}


