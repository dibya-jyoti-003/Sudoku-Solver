#include <iostream>
#include <vector>
using namespace std; 
bool isPossible(vector<vector<int>>& sudoku,int row, int col, int value){
    // checks if the guessed value of the row and column is correct or not 
    for (int i=0;i<9;i++){
        if (value == sudoku[row][i] or value == sudoku[i][col])
            return false ;
        if (value== sudoku[3*(row/3)+(i/3)][3*(col/3)+(i%3)])
            return false;
    }
    return true;
}
bool isSudoku(vector<vector<int>>& sudoku){
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            //empty places in the sudoku are denoted by 0
            if (sudoku[i][j] == 0){
                for (int k=1;k<=9;k++){
                    if (isPossible(sudoku,i,j,k)){
                        sudoku[i][j] = k;
                        if (isSudoku(sudoku))return true ;
                        else {
                            //the guess is wrong and solution backtracks to other values 
                            sudoku[i][j] = 0;
                        }
                    }
                }
                return false ;
            }
        }
    }
    return true ;
}
int main(){
    vector<vector<int>> sudoku(9,vector<int>(9,0));
    cout <<"Enter the elements of the Sudoku row wise ,enter 0 if the place is empty----\n";
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            int p;
            cin >> p;
            while (p>9 or p<0){
                cout <<"Invalid input Enter again\n";
                cin >> p;
            }
            sudoku[i][j]=p;
        }
    }
    bool ans = isSudoku(sudoku);
    if (ans == false ){
        cout <<"\n\nInvalid input of sudoku\n";
        return 0;
    }
    cout <<"\n\nThe solved sudoku is -------\n\n\n";
    for (int i=0;i<9;i++){
        for (int j=0;j<9;j++){
            cout << sudoku[i][j]<<" ";
        }
        cout <<endl;
    }
    return 0;
}