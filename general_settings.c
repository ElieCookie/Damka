#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "general_settings.h"


int SubTreeHeight (SingleSourceMovesTreeNode* root) {
    int heightLeft, heightRight;

    if(root == NULL) return -1;
    else {
        heightLeft = SubTreeHeight(root->next_move[0]) + 1 ;
        heightRight = SubTreeHeight(root->next_move[1]) + 1;
        return (max(heightLeft, heightRight) + 1);
    }
}


SingleSourceMovesListCell* createMovesListCell(checkersPos* position, unsigned short captures) {
    SingleSourceMovesListCell* cell = (SingleSourceMovesListCell*)malloc(sizeof(SingleSourceMovesListCell));
    cell->position = (checkersPos*)malloc(sizeof(checkersPos));
    cell->position->row = position->row;
    cell->position->col = position->col;
    cell->captures = captures;
    cell->next = NULL;
    return cell;
}

void addMovesListCellToEndOfList(SingleSourceMovesList* list, SingleSourceMovesListCell* cell) {
    if (list->head == NULL) {
        list->head = cell;
        list->tail = cell;
    } else {
        list->tail->next = cell;
        list->tail = cell;
    }
}

void addMovesListCellToStartList(SingleSourceMovesList* list, SingleSourceMovesListCell* cell) {
    if(isEmptyList(list)) {
        cell->next = NULL;
        list->head = list->tail = cell;
    }
    else {
        cell->next = list->head;
        list->head = cell;
    }
}

bool isEmptyMultipleList(MultipleSourceMovesList * lst) {
    return lst->tail == NULL;
}


bool isEmptyList(SingleSourceMovesList* lst) {
    return lst->tail == NULL;
}

MultipleSourceMovesListCell* createMultipleSourceMovesListCell(SingleSourceMovesList* lst){
    MultipleSourceMovesListCell* cell = (MultipleSourceMovesListCell*)malloc(sizeof(MultipleSourceMovesListCell));
    cell->single_source_moves_list = lst;
    cell->next = NULL;
    return cell;
}
