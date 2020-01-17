#ifndef TatrisElement_hpp
#define TatrisElement_hpp

#include <stdio.h>
#include <string>

using namespace std;

struct TatrisElement {
    int TatrisNumber;
    int Start_x_coordinate;
    int RowSize;
    int ColumnSize;
    int** ElementArray;
};

int** CreateElementArray(int array_index, int row, int column); // Convert decimal value in to array, and create a struct to store the array, row, column, start x_coordinate
TatrisElement* CreateCommednStream(string* GameCommendsArray, int FileLineCount); // Convert Commends into [TatrisElement](), so I can process it conveniently.
int ReturnCommendCount(); // Return the count of the commends

#endif /* TatrisElement_hpp */
