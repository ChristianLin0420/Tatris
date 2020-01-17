#ifndef ProcessGameCommends_hpp
#define ProcessGameCommends_hpp

#include <stdio.h>

#include "TatrisElement.hpp"

int** drawTatrisOnBoard(int** currentBoard, int Board_row, int Board_column, TatrisElement newTatrisElement); // Add new Tatris blocks in the Tatris board.
int** detectGameOver(int** currentBoard, int Board_row, int Board_column);
int** detectLineMatch(int** currentBoard, int Board_row, int Board_column); // Check whether the column is filled with 1 only, if yes, delete it.

#endif /* ProcessGameCommends_hpp */
