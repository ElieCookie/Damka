#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "general_settings.h"

void initPieces(Piece *pieces, Player p, unsigned char direction, Board board) {
    int piece_count=0;
    int start_row, end_row;

    if(p == 'T'){
        start_row = 0;
        end_row = 2;
    }
    else{
        start_row = 5;
        end_row = 7;
    }

    for (int row = start_row; row <= end_row; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
             // initialize each Piece
            if(board[row][col] == p){
                pieces[piece_count].pos = (checkersPos*)malloc(sizeof(checkersPos));
                if(pieces[piece_count].pos == NULL)
                    exit(1);

                pieces[piece_count].pos->row = row + 'A';
                pieces[piece_count].pos->col = col + '1';

                pieces[piece_count].player = p;
                pieces[piece_count].moves.source = NULL;
                pieces[piece_count].direction = direction;
               
                piece_count++;
            }    
        }
    }
}


int SubTreeHeight (SingleSourceMovesTreeNode* root) {
    int heightLeft, heightRight;

    if(root == NULL) return -1;
    else {
        heightLeft = SubTreeHeight(root->next_move[0]);
        heightRight = SubTreeHeight(root->next_move[1]);
        return 1 + max(heightLeft, heightRight);
    }
}

void print_all_pieces(Piece *pieces, PiecesNum num){
    for (int i = 0; i < num; i++) {
        printf("Pos: %c%c\nPlayer: %c\n", pieces[i].pos->row, pieces[i].pos->col, pieces[i].player);
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
