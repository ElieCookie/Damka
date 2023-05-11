#include <stdio.h>
#include <stdlib.h>
#include "general_settings.h"

int main(){
    // Initialize the board
    Board board;
    init_board(&board);

    // Print the initial board
    print_board(&board);

    Piece* Pieces = (Piece*)malloc(sizeof(Piece)*INITIAL_PIECE_NUM);
    if(Pieces == NULL)
        exit(1);

    // top player pieces 
    initPieces(Pieces, t_player, DOWN, board);
    print_all_pieces(Pieces, T_pieces);

    // bottom player pieces 
    initPieces(Pieces, b_player, UP, board);
    print_all_pieces(Pieces, B_pieces);

    return 0;
}






