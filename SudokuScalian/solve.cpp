#include <iostream>

using namespace std;

int sudoku[9][9] = {
   {5, 3, 0, 0, 7, 0, 0, 0, 0},
   {6, 0, 0, 1, 9, 5, 0, 0, 0},
   {0, 9, 8, 0, 0, 0, 0, 6, 0},
   {8, 0, 0, 0, 6, 0, 0, 0, 3},
   {4, 0, 0, 8, 0, 3, 0, 0, 1},
   {7, 0, 0, 0, 2, 0, 0, 0, 6},
   {0, 6, 0, 0, 0, 0, 2, 8, 0},
   {0, 0, 0, 4, 1, 9, 0, 0, 5},
   {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

int isInCol(int col, int num)
{
   for (int row = 0; row < 9; row++)
      if (sudoku[row][col] == num)
         return (1);
   return (0);
}

int isInRow(int row, int num)
{
   for (int col = 0; col < 9; col++)
      if (sudoku[row][col] == num)
         return (1);
   return (0);
}

int isInBox(int startRow, int startCol, int num)
{
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (sudoku[row + startRow][col + startCol] == num)
            return (1);
   return (0);
}

void printSudoku(void)
{
    cout << "<--------SOLUTION-------->" << endl;
   for (int fila = 0; fila < 9; fila++)
   {
        for (int col = 0; col < 9; col++)
        {
            cout << sudoku[fila][col] << " ";
            if (col == 2 || col == 5) {
                cout << " | ";
            }
        }
        cout << endl;
        if (fila == 2 || fila == 5)
        {
            for (int i = 0; i < 9; i++)
                cout << "---";
            cout << endl;
        }
    }
}

int isEmpty(int &row, int &col)
{ 
   for (row = 0; row < 9; row++)
      for (col = 0; col < 9; col++)
         if (sudoku[row][col] == 0)
            return (1);
   return (0);
}

int isValidPlace(int row, int col, int num){
    if (isInRow(row, num) || isInCol(col, num) || isInBox(row - row%3, col - col%3, num))
        return(0);
    return (1);
}

int solve(void){
   int row;
   int col;
   
   if (!isEmpty(row, col))
      return (1);
   for (int num = 1; num <= 9; num++)
   {
      if (isValidPlace(row, col, num))
      { 
         sudoku[row][col] = num;
         if (solve())
            return (1);
         sudoku[row][col] = 0;
      }
   }
   return (0);
}

int main(){
   if (solve())
      printSudoku();
   else
      cout << "Cannot solve" << endl;
}
