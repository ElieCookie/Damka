#ifndef GENERAL_SETTINGS_H
#define GENERAL_SETTINGS_H
#include "general.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define max(a, b) a > b ? a : b
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

    typedef struct _SingleSourceMovesListCell {
        checkersPos* position;
        unsigned short captures;
        struct _SingleSourceMovesListCell* next;
    } SingleSourceMovesListCell;

    typedef struct _SingleSourceMovesList {
        SingleSourceMovesListCell* head;
        SingleSourceMovesListCell* tail;
    } SingleSourceMovesList;

    void initPieces(Piece *pieces, Player p, unsigned char direction, Board board);
    void print_all_pieces(Piece *pieces, PiecesNum num);
    SingleSourceMovesTree* FindSingleSourceMoves(Board board, checkersPos *src);
    SingleSourceMovesList * FindSingleSourceOptimalMove(SingleSourceMovesTree* moves_tree);
    void FindSingleSourceOptimalMoveHelper(SingleSourceMovesTreeNode* moves_cell, char player, SingleSourceMovesList* res);
    int SubTreeHeight (SingleSourceMovesTreeNode* root);
    SingleSourceMovesListCell* createMovesListCell(checkersPos* position, unsigned short captures);
    bool isEmptyList(SingleSourceMovesList* lst);
    void addMovesListCellToStartList(SingleSourceMovesList* list, SingleSourceMovesListCell* cell);
    void addMovesListCellToEndOfList(SingleSourceMovesList* list, SingleSourceMovesListCell* cell);
#define makeEmptyList(list) { \
    (*list).head = (*list).tail = NULL;\
}
#endif //GENERAL_SETTINGS_H
