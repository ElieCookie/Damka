#include "general_settings.h"


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

MultipleSourceMovesList* FindAllPossiblePlayerMoves(Board board, Player player) {
    MultipleSourceMovesList res;
    MultipleSourceMovesListCell* temp = malloc(sizeof (MultipleSourceMovesListCell));
    makeEmptyList(&res);
    for(int row = 0; row < BOARD_SIZE; row++) {
        for(int col = 0; col< BOARD_SIZE; col++) {
            if(board[row][col] == player) {
                checkersPos *src = (checkersPos*) malloc(sizeof(checkersPos));
                src->row = row + 'A';
                src->col = col + '1';
                SingleSourceMovesTree* tr = FindSingleSourceMoves(board, src);
                temp->next = NULL;
                temp->single_source_moves_list = FindSingleSourceOptimalMove(tr);
                addMultipleSourceMovesListCellToStartList(&res, temp);
            }
        }
    }
    return &res;
}