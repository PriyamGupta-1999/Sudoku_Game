#include<iostream>
#include<unordered_map>
using namespace std;
bool grid_check(int** grid,int n,int i,int j,int x){
	int row_factor=i-(i%3);
	int col_factor=j-(j%3);

	for (int a = 0; a <3;++a)
	{
		for (int b = 0; b < 3; ++b)
		{
			if(grid[a+row_factor][b+col_factor]==x){
				return false;
			}
		}
	}

	return true;
}

bool col_check(int** grid,int n,int i,int j,int x){
	for (int row = 0; row < n; ++row )
	{
		if(grid[row][j]==x){
			return false;
		}
	}
	return true;
}

bool row_check(int** grid,int n,int i,int j,int x){
	for (int col = 0; col < n; ++col )
	{
		if(grid[i][col]==x){
			return false;
		}
	}
	return true;
}


bool is_palcable(int** grid,int n,int i,int j,int x){
	return row_check(grid,n,i,j,x) && col_check(grid,n,i,j,x) && grid_check(grid,n,i,j,x);
}
bool finder(int** grid,int n,int &row,int &col){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(grid[i][j]==0){
				row=i;
				col=j;
				return true;
			}
		}
	}

	return false;
}
bool  fill_small_grid(int** grid,int n){
	int row,col;
	if(finder(grid,n,row,col)==false){
		// for (int i = 0; i < n; ++i)
	 // {
	 // 	//grid[i]=new int[n];
	 // 	for (int j = 0; j < n;	 ++j)
	 // 	{
	 // 		cout<<grid[i][j]<<" ";
	 // 	}
	 // 	cout<<endl;
	 // } 
		return true;
	}


	for (int a = 1; a <= 9; ++a)
	{
		if(is_palcable(grid,n,row,col,a)){
			grid[row][col]=a;

			bool ans=fill_small_grid(grid,n);
			if(ans==true){

				return true;
			}
			grid[row][col]=0;
		}
	}

	return false;
}
void random_remover(int** grid,int n,int difficulty){
	for (int i = 0; i < difficulty; ++i)
	{
		 grid[rand()%9][rand()%9]=0;
	}
}
int** grid_maker(){
	int n=9;
	int** grid= new int*[n];
	for (int i = 0; i < n; ++i)
	 {
	 	grid[i]=new int[n];
	 	for (int j = 0; j < n;	 ++j)
	 	{
	 		grid[i][j]=0;
	 	}
	 } 

	 grid[0][0]=rand()%9+1;
	 grid[3][3]=rand()%9+1;
	 grid[6][6]=rand()%9+1;


	 // make_sudoku(grid,n,0,0);
	 bool ans=fill_small_grid(grid,n);
	 random_remover(grid,n,80);

	 

	 return grid;
}



// // bool grid_check_sudoku_test(int** grid,int n,int i,int j,int x){
// // 	int row_factor=i-(i%3);
// // 	int col_factor=j-(j%3);

// // 	for (int a = 0; a <3;++a)
// // 	{
// // 		for (int b = 0; b < 3; ++b)
// // 		{
// // 			if(grid[a+row_factor][b+col_factor]==x){
// // 				return false;
// // 			}
// // 		}
// // 	}

// // 	return true;
// // }

// // bool col_check(int** grid,int n,int i,int j,int x){
// // 	for (int row = 0; row < n; ++row )
// // 	{
// // 		if(grid[row][j]==x){
// // 			return false;
// // 		}
// // 	}
// // 	return true;
// // }

// // bool row_check(int** grid,int n,int i,int j,int x){
// // 	for (int col = 0; col < n; ++col )
// // 	{
// // 		if(grid[i][col]==x){
// // 			return false;
// // 		}
// // 	}
// // 	return true;
// // }


// // bool is_palcable(int** grid,int n,int i,int j,int x){
// // 	return row_check(grid,n,i,j,x) && col_check(grid,n,i,j,x) && grid_check_sudoku_test(grid,n,i,j,x);
// // }
// // bool finder(int** grid,int n,int &row,int &col){
// // 	for (int i = 0; i < n; ++i)
// // 	{
// // 		for (int j = 0; j < n; ++j)
// // 		{
// // 			if(grid[i][j]==0){
// // 				row=i;
// // 				col=j;
// // 				return true;
// // 			}
// // 		}
// // 	}

