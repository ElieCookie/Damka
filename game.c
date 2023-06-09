#include "general.h"
#include "general_settings.h"

int main(){
    // Initialize the board
    Board board;
    init_board(&board);

    // Assign players
    Player t_player = 'T';
    Player b_player = 'B';
    Player starting_player;

    printf("Enter the player that will start the game: \n");
    scanf("%c", &starting_player);

   PlayGame(board, starting_player);
    return 0;
}






