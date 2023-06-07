#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "general_settings.h"

int main(){
    // Initialize the board
    Board board;
    init_board(&board);

    // Print the initial board
//    print_board(&board);

    // Assign players
    Player t_player = 'T';
    Player b_player = 'B';

//    PiecesNum T_pieces = 12;
//    PiecesNum B_pieces = 12;

//    Piece* Pieces = (Piece*)malloc(sizeof(Piece)*INITIAL_PIECE_NUM);
//    checkMemoryAllocation(Pieces);
//    // top player pieces
//    initPieces(Pieces, t_player, DOWN, board);
//    print_all_pieces(Pieces, T_pieces);
//
//    // bottom player pieces
//    initPieces(Pieces, b_player, UP, board);
//    print_all_pieces(Pieces, B_pieces);

//    board[2][3] = EMPTY;
//    board[5][4] = EMPTY;
//    board[7][6] = EMPTY;
//    board[3][2] = TOP_PLAYER;
//    board[4][3] = BOTTOM_PLAYER;
    //board[4][1] = BOTTOM_PLAYER;

//    checkersPos *src = (checkersPos*) malloc(sizeof(checkersPos));
//    src->row = 'E';
//    src->col = '2';
//    SingleSourceMovesTree* tr = FindSingleSourceMoves(board, src);
//    printf("\nmoves of E2:\n");
//    if(tr == NULL)
//        return 0;

//    PrintSingleSourceMovesTree(tr->source);
//    MultipleSourceMovesList* x = FindAllPossiblePlayerMoves(board, t_player);
//    Turn(board,t_player, &B_pieces);
//    Turn(board, t_player, &T_pieces);

//    board[7][0] = TOP_PLAYER;
//    board[0][7] = BOTTOM_PLAYER;
//    bool k = checkIfLastRowCo(board, t_player);
//    bool j = checkIfLastRowCo(board, b_player);

   PlayGame(board, t_player);
    return 0;
}






