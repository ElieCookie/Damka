//
// Created by Lidor Levi on 17/05/2023.
//
#include "general_settings.h"

//TODO :
// 1. Check for the _multipleSourceMovesList
// 2. Implement new function that gets the player and his _multipleSourceMovesList and returns the best move
//    Based on the requirements mentioned in the question,
// 3. Implement new function that gets the result of the function above, and a player, and will return a list of all enemies
//    Soliders that need to be deleted, and their amount.
//
//
//
//


void Turn(Board board, Player player) {
    MultipleSourceMovesList* playerPossibleMoves = FindAllPossiblePlayerMoves(board,player);
    int maximumCaptures = getMaximumCaptures(playerPossibleMoves);
    SingleSourceMovesListCell* cellToMove = findRelevantCell(playerPossibleMoves, player, maximumCaptures);
    deleteCapturedCells(board,cellToMove,player);
    moveCell(board,cellToMove,player);
    checkersPos* dest = findLastDestination(cellToMove);
    printf("%c%c->%c%c\n", cellToMove->position->row, cellToMove->position->col, dest->row, dest->col);
}

checkersPos* findLastDestination(SingleSourceMovesListCell* from){
    SingleSourceMovesListCell* next_move = from->next;
    while(next_move){
        if(next_move->next == NULL)
            return next_move->position;
        next_move = next_move->next;
    }
}

void deleteCapturedCells(Board board, SingleSourceMovesListCell* cellToMove, Player player) {
    // added here cellToMove->next == NULL
    if(cellToMove == NULL || cellToMove->next == NULL) return;

    // added here cellToMove->next != NULL
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


void moveCell(Board board, SingleSourceMovesListCell* cellToMove, Player player) {
    SingleSourceMovesListCell* temp = cellToMove;

    while(temp->next != NULL) {
        board[temp->position->row-'A'][temp->position->col-'1'] = EMPTY;
        board[temp->next->position->row-'A'][temp->next->position->col-'1'] = player;
        temp = temp->next;
    }
}


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
    SingleSourceMovesList* tempSingle = tempMultiple->single_source_moves_list;;
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

bool canMove(SingleSourceMovesListCell* lst) {
    return lst->next != NULL;
}