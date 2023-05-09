#include <stdio.h>
#include <stdlib.h>
#include "ex1/general_settings.h"

void main(){
    // Initialize the board
    Board board;
    init_board(&board);

    Piece* Pieces = (Piece*)malloc(sizeof(Piece)*INITIAL_PIECE_NUM);
    if(Pieces == NULL)
        exit(1);


    // Print the initial board
    print_board(&board);
}






