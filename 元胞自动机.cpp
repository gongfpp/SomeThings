//Linux 运行 要是用Windows需要将systemp("clear")改为system("cls")

#include <bits/stdc++.h>
#include <random>
#include <time.h>
#include <unistd.h>
#define N 40
using namespace std;

bool board[N][N];
bool nextBoard[N][N];

void pretation(){
  for (int i = 0; i < N ; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if(i == 0 || i == N-1)  cout << "==";
      else if(j==0 || j == N -1) cout << "||";
      else if(board[i][j]) cout << " +";
      else                  cout << "  ";
    }
    cout << endl;
  }
  
}
void init(){
  
  srand(time(NULL));
  for (int i = 0; i < N ; i++)
  {
    for (int j = 0; j < N; j++)
    {
      board[i][j] = rand()%10 == 0 ? true : false;
    }
    cout << endl;
  }
}
void calculator(){
  int crowd = 0;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if(i == 0 || j == 0 || i == N-1 || j== N-1 ){
        nextBoard[i][j]= false  ;
        continue;
      }
      crowd = 0;
      if(board[i-1][j]) crowd++;
      if(board[i-1][j-1])crowd++;
      if(board[i-1][j+1])crowd++;
      if(board[i][j]) crowd++;
      if(board[i][j-1])crowd++;
      if(board[i][j+1])crowd++;
      if(board[i+1][j]) crowd++;
      if(board[i+1][j-1])crowd++;
      if(board[i+1][j+1])crowd++;
      

      if(crowd >2 && crowd <= 4)
        nextBoard[i][j] = true;
      else
        nextBoard[i][j] = false;

      // if(crowd>4) 
      //   board[i][j] = false;
      // else
      //   board[i][j] =true;
    }
    
  }
  memcpy(board,nextBoard,sizeof(board));
}
int main()
{
  
  init();
  while(true){
    system("clear");
    pretation();
    calculator();
    // getchar();
    usleep(1e5);
  }
}
