#include <iostream>
using namespace std;
#define N 9
void print(int arr[N][N])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
      cout << arr[i][j] << " ";
    cout << endl;
  }
}
bool isSafe(int grid[N][N], int row,
          int col, int num)
{
  for (int x = 0; x <= 8; x++)
    if (grid[row][x] == num)
      return false;
  for (int x = 0; x <= 8; x++)
    if (grid[x][col] == num)
      return false;
  int startRow = row - row % 3,
      startCol = col - col % 3;

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      if (grid[i + startRow][j +
              startCol] == num)
        return false;

  return true;
}
bool solveSudoku(int grid[N][N], int row, int col)
{
  if (row == N - 1 && col == N)
    return true;
  if (col == N) {
    row++;
    col = 0;
  }
  if (grid[row][col] > 0)
    return solveSudoku(grid, row, col + 1);

  for (int num = 1; num <= N; num++)
  {
    if (isSafe(grid, row, col, num))
    {
      grid[row][col] = num;

      if (solveSudoku(grid, row, col + 1))
        return true;
    }

    grid[row][col] = 0;
  }
  return false;
}


int main()
{
    int grid[N][N];
    for(int i=0;i<N;i++){
        cout<<"Enter row "<<i+1<<" of your sudoku(Enter '0' if the number is not present in the grid):\n";
        int k=0;
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
            if((grid[i][j]>9) || (grid[i][j]<0)){
                cout<<"Invalid Input!!\n";
                cout<<"Reenter for row "<<i+1<<" and column "<<j+1;
                cin>>grid[i][j];
            }
        }
    }
    while(1){
        cout<<"Do you want to change any row?(Type 'y' for yes and 'n' for no)";
        char reenter;
        cin>>reenter;
        if(reenter=='y'){
            cout<<"Enter row number: ";
            int reenter_row;
            cin>>reenter_row;
            if(reenter_row>=1 && reenter_row<=9){
                for(int i=0;i<9;i++){
                    cin>>grid[reenter_row-1][i];
                }
            }
            else{
                cout<<"Invalid Input!!\n";
            }
        }
        else if(reenter=='n'){
            break;
        }
        else{
            cout<<"Invalid Input!!\n";
        }
    }

    if (solveSudoku(grid, 0, 0)) print(grid);
    else cout << "no solution exists " << endl;
    return 0;
}

