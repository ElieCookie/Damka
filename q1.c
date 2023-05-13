#include "general_settings.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LEFT 0
#define RIGHT 1

bool isCorner(checkersPos *src){
    int row = src->row - 'A';
    int col = src->col - '0' - 1;

    if((row == 0 && col == 0) || (row == 0 && col == 7) || (row == 7 && col == 0) || (row == 7 && col == 7)){
        return true;
    }
    return false;
}

bool isBlockedBySame(Board board, checkersPos *dest, Player player){
    int row = dest->row - 'A';
    int col = dest->col - '0' - 1;

    if(board[row][col] == player)
        return true;
    return false;
}

bool isBlockedByOther(Board board, checkersPos *dest, Player player){
    int row = dest->row - 'A';
    int col = dest->col - '0' - 1;

    if(((player == 'T') && (board[row][col] == 'B')) || ((player == 'B') && (board[row][col] == 'T')))
        return true;
    return false;
}

checkersPos* findDest(checkersPos *src, int direction, Player player){
    checkersPos *dest = (checkersPos*) malloc(sizeof(checkersPos));
    if(dest == NULL)
        exit(1);

    // going down
    if(player == 'T'){

        // going left
        if(direction == 0){
            if(src->col > '1' && src->row < 'H'){
                dest->row = (src->row)++;
                dest->col = (src->col)--;
                return dest;
            }
            return NULL;
        }
        // going right
        else{
            if(src->col < '8' && src->row < 'H'){
                dest->row = (src->row)++;
                dest->col = (src->col)--;
                return dest;
            }
            return NULL;
        }
    }

    // going up
    else if(player == 'B'){

        // going left
        if(direction == 0){
            if(src->col > '1' && src->row > 'B'){
                dest->row = (src->row)--;
                dest->col = (src->col)--;
                return dest;
            }
            return NULL;
        }
            // going right
        else{
            if(src->col < '8' && src->row > 'B'){
                dest->row = (src->row)--;
                dest->col = (src->col)++;
                return dest;
            }
            return NULL;
        }
    }
    else
        return NULL;
}


///is Blocked By Corner from the left/right
bool isBlockedByCorner(checkersPos *src, int direction){
    int col = src->col - '0';

        /// left , right
        if(((direction == 0) && (col == 1)) || ((direction == 1) && (col == 8))){
            return true;
        }
        else
            return false;
}

bool isBlockedByRow(checkersPos *src, Player player){
    int row = src->row - 'A';

    /// down , up
    if(((player == 'T') && (row == 8)) || ((player == 'B') && (row == 1))){
        return true;
    }
    else
        return false;
}

bool isEmptyChecker(Board board, checkersPos *dest){
    int row = dest->row - 'A';
    int col = dest->col - '0' - 1;

    if(board[row][col] == EMPTY || board[row][col] == GRAY)
        return true;
    return false;
}

bool canCapture(Board board, checkersPos *dest, int direction, Player player){
    /// if the checker after the other player's piece is blocked (doesn't matter by who) /
    /// it is the corner (can check using the type of player and indexes of the src)
    /// return false, else if the checker is empty we can capture.

    checkersPos *after_capture = findDest(dest, direction, player);

    // check if the dest is in a corner or blocked by another piece
    if(isCorner(dest) || isBlockedByCorner(dest, direction)
        || isBlockedByRow(dest, player)
        || isBlockedBySame(board,  after_capture, player)
        || isBlockedByOther(board,  after_capture, player))
        return false;
    else
        return true;
}

void copyBoard(Board *dest, Board src){
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if(src[row][col] == EMPTY)
                (*dest)[row][col] = EMPTY;
            else if (src[row][col] == GRAY)
                (*dest)[row][col] = GRAY;
            else if (src[row][col] == TOP_PLAYER)
                (*dest)[row][col] = TOP_PLAYER;
            else
                (*dest)[row][col] = BOTTOM_PLAYER;
        }
    }
}

