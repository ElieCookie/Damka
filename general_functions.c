#include "functions.h"


//This function gets a node of a SingleSourceMovesTreeNode and returns the height from this node below.
int SubTreeHeight (SingleSourceMovesTreeNode* root) {
    int heightLeft, heightRight;

    if(root == NULL) return -1;
    else {
        heightLeft = SubTreeHeight(root->next_move[0]) + 1 ;
        heightRight = SubTreeHeight(root->next_move[1]) + 1;
        return (max(heightLeft, heightRight) + 1);
    }
}


//This function gets a checkersPos pointer position and unsigned short captures and returns a SingleSourceMovesListCell pointer based on the given data.
SingleSourceMovesListCell* createMovesListCell(checkersPos* position, unsigned short captures) {
    SingleSourceMovesListCell* cell = (SingleSourceMovesListCell*)malloc(sizeof(SingleSourceMovesListCell));
    checkMemoryAllocation(cell);
    cell->position = (checkersPos*)malloc(sizeof(checkersPos));
    cell->position->row = position->row;
    cell->position->col = position->col;
    cell->captures = captures;
    cell->next = NULL;
    return cell;
}


//This function gets a SingleSourceMovesList list and a SingleSourceMovesListCell cell and adds cell to the end of list.
void addMovesListCellToEndOfList(SingleSourceMovesList* list, SingleSourceMovesListCell* cell) {
    if (list->head == NULL) {
        list->head = cell;
        list->tail = cell;
    } else {
        list->tail->next = cell;
        list->tail = cell;
    }
}


//This function checks if the MultipleSourceMovesList lst is empty.
bool isEmptyMultipleList(MultipleSourceMovesList * lst) {
    return lst->tail == NULL;
}


//This function gets a SingleSourceMovesList lst and creates a new MultipleSourceMovesListCell with this lst as a single_source_moves_list and returns cell.
MultipleSourceMovesListCell* createMultipleSourceMovesListCell(SingleSourceMovesList* lst){
    MultipleSourceMovesListCell* cell = (MultipleSourceMovesListCell*)malloc(sizeof(MultipleSourceMovesListCell));
    cell->single_source_moves_list = lst;
    cell->next = NULL;
    return cell;
}


//This function makes the MultipleSourceMovesList lst an empty list.
void makeEmptyMultipleSourceMovesList(MultipleSourceMovesList* lst){
    lst->head = lst->tail = NULL;
}


//This function free all elements in the SingleSourceMovesTree tr.
void freeTree(SingleSourceMovesTree* tr){
    freeTreeHelper(tr->source);
    free(tr);
}


//This function is a helper function to freeTree, it frees all elements in the SingleSourceMovesTree tr.
void freeTreeHelper(SingleSourceMovesTreeNode * root){
    if (root == NULL)
        return;
    else
    {
        freeTreeHelper(root->next_move[0]);
        freeTreeHelper(root->next_move[1]);
        free(root);
    }
}


//This function frees all elements inside the MultipleSourceMovesList list
void freeMultipleSourceMovesList(MultipleSourceMovesList* list){
    MultipleSourceMovesListCell* temp = list->head;
    MultipleSourceMovesListCell* next = list->head->next;
    while(next != NULL){
        freeSingleSourceMovesList(temp->single_source_moves_list);
        free(temp);
        temp = next;
        next = next->next;
    }
    free(temp);
    free(next);
}


//This function frees all elements inside the SingleSourceMovesList list
void freeSingleSourceMovesList(SingleSourceMovesList * list){
    SingleSourceMovesListCell * temp = list->head;
    SingleSourceMovesListCell * next = list->head->next;
    while(next != NULL){
        free(temp->position);
        free(temp);
        temp = next;
        next = next->next;
    }
    free(temp);
    free(next);

}
