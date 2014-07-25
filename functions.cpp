#include <cstdlib>
#include <iostream>
#include "header.h"

using namespace std;

          /*Player functions*/

//determines who will go first

bool Player::goFirst()
{
   char answer;
   do
   { 
     cout << "Do you want to go first? Y/N" << endl;
     cin >> answer;
     if (answer == 'y' or answer == 'Y')
        return true;
     if (answer == 'n' or answer == 'N')
        return false;
   }while( answer != 'Y' && answer != 'y' && answer != 'n' && answer != 'N');
}


//get players move

void Player::get_person_move(char board[3][3], int &row, int &col )
{
     
     bool repeat = true;
     do
     {
        do
        {
         cout << "enter the cordinats as to where you want to go." << endl;
         cout << "Row 0-2 and column 0-2: " << endl;
         cout << "Row: " << endl;
         cin >>row;
         cout << "Column: " << endl;
         cin >> col;
         }while(row < -1 && row > 3 && col < -1 && col > 3);
     
     if(board[row][col] != '-')
         cout << "That place is already taken." << endl;
     else
         repeat = false;
         }while(repeat == true);       
}


//gets computers move by generating a random number for row and col
//and checking to see if that space is available.

void Player::get_computer_move(char board[3][3], int &row, int &col)
{   
     do
     {
         row = (rand() % 3);
         col = (rand() % 3);
     }while( board[row][col] != '-');   
}


//deconstructor
Player::~Player()
{
}




          /*GameBoard functions*/


//resets board to all - for a clean playing area.

void GameBoard::clear_board(char board[3][3])
{
     for(int i = 0; i < 3; i++)
     {
         for(int j = 0; j < 3; j++)
            board[i][j] = '-' ;
     }
}


//assigns X or O depending on whos turn and what row/col they picked

void GameBoard::update_board(char board[3][3], int row, int col, bool person_next)
{
    cout << endl;
        
    if(person_next == true)
        board[row][col]= 'X';
    else
        board[row][col] = 'O';
}
     
     
//displays current board

void GameBoard::display_board(char board[3][3])
{
     cout << endl;
     for(int i = 0; i<3; i++)
        {
           for(int j = 0; j< 3; j++)
           cout << board[i][j];
           cout << endl;
        }
}

     
     
//checks for a win by checking through each possible win state

bool GameBoard::check_for_win(char board[3][3], bool person_next)
{
    if (person_next == true)
    {
     if (board[0][0] == 'X' && board[0][1]== 'X' && board[0][2]== 'X')
        return true;
     if ( board[1][0]== 'X' && board[1][1]== 'X' && board[1][2]== 'X')
        return true;
     if ( board[2][0]== 'X' && board[2][1]== 'X' && board[2][2]== 'X')
        return true;
        
     if ( board[0][0]== 'X' && board[1][0]== 'X' && board[2][0]== 'X')
        return true;
     if ( board[1][1]== 'X' && board[1][1]== 'X' && board[2][1]== 'X')
        return true;
     if ( board[0][2]== 'X' && board[1][2]== 'X' && board[2][2]== 'X')
        return true;
        
     if ( board[0][0]== 'X' && board[1][2]== 'X' && board[2][2]== 'X')
        return true;
     if ( board[0][2]== 'X' && board[1][1]== 'X' && board[2][0]== 'X')
        return true;
     else
         return false;
     }
     
    if (person_next == false)
    {
     if (board[0][0] == 'O' && board[0][1]== 'O' && board[0][2]== 'O')
        return true;
     if ( board[1][0]== 'O' && board[1][1]== 'O' && board[1][2]== 'O')
        return true;
     if ( board[2][0]== 'O' && board[2][1]== 'O' && board[2][2]== 'O')
        return true;
        
     if ( board[0][0]== 'O' && board[1][0]== 'O' && board[2][0]== 'O')
        return true;
     if ( board[0][1]== 'O' && board[1][1]== 'O' && board[2][1]== 'O')
        return true;
     if ( board[0][2]== 'O' && board[1][2]== 'O' && board[2][2]== 'O')
        return true;
        
     if ( board[0][0]== 'O' && board[1][1]== 'O' && board[2][2]== 'O')
        return true;
     if ( board[0][2]== 'O' && board[1][1]== 'O' && board[2][0]== 'O')
        return true;
     else
         return false;
     }
}
 
 
 //checks for a draw by checking each place for being unoccupied
 
bool GameBoard::check_for_draw(char board[3][3] )
{
    if (board[0][0] != '-' && board[0][1] != '-' && board[0][2] != '-' && 
        board[1][0] != '-' && board[1][1] != '-' && board[1][2] != '-' && 
        board[2][0] != '-' && board[2][1] != '-' && board[2][2] != '-')
        return true;
    else
        return false;
}
  

//gets draw member data
        
bool GameBoard::get_draw()
{
    return draw;
}   
   
   
//assigns value to draw member data
   
void GameBoard::ass_draw(bool)
{
    bool d;
    draw = d;
}
   

//GameBoard deconstructor   
 
GameBoard::~GameBoard()
{
}
   
          
          
          
          
          
          
          
          
          
  
  
  
  
  
  
  
  
  
  
  
  
  
