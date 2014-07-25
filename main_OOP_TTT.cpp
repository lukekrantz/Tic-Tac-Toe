#include <cstdlib>
#include <iostream>
#include "header.h"


using namespace std;

   int row, col;   // ints from 0 to 2 for move
   char board[3][3];
   bool person_next;  //true if person goes first
    
    int main(int argc, char *argv[])
{
    
    Player person;
    Player computer;
    GameBoard Board;
    
    // get inputs
     person_next=person.goFirst();
    
    //set up game
    srand(time(0));
    Board.clear_board(board);
    
    // game loop
    do
    {
            Board.display_board(board);
            
            if (person_next)
               person.get_person_move(board, row, col);
            else
                computer.get_computer_move(board, row, col);
                
            Board.update_board(board, row, col, person_next);
            
            if(Board.check_for_win(board, person_next) )
                break;
                
            if(Board.check_for_draw(board))
                {
                     Board.ass_draw(true);
                     break;
                }
            person_next = !person_next;
     }while(true);
     
     // announce winner
     
     if ( Board.get_draw() )
       cout << "The game was a draw\n";
    else
        if ( person_next )
            cout << "You won\n";
        else
            cout << "The computer won\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
