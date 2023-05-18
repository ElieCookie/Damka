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
    int x = 0;
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
    SingleSourceMovesListCell* res = tempSingle->head;
    while (tempMultiple != NULL) {
        tempSingle = tempMultiple->single_source_moves_list;
        if(tempSingle->tail->captures == captures) {
            if (player == TOP_PLAYER) {
                if(tempSingle->head->position->row > res->position->row)
                    res = tempSingle->head;
                else if (tempSingle->head->position->row == res->position->row)
                    if(tempSingle->head->position->col > res->position->col)
                        res = tempSingle->head;
            }
            else {
                if(tempSingle->head->position->row < res->position->row)
                    res = tempSingle->head;
                else if (tempSingle->head->position->row == res->position->row)
                    if(tempSingle->head->position->col < res->position->col)
                        res = tempSingle->head;

            }
        }
        tempMultiple = tempMultiple->next;
    }
    return res;
}