#include "general.h"
#include "functions.h"

int main(){
    // Initialize the board
    Board board;
    init_board(&board);

    // Assign players
    Player starting_player;

    do {
        printf("Enter the player that will start the game. T for top player, B for bottom player: \n");
        scanf(" %c", &starting_player);

        if (starting_player != 'T' && starting_player != 'B') {
            printf("Invalid input. Please enter a valid player (T or B).\n");
        }
    } while (starting_player != 'T' && starting_player != 'B');

   PlayGame(board, starting_player);
   return 0;
}






