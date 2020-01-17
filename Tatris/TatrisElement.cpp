#include "TatrisElement.hpp"

#include <iostream>
#include <string>

using namespace std;

int CommendsArray_count = 0;

int T1_array = 111010;
int T2_array = 11101;
int T3_array = 10111;
int T4_array = 101110;
int L1_array = 101011;
int L2_array = 111100;
int L3_array = 110101;
int L4_array = 1111;
int J1_array = 10111;
int J2_array = 100111;
int J3_array = 111010;
int J4_array = 111001;
int S1_array = 11110;
int S2_array = 101101;
int Z1_array = 110011;
int Z2_array = 11110;
int I1_array = 1111;
int I2_array = 1111;
int O_array = 1111;

int** CreateElementArray(int array_index, int row, int column) { // Convert decimal value in to array, and create a stuct to store the array, row, column, start x_coordinate
    
    long int array_number = 0;
    
    switch (array_index) {
        case 361: array_number = T1_array; break;
        case 362: array_number = T2_array; break;
        case 363: array_number = T3_array; break;
        case 364: array_number = T4_array; break;
        case 281: array_number = L1_array; break;
        case 282: array_number = L2_array; break;
        case 283: array_number = L3_array; break;
        case 284: array_number = L4_array; break;
        case 261: array_number = J1_array; break;
        case 262: array_number = J2_array; break;
        case 263: array_number = J3_array; break;
        case 264: array_number = J4_array; break;
        case 351: array_number = S1_array; break;
        case 352: array_number = S2_array; break;
        case 421: array_number = Z1_array; break;
        case 422: array_number = Z2_array; break;
        case 251: array_number = I1_array; break;
        case 252: array_number = I2_array; break;
        case 31: array_number = O_array; break;
        default: break;
    }
    
    int** result_arr = new int*[row];
    
    for(int i = 0; i < row; i++)
        result_arr[i] = new int[column];
    
    for (int i = row - 1; i != -1; i--) {
        for (int j = column - 1; j != -1; j--) {
            result_arr[i][j] = array_number % 10;
            array_number /= 10;
        }
    }
    
    return result_arr;
}

TatrisElement* CreateCommednStream(string* GameCommendsArray, int FileLineCount) { // Convert Commends into [TatrisElement](), so I can process it conviently.
    TatrisElement* TatrisCommendsArray;
    TatrisCommendsArray = new TatrisElement[FileLineCount];
    
    for (int row = 1; row < FileLineCount; row++) {
        int Element_index = 0;
        int x_coordinate = 0;
        int Multiplicand = 1;
        int matrix_coordinate_flag = true;
        
        for (int i = 0; i < 5; i++) {
            if (isdigit(GameCommendsArray[row][i]) && matrix_coordinate_flag) { // calculate the number of Element_index
                Element_index *= Multiplicand;
                Multiplicand *= 10;
                Element_index += GameCommendsArray[row][i] - '0';
            } else if (isdigit(GameCommendsArray[row][i]) && !matrix_coordinate_flag) { // calculate the number of x_coordinate
                x_coordinate *= Multiplicand;
                Multiplicand *= 10;
                x_coordinate += GameCommendsArray[row][i] - '0';
            } else if (isalpha(GameCommendsArray[row][i]) && matrix_coordinate_flag) { // calculate the number of Element_index
                Element_index *= Multiplicand;
                Multiplicand *= 10;
                Element_index += GameCommendsArray[row][i] - '0';
            } else {
                Multiplicand = 1;
                matrix_coordinate_flag = !matrix_coordinate_flag;
            }
        }
        
        if (Element_index != 27252 && Element_index != 0) { // if the index value doesn't equal to 27252 and 0, then
            TatrisElement element;                          // store it in the commends array
            element.TatrisNumber = Element_index;
            element.Start_x_coordinate = x_coordinate;
                        
            switch (Element_index) {
                case 361: element.ElementArray = CreateElementArray(361, 2, 3); element.RowSize = 2; element.ColumnSize = 3; break;
                case 362: element.ElementArray = CreateElementArray(362, 3, 2); element.RowSize = 3; element.ColumnSize = 2; break;
                case 363: element.ElementArray = CreateElementArray(363, 2, 3); element.RowSize = 2; element.ColumnSize = 3; break;
                case 364: element.ElementArray = CreateElementArray(364, 3, 2); element.RowSize = 3; element.ColumnSize = 2; break;
                case 281: element.ElementArray = CreateElementArray(281, 3, 2); element.RowSize = 3; element.ColumnSize = 2; break;
                case 282: element.ElementArray = CreateElementArray(282, 2, 3); element.RowSize = 2; element.ColumnSize = 3; break;
                case 283: element.ElementArray = CreateElementArray(283, 3, 2); element.RowSize = 3; element.ColumnSize = 2; break;
                case 284: element.ElementArray = CreateElementArray(284, 2, 3); element.RowSize = 2; element.ColumnSize = 3; break;
                case 261: element.ElementArray = CreateElementArray(261, 3, 2); element.RowSize = 3; element.ColumnSize = 2; break;
                case 262: element.ElementArray = CreateElementArray(262, 2, 3); element.RowSize = 2; element.ColumnSize = 3; break;
                case 263: element.ElementArray = CreateElementArray(263, 3, 2); element.RowSize = 3; element.ColumnSize = 2; break;
                case 264: element.ElementArray = CreateElementArray(264, 2, 3); element.RowSize = 2; element.ColumnSize = 3; break;
                case 351: element.ElementArray = CreateElementArray(351, 2, 3); element.RowSize = 2; element.ColumnSize = 3; break;
                case 352: element.ElementArray = CreateElementArray(352, 3, 2); element.RowSize = 3; element.ColumnSize = 2; break;
                case 421: element.ElementArray = CreateElementArray(421, 2, 3); element.RowSize = 2; element.ColumnSize = 3; break;
                case 422: element.ElementArray = CreateElementArray(422, 3, 2); element.RowSize = 3; element.ColumnSize = 2; break;
                case 251: element.ElementArray = CreateElementArray(251, 4, 1); element.RowSize = 4; element.ColumnSize = 1; break;
                case 252: element.ElementArray = CreateElementArray(252, 1, 4); element.RowSize = 1; element.ColumnSize = 4; break;
                case 31: element.ElementArray = CreateElementArray(31, 2, 2); element.RowSize = 2; element.ColumnSize = 2; break;
                default: break;
            }
            
            TatrisCommendsArray[CommendsArray_count++] = element;
        }
    }
    
    return TatrisCommendsArray;
}

int ReturnCommendCount() {
    return CommendsArray_count;
}
