#include<iostream>
#include<unordered_map>
#include "grid_maker.h"
#include "sudoku_checker.h"
using namespace std;
class grid{
public:
int** grid1;

grid(){
	grid1=new int*[9];
}


};

class game{
public:
	grid g;
void insert_grid(){
	 int** grid=new int*[9];
	for (int i = 0; i < 9; ++i)
	{
		grid[i]=new int[9];
		for (int j = 0; j < 9; ++j)
		{
			cin>>grid[i][j];
		}
	}
	g.grid1=grid;
}

void make_new_grid(){
	g.grid1=grid_maker();
}



};


int main(){
	int n=9;
	// grid g;
	// g.grid1=grid_maker();


	 // for (int i = 0; i < n;	 ++i)

	 // {
	 // 	for (int j = 0; j < n; ++j)
	 // 	{
	 // 		cout<<g.grid1[i][j]<<" ";
	 // 	}
	 // 	/* code */
	 // 	cout<<endl;
	 // }
	cout<<"**--------------------------**"<<endl;
	cout<<"**-WELCOME-TO-SUDOKU-GAME-**"<<endl;
	cout<<"1. play new game 2. Press -1 to stop Game"<<endl;
	int ch;
	cin>>ch;
	while(ch!=-1){


	    

		if(ch==1){
			game player;
			cout<<"here is your grid : "<<endl;
			cout<<"--------------------"<<endl;
			player.make_new_grid();

			 for (int i = 0; i < n;	 ++i)

			 {
			 	for (int j = 0; j < n; ++j)
			 	{
			 		cout<<player.g.grid1[i][j]<<" ";
			 	}
			 	/* code */
			 	cout<<endl;
			 }
			 cout<<endl<<endl<<endl;
			 cout<<"enter your sudoku : "<<endl;
			 player.insert_grid();
			 bool ans=sudokuSolver(player.g.grid1);
			 if(ans==true){
			 	cout<<"*** Woooh! You were Correct ***"<<endl<<endl;
			 }else{
			 	cout<<"sorry Wrong ans please try again"<<endl;
			 }

			 cout<<"1. play new game 2. Press -1 to stop Game"<<endl;
			 cin>>ch;
    }

	

	
	 
}

}
