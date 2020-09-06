#include <bits/stdc++.h>
using namespace std;


bool canPlace(vector<vector<int>> &sudoku, int i,int j,int num){

    int n = sudoku.size();
    for(int x = 0;x < n;x++){
        if(sudoku[i][x]==num){
            return false;
        }
    }
    for(int x = 0;x < n;x++){
        if(sudoku[x][j]==num){
            return false;
        }
    }
    int k = sqrt(n);
    int x = i-(i%k);
    int y = j-(j%k);

    for(int i = x;i < x+k; i++){
        for(int j = y; j < y+k;j++){
            if(sudoku[i][j] == num)
                return false;
        }
    }
    return true;
}


bool solveSudoku(vector<vector<int>> &sudoku, int i,int j){

    int n = sudoku.size();

    if(i>=n){

        // print solution
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                cout<<sudoku[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    // when one row ends:
    if(j==n){
        return solveSudoku(sudoku,i+1,0);
    }

    // skip pre filled cells
    if(sudoku[i][j]!=0){
        return solveSudoku(sudoku,i,j+1);
    }

    // rec case
    // check which number can be placed now:
    for(int num = 1;num <= n;num++){

        if(canPlace(sudoku,i,j,num)){

            sudoku[i][j] = num;
            bool isValidMove = solveSudoku(sudoku,i,j+1);
            if(isValidMove){
                return true;
            }
            sudoku[i][j] = 0;
        }
    }   
    return false;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int n;
    cin>>n;
    vector<vector<int>> sudoku(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>sudoku[i][j];
    }

    solveSudoku(sudoku,0,0);
} 

//input
//9
// 3 0 6 5 0 8 4 0 0
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5
// 0 5 0 0 9 0 6 0 0
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0


//ouput
// 3 1 6 5 7 8 4 9 2 
// 5 2 9 1 3 4 7 6 8 
// 4 8 7 6 2 9 5 3 1 
// 2 6 3 4 1 5 9 8 7 
// 9 7 4 8 6 3 1 2 5 
// 8 5 1 7 9 2 6 4 3 
// 1 3 8 9 4 7 2 5 6 
// 6 9 2 3 5 1 8 7 4 
// 7 4 5 2 8 6 3 1 9 


// input
// 9
// 5 3 0 0 7 0 0 0 0
// 6 0 0 1 9 5 0 0 0
// 0 9 8 0 0 0 0 6 0
// 8 0 0 0 6 0 0 0 3
// 4 0 0 8 0 3 0 0 1
// 7 0 0 0 2 0 0 0 6
// 0 6 0 0 0 0 2 8 0
// 0 0 0 4 1 9 0 0 5
// 0 0 0 0 8 0 0 7 9

// output
// 5 3 4 6 7 8 9 1 2 
// 6 7 2 1 9 5 3 4 8 
// 1 9 8 3 4 2 5 6 7 
// 8 5 9 7 6 1 4 2 3 
// 4 2 6 8 5 3 7 9 1 
// 7 1 3 9 2 4 8 5 6 
// 9 6 1 5 3 7 2 8 4 
// 2 8 7 4 1 9 6 3 5 
// 3 4 5 2 8 6 1 7 9 
