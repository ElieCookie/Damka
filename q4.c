#include "general_settings.h"

// The function conducts a turn of a given player
void Turn(Board board, Player player) {
    MultipleSourceMovesList* playerPossibleMoves = FindAllPossiblePlayerMoves(board,player);
    int maximumCaptures = getMaximumCaptures(playerPossibleMoves);
    SingleSourceMovesListCell* cellToMove = findRelevantCell(playerPossibleMoves, player, maximumCaptures);
    deleteCapturedCells(board,cellToMove,player);
    moveCell(board,cellToMove,player);
    checkersPos* dest = findLastDestination(cellToMove);
    printf("%c%c->%c%c\n", cellToMove->position->row, cellToMove->position->col, dest->row, dest->col);
}

// The function finds the final destination of a player in a given SingleSourceMovesListCell, and returns the position
checkersPos* findLastDestination(SingleSourceMovesListCell* from){
    SingleSourceMovesListCell* next_move = from->next;
    while(next_move){
        if(next_move->next == NULL)
            return next_move->position;
        next_move = next_move->next;
    }
}

// The function deletes the captured pieces from the board according to the given SingleSourceMovesListCell
void deleteCapturedCells(Board board, SingleSourceMovesListCell* cellToMove, Player player) {
    if(cellToMove == NULL || cellToMove->next == NULL) return;

    if(cellToMove->next != NULL && cellToMove->next->captures == 0) return;

    if(player == TOP_PLAYER) {
        if(cellToMove->next->position->col - cellToMove->position->col  == 2)  // Moved right
            board[cellToMove->position->row - 'A' + 1][cellToMove->position->col - '0'] = EMPTY;
        else board[cellToMove->position->row - 'A' + 1][cellToMove->position->col - '2'] = EMPTY;
    }
    else {
        if(cellToMove->next->position->col - cellToMove->position->col  == 2)  // Moved right
            board[cellToMove->position->row - 'A' -1][cellToMove->position->col - '0'] = EMPTY;
        else board[cellToMove->position->row - 'A' -1][cellToMove->position->col - '2'] = EMPTY;
    }
    deleteCapturedCells(board, cellToMove->next, player);
}


//This function gets a Board, a SingleSourceMovesListCell pointer cellToMove and a Player
//The function will update the board, so it will move the head of cellToMove to his tail, and clear all values in the middle.
void moveCell(Board board, SingleSourceMovesListCell* cellToMove, Player player) {
    SingleSourceMovesListCell* temp = cellToMove;

    while(temp->next != NULL) {
        board[temp->position->row-'A'][temp->position->col-'1'] = EMPTY;
        board[temp->next->position->row-'A'][temp->next->position->col-'1'] = player;
        temp = temp->next;
    }
}


//This function gets a MultipleSourceMovesList pointer playerPossibleMoves
// and returns the maximum amount of captures in the MultipleSourceMovesListCells inside lst.
int getMaximumCaptures (MultipleSourceMovesList* playerPossibleMoves) {
    int res = 0;
    MultipleSourceMovesListCell* temp = playerPossibleMoves->head;
    while(temp != NULL) {
        if (temp->single_source_moves_list->tail->captures > res)
            res = temp->single_source_moves_list->tail->captures;
        temp = temp->next;
    }
    return res;
}



SingleSourceMovesListCell * findRelevantCell(MultipleSourceMovesList* lst ,Player player, int captures) {
    MultipleSourceMovesListCell * tempMultiple = lst->head;
    SingleSourceMovesList* tempSingle = tempMultiple->single_source_moves_list;
    SingleSourceMovesListCell* res = NULL;
    while (tempMultiple != NULL) {
        tempSingle = tempMultiple->single_source_moves_list;
        if(canMove(tempSingle->head)) {
            if (tempSingle->tail->captures == captures) {
                if (player == TOP_PLAYER) {
                    if (res == NULL)
                        res = tempSingle->head;
                    else if (tempSingle->head->position->row == res->position->row)
                        res = tempSingle->head->position->col > res->position->col ? tempSingle->head : res;
                    else
                        res = tempSingle->head->position->row > res->position->row ? tempSingle->head : res;
                } else {
                    if (res == NULL)
                        res = tempSingle->head;
                    else if (tempSingle->head->position->row == res->position->row)
                        res = tempSingle->head->position->col > res->position->col ? res : tempSingle->head;
                    else
                        res = tempSingle->head->position->row > res->position->row ? res : tempSingle->head;
                }
            }
        }
        tempMultiple = tempMultiple->next;
    }
    return res;
}


//This function gets a SingleSourceMovesListCell pointer lst which we assume it isn't null
// and returns TRUE if the next property is not NULL, and FALSE otherwise.
bool canMove(SingleSourceMovesListCell* lst) {
    return lst->next != NULL;
}