// // 	return false;
// // }
// // bool  fill_small_grid(int** grid,int n){
// // 	int row,col;
// // 	if(finder(grid,n,row,col)==false){
// // 		// for (int i = 0; i < n; ++i)
// // 	 // {
// // 	 // 	//grid[i]=new int[n];
// // 	 // 	for (int j = 0; j < n;	 ++j)
// // 	 // 	{
// // 	 // 		cout<<grid[i][j]<<" ";
// // 	 // 	}
// // 	 // 	cout<<endl;
// // 	 // } 
// // 		return true;
// // 	}


// // 	for (int a = 1; a <= 9; ++a)
// // 	{
// // 		if(is_palcable(grid,n,row,col,a)){
// // 			grid[row][col]=a;

// // 			bool ans=fill_small_grid(grid,n);
// // 			if(ans==true){

// // 				return true;
// // 			}
// // 			grid[row][col]=0;
// // 		}
// // 	}

// // 	return false;
// // }
// // void random_remover(int** grid,int n,int difficulty){
// // 	for (int i = 0; i < difficulty; ++i)
// // 	{
// // 		 grid[rand()%9][rand()%9]=0;
// // 	}
// // }
// // void grid_maker(int** grid){
// // 	int n=9;
	

// // 	 grid[0][0]=rand()%9+1;
// // 	 grid[3][3]=rand()%9+1;
// // 	 grid[6][6]=rand()%9+1;


// // 	 // make_sudoku(grid,n,0,0);
// // 	 bool ans=fill_small_grid(grid,n);
// // 	 random_remover(grid,n,80);

// // 	 for (int i = 0; i < n;	 ++i)

// // 	 {
// // 	 	for (int j = 0; j < n; ++j)
// // 	 	{
// // 	 		cout<<grid[i][j]<<" ";
// // 	 	}
// // 	 	/* code */
// // 	 	cout<<endl;
// // 	 }
// // }



























// bool  fill_small_grid(int** grid,int n,int i,int j,int** helper){
// 	if(j==n-1){
// 		i=i+1;
// 		j=0;	
// 	}

// 	if(i==n){
// 		for (int a = 0; a < n; ++a)
// 		 {
		 	
// 		 	for (int b = 0; b < n;	 ++b)
// 		 	{
		 		
// 		 		cout<<grid[a][b]<<" ";
// 		 		helper[a][b]=grid[a][b];
// 		 	}
// 		 	cout<<endl;
// 		 } 
// 		 return true;

// 	}


// 	for (int a = 1; a < 9; ++a)
// 	{
// 		if(grid[i][j]==0 && is_palcable(grid,n,i,j,a)){
// 			grid[i][j]=a;
// 			bool ans=fill_small_grid(grid,n,i,j+1,helper);
// 			if(ans==true){
// 				return true;
// 			}
// 			grid[i][j]=0;
// 		}
// 	}

// 	return false;
// }

// void fill_grid_dioganal(int** grid,int n){
// 	// unordered_map<int,int>	map1;
// 	// grid[0][0]=(rand() % 9) + 1;
// 	// grid[3][3]=(rand() % 9) + 1;
// 	// grid[6][6]=(rand() % 9) + 1;
	
// 	int k=0;
//   for(int c=0;c<3;c++){

  		
// 		int** helper=new int*[3];
		

// 		for (int i = 0; i < 3; ++i)
// 		 {
// 		 	helper[i]=new int[n];
// 		 	for (int j = 0; j < 3;	 ++j)
// 		 	{
// 		 		helper[i][j]=0;
// 		 	}
// 		 } 
		 	
// 		 helper[0][0]=(rand() % 9) + 1;
// 		 bool ans=fill_small_grid(grid,3,0,0,helper);
		 	

// 		for (int a = 0; a < 3; ++a)
// 			 {
			 	
// 			 	for (int b = 0; b < 3;++b)
// 			 	{
// 			 		grid[a+k][b+k]=helper[a][b];
// 			 	}
// 			 } 
// 			 k=k+3;
// 	 }
	

// }