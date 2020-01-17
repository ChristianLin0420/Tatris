//
//  GameInitial.hpp
//  Tatris
//
//  Created by Christian on 2019/10/4.
//  Copyright © 2019 Christian. All rights reserved.
//

#ifndef GameInitial_hpp
#define GameInitial_hpp

#include <stdio.h>

int** CreateTatrisBoard(int row, int column); // Creating a board filled with 0 according to given row and column
void DrawCurrentStateOfBoard(int** currentBoard, int row, int column); // Print out the current board by double pointer

#endif /* GameInitial_hpp */
