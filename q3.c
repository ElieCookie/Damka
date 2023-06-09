#include "general_settings.h"

//This function gets a MultipleSourceMovesList pointer list and a MultipleSourceMovesListCell pointer cell
//The function adds cell to the beginning of list.
void addMultipleSourceMovesListCellToStartList(MultipleSourceMovesList* list, MultipleSourceMovesListCell* cell) {
    if(isEmptyMultipleList(list)) {
        cell->next = NULL;
        list->head = list->tail = cell;
    }
    else {
        cell->next = list->head;
        list->head = cell;
    }
}


//This function gets a Board and a player, the function go over all checkers in the board, if the checkers is a checker of player
//Then it will find his SingleSourceMovesTree and assign it into a new SingleSourceMovesTree which it will return.
MultipleSourceMovesList* FindAllPossiblePlayerMoves(Board board, Player player) {
    MultipleSourceMovesList* res = (MultipleSourceMovesList*) malloc(sizeof (MultipleSourceMovesList));
    checkMemoryAllocation(res);
    makeEmptyMultipleSourceMovesList(res);
    checkersPos src;
    for(int row = 0; row < BOARD_SIZE; row++) {
        for(int col = 0; col< BOARD_SIZE; col++) {
            if(board[row][col] == player) {
                src.row = row + 'A';
                src.col = col + '1';
                SingleSourceMovesTree* tr = FindSingleSourceMoves(board, &src);
                addMultipleSourceMovesListCellToStartList(res, createMultipleSourceMovesListCell(FindSingleSourceOptimalMove(tr)));
            }
        }
    }
    return res;
}