void addNextMove(Board board, checkersPos *dest, checkersPos *src,
                 bool is_capture, int direction, Player player,
                 SingleSourceMovesTreeNode* next_move, bool added_next_move){

    next_move->pos = src;

    /// TO DO - update the board after each play
    copyBoard(&(next_move->board), board);

    if(direction == LEFT){
        if(!added_next_move)
            next_move->next_move[RIGHT] = NULL;
        if(is_capture) {
            next_move->next_move[LEFT]->pos = findDest(dest, direction, player);
            (next_move->total_captures_so_far)++;
        }
        else{
            next_move->next_move[LEFT]->pos = dest;
        }
    }
    // right
    else{
        if(!added_next_move)
            next_move->next_move[LEFT] = NULL;
        if(is_capture) {
            next_move->next_move[RIGHT]->pos = findDest(dest, direction, player);
            (next_move->total_captures_so_far)++;
        }
        else{
            next_move->next_move[RIGHT]->pos = dest;
        }
    }

}

SingleSourceMovesTreeNode* FindSingleSourceMovesHelp(Board board, checkersPos *src,
                                                     unsigned short *total_captures_so_far, Player player){
    bool added;
    if(isCorner(src) || isBlockedByRow(src, player))
        return NULL;

    checkersPos *dest_left = findDest(src, LEFT, player);
    checkersPos *dest_right = findDest(src, RIGHT, player);

    if(isBlockedBySame(board,  dest_left, player)){

        if(isBlockedBySame(board,  dest_right, player) || isBlockedByCorner(src, RIGHT))
            return NULL;

        else if(isBlockedByOther(board,  dest_right, player)){
            /// check only the other --> if it is possible to capture
            if(canCapture(board, dest_right, RIGHT, player)){
                /// add move
                SingleSourceMovesTreeNode* new_move = (SingleSourceMovesTreeNode*) malloc(sizeof(SingleSourceMovesTreeNode));
                if(new_move == NULL)
                    exit(1);

                addNextMove(board, dest_right, src, true, RIGHT, player, new_move, false);
                (*total_captures_so_far)++;
                return FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
            }
            return NULL;
        }
        else{
            /// add the empty option move to the moves
            SingleSourceMovesTreeNode* new_move = (SingleSourceMovesTreeNode*) malloc(sizeof(SingleSourceMovesTreeNode));
            if(new_move == NULL)
                exit(1);

            addNextMove(board, dest_right, src, false, RIGHT, player, new_move, false);
            return FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
        }
    }


    if(isBlockedByOther(board,  dest_left, player)){
        SingleSourceMovesTreeNode* new_move;

        if(canCapture(board, dest_left, LEFT, player)){
            /// add move
            new_move = (SingleSourceMovesTreeNode*) malloc(sizeof(SingleSourceMovesTreeNode));
            if(new_move == NULL)
                exit(1);

            addNextMove(board, dest_left, src, true, LEFT, player, new_move, false);
            (*total_captures_so_far)++;
        }
        else{
            new_move = NULL;
        }

        if(isBlockedByCorner(src, RIGHT) || isBlockedBySame(board,  dest_right, player)){
            return FindSingleSourceMovesHelp(board, dest_left, total_captures_so_far, player);
        }
        else if(isBlockedByOther(board,  dest_right, player)){
            /// need to check both sides --> if it is possible to capture
            if(canCapture(board, dest_right, RIGHT, player)){
                if(new_move == NULL) {
                    added = false;
                    addNextMove(board, dest_right, src, true, RIGHT, player, new_move, added);
                    (*total_captures_so_far)++;

                    return FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
                }
                else
                    added = true;

                /// add move also to new_move
                addNextMove(board, dest_right, src, true, RIGHT, player, new_move, added);
                (*total_captures_so_far)++;

                 FindSingleSourceMovesHelp(board, dest_left, total_captures_so_far, player);
                 FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
            }
            else{
                if(new_move == NULL)
                    return NULL;

                return FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
            }
        }
        else{
            /// add the empty to the moves and return it
            if(new_move == NULL) {
                added = false;

                addNextMove(board, dest_right, src, false, RIGHT, player, new_move, added);
                return FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
            }
            else
                added = true;

            addNextMove(board, dest_right, src, false, RIGHT, player, new_move, added);
            FindSingleSourceMovesHelp(board, dest_left, total_captures_so_far, player);
            FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
        }
    }


    if(isBlockedByCorner(src, LEFT)){

        if(isBlockedBySame(board,  dest_right, player)){
            return NULL;
        }
        else if(isBlockedByOther(board,  dest_right, player)){
            /// check only the other --> if it is possible to capture
            if(canCapture(board, dest_right, RIGHT, player)){
                /// add move also to new_move
                SingleSourceMovesTreeNode* new_move = (SingleSourceMovesTreeNode*) malloc(sizeof(SingleSourceMovesTreeNode));
                if(new_move == NULL)
                    exit(1);

                addNextMove(board, dest_right, src, true, RIGHT, player, new_move, false);
                (*total_captures_so_far)++;

                return FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
            }
            else{
                return NULL;
            }
        }
        else{
            /// the checker is empty --> add to the moves
            SingleSourceMovesTreeNode* new_move = (SingleSourceMovesTreeNode*) malloc(sizeof(SingleSourceMovesTreeNode));
            if(new_move == NULL)
                exit(1);

            addNextMove(board, dest_right, src, false, RIGHT, player, new_move, false);
            return FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
        }

    }

    if(isEmptyChecker(board, dest_left)){
        /// first add it to moves
        SingleSourceMovesTreeNode* new_move;
        new_move = (SingleSourceMovesTreeNode*) malloc(sizeof(SingleSourceMovesTreeNode));
        if(new_move == NULL)
            exit(1);

        addNextMove(board, dest_left, src, false, LEFT, player, new_move, false);

        /// continue checking the others:
        if(isBlockedBySame(board,  dest_right, player) || isBlockedByCorner(src, RIGHT)){
            return FindSingleSourceMovesHelp(board, dest_left, total_captures_so_far, player);
        }
        else if(isBlockedByOther(board,  dest_right, player)){
            /// check the other --> if it is possible to capture
            if(canCapture(board, dest_right, RIGHT, player)){
                /// add move also to new_move
                addNextMove(board, dest_right, src, true, RIGHT, player, new_move, true);
                (*total_captures_so_far)++;
                return FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
            }
            else{
                return FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
            }
        }
        else{
            /// the right checker is empty too --> add it to the moves also
            addNextMove(board, dest_right, src, false, RIGHT, player, new_move, true);
            return FindSingleSourceMovesHelp(board, dest_right, total_captures_so_far, player);
        }
    }
    return NULL;
}

SingleSourceMovesTree* FindSingleSourceMoves(Board board, checkersPos *src){
    int row = src->row - 'A';
    int col = src->col - '0' - 1;

    if(board[row][col] == WHITE || board[row][col] == EMPTY)
        return NULL;
    else{
        SingleSourceMovesTree* tree = (SingleSourceMovesTree*)malloc(sizeof(SingleSourceMovesTree));
        if(tree == NULL)
            exit(1);

        unsigned short total_captures_so_far = 0;
        tree->source = FindSingleSourceMovesHelp(board, src, &total_captures_so_far, board[row][col]);
        return tree;
    }
}

void PrintSingleSourceMovesTree(SingleSourceMovesTreeNode* node){
    if(node == NULL)
        return;

    printf("move: %c%c\n", node->pos->row, node->pos->col);
    PrintSingleSourceMovesTree(node->next_move[LEFT]);
    PrintSingleSourceMovesTree(node->next_move[RIGHT]);
}
