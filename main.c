#include "general.h"
#include "functions.h"

int main(){
    // Initialize the board
    Board board;
    init_board(&board);

    // Assign players
    Player starting_player;

    printf("Enter the player that will start the game. T for top player, B for bottom player: \n");
    scanf("%c", &starting_player);

   PlayGame(board, starting_player);
   return 0;
}






