#include<iostream>
#include<unordered_map>
using namespace std;
bool rowcheck_sudoku_test(int** grid,int row,int col){
    for(int j=col+1;j<9;j++){
        if(grid[row][j]==grid[row][col]){
            
            return false;
        }
    }
    
    for(int j=0;j<col;j++){
        if(grid[row][j]==grid[row][col]){
            
            return false;
        }
    }
    
    return true;
}

bool colcheck_sudkou_test(int** grid,int row,int col){
    for(int i=row+1;i<9;i++){
        if(grid[i][col]==grid[row][col]){
           
            return false;
        }
    }
    
    for(int i=0;i<row;i++){
        if(grid[i][col]==grid[row][col]){
            
            return false;
        }
    }
    
    return true;
}

bool grid_check_sudoku_test(int** grid,int row,int col){
    int rowfactor=row-(row%3);
    int colfactor=col-(col%3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if((i+rowfactor)==row&&(j+colfactor==col)){
                continue;
            }else if(grid[i+rowfactor][j+colfactor]==grid[row][col]){
                
                return false;
            }
        }
    }
    
    return true;
}




bool check(int** grid,int row,int col){
    return rowcheck_sudoku_test(grid,row,col) && colcheck_sudkou_test(grid,row,col) && grid_check_sudoku_test(grid,row,col);
}
bool sudokuSolver(int** grid){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
//cout<<grid[2][9]<<endl;
for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
            bool ans=check(grid,i,j);
            
            if(ans==false){
                return false;
            }
        
    }
}
    
return true;
}
