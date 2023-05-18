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

    typedef struct _multipleSourceMovesListCell{
       SingleSourceMovesList *single_source_moves_list;
       struct _multipleSourceMovesListCell *next;
    } MultipleSourceMovesListCell;

    typedef struct _multipleSourceMovesList{
        struct _multipleSourceMovesListCell *head;
        struct _multipleSourceMovesListCell *tail;
    } MultipleSourceMovesList;
    
    

    void initPieces(Piece *pieces, Player p, unsigned char direction, Board board);
    void print_all_pieces(Piece *pieces, PiecesNum num);
    SingleSourceMovesTree* FindSingleSourceMoves(Board board, checkersPos *src);
    void PrintSingleSourceMovesTree(SingleSourceMovesTreeNode* node);

    SingleSourceMovesList * FindSingleSourceOptimalMove(SingleSourceMovesTree* moves_tree);
    void FindSingleSourceOptimalMoveHelper(SingleSourceMovesTreeNode* moves_cell, char player, SingleSourceMovesList* res);
    int SubTreeHeight (SingleSourceMovesTreeNode* root);
    SingleSourceMovesListCell* createMovesListCell(checkersPos* position, unsigned short captures);
    MultipleSourceMovesListCell* createMultipleSourceMovesListCell(SingleSourceMovesList* lst);
    bool isEmptyList(SingleSourceMovesList* lst);
    bool isEmptyMultipleList(MultipleSourceMovesList* lst);
    void addMovesListCellToStartList(SingleSourceMovesList* list, SingleSourceMovesListCell* cell);
    void addMovesListCellToEndOfList(SingleSourceMovesList* list, SingleSourceMovesListCell* cell);
    void addMultipleSourceMovesListCellToStartList(MultipleSourceMovesList* list, MultipleSourceMovesListCell* cell);
    MultipleSourceMovesList* FindAllPossiblePlayerMoves(Board board, Player player);
    void Turn(Board board, Player player);
    int getMaximumCaptures (MultipleSourceMovesList* playerPossibleMoves);
SingleSourceMovesListCell* findRelevantCell(MultipleSourceMovesList* lst ,Player player, int captures);
#define makeEmptyList(list) { \
    (*list).head = (*list).tail = NULL;\
}
#endif //GENERAL_SETTINGS_H
