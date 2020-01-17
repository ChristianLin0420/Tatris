#include <iostream>
#include <string>
#include <fstream>

#include "GameInitial.hpp"
#include "TatrisElement.hpp"
#include "ProcessGameCommends.hpp"

#define MAX_COMMEND_SIZE 1010

using namespace std;

FILE* solution_file;

void wirteAnswerToFile(int** currentBoard, int row, int column, FILE* file) {
    for (int i = 3; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (currentBoard[i][j] == -1) fprintf(file, "%d", 0);
            else if (currentBoard[i][j] == -2) fprintf(file, "%d", 1);
            else fprintf(file, "%d", currentBoard[i][j]);
        }
        fprintf(file, "\n");
    }
}

int main() {

    // Read GameCommend.txt and receive all commends
    ifstream GameFile;
    string GameCommend[MAX_COMMEND_SIZE];
    GameFile.open("Tetris.data");
    solution_file = fopen("Tetris.final", "w");
    
    // using getline() to store every comment line to GameCommend
    string line;
    int currentStoreIndex = 0;
    
    // TatrisBoard parameters
    int** CurrentTetrisBoard;
    int Board_row = 0, Board_column = 0;
    
    // TatrisElement parameters
    TatrisElement* CommendArray;
    int CommendCount;
    
    if (GameFile.is_open()) {

        while (!GameFile.eof()) {  // read the file until EOF
            getline(GameFile, line);
            GameCommend[currentStoreIndex++] = line;
        }

        GameFile.close();
    } else {
        cout << "Cannot read GameCommedn.txt!!!" << endl;
    }
    
    CommendArray = new TatrisElement[currentStoreIndex - 2];
    
    int Multiplicand = 1;
    int matrix_coordinate_flag = true;
    
    for (int i = 0; i < 5; i++) {
        if (isdigit(GameCommend[0][i]) && matrix_coordinate_flag) { // calculate the number of Board_row
            Board_row *= Multiplicand;
            Multiplicand *= 10;
            Board_row += GameCommend[0][i] - '0';
        } else if (isdigit(GameCommend[0][i]) && !matrix_coordinate_flag) { // calculate the number of Board_column
            Board_column *= Multiplicand;
            Multiplicand *= 10;
            Board_column += GameCommend[0][i] - '0';
        } else {
            Multiplicand = 1;
            matrix_coordinate_flag = !matrix_coordinate_flag;
        }
    }
    
    Board_row += 3;
    
    // Initial TatrisBoard
    CurrentTetrisBoard = CreateTatrisBoard(Board_row, Board_column);
    
    // Processing Commend and return GameComments array
    CommendArray = CreateCommednStream(GameCommend, currentStoreIndex);
    CommendCount = ReturnCommendCount();

    // Start playing game
    for (int i = 0; i < CommendCount; i++) {
        CurrentTetrisBoard = drawTatrisOnBoard(CurrentTetrisBoard, Board_row, Board_column, CommendArray[i]);
        if (CurrentTetrisBoard[0][0] == -1 || CurrentTetrisBoard[0][0] == -2) break;
    }
    
    //DrawCurrentStateOfBoard(CurrentTetrisBoard, Board_row, Board_column);
    
    wirteAnswerToFile(CurrentTetrisBoard, Board_row, Board_column, solution_file);
    fclose(solution_file);
    
    return 0;
}
