#ifndef GENERAL_SETTINGS_H
#define GENERAL_SETTINGS_H
#include "general.h"

    typedef struct _SingleSourceMovesTreeNode{
        Board board;
        checkersPos *pos;
        unsigned short total_captures_so_far;
        struct _SingleSourceMovesTreeNode *next_move[2]; // move targets
    } SingleSourceMovesTreeNode;

    typedef struct _SingleSourceMovesTree{
        SingleSourceMovesTreeNode *source;
    }SingleSourceMovesTree;

    typedef struct _Piece{
        checkersPos *pos; // position in the board
        Player player;
        SingleSourceMovesTree moves;
        unsigned char direction;
    }Piece;


    void initPieces(Piece *pieces, Player p, unsigned char direction, Board board);
    void print_all_pieces(Piece *pieces, PiecesNum num);
    SingleSourceMovesTree* FindSingleSourceMoves(Board board, checkersPos *src);
    void PrintSingleSourceMovesTree(SingleSourceMovesTreeNode* node);

#endif //GENERAL_SETTINGS_H
