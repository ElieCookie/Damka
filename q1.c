#include "general_settings.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    if(((p == 'T') && (board[row][col] == 'B')) || ((p == 'B') && (board[row][col] == 'T')))
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
                dest->row = src->row + 1;
                dest->col = src->col - 1;
                return dest;
            }
            return NULL;
        }
            // going right
        else{
            if(src->col < '8' && src->row < 'H'){
                dest->row = src->row + 1;
                dest->col = src->col + 1;
                return dest;
            }
            return NULL;
        }
    }

    // going up
    if(player == 'B'){

        // going left
        if(direction == 0){
            if(src->col > '1' && src->row > 'B'){
                dest->row = src->row - 1;
                dest->col = src->col - 1;
                return dest;
            }
            return NULL;
        }
            // going right
        else{
            if(src->col < '8' && src->row > 'B'){
                dest->row = src->row - 1;
                dest->col = src->col + 1;
                return dest;
            }
            return NULL;
        }
    }
}

bool canCapture(Board board, checkersPos *dest, int direction, Player player){
    /// if the checker after the other player's piece is blocked (doesn't matter by who) /
    /// it is the corner (can check using the type of player and indexes of the src)
    /// return false, else if the checker is empty we can capture.



}

///is Blocked By Corner from the left/right
bool isBlockedByCorner(Board board, checkersPos *src, int direction){
    int row = dest->row - 'A';
    int col = dest->col - '0';

    /// left , right
    if(((direction == 0) && (col == 1)) || ((direction == 1) && (col == 8))){
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

SingleSourceMovesTreeNode* FindSingleSourceMovesHelp(Board board, checkersPos *src,
                                                     unsigned short total_captures_so_far, Player player){

    if(isCorner(src))
        return NULL;

    checkersPos *dest_left = findDest(src, 0, player);
    checkersPos *dest_right = findDest(src, 1, player);



    if(isBlockedBySame(board,  dest_left, player)){

        if(isBlockedBySame(board,  dest_right, player) || isBlockedByCorner(board, src, 1, player))
            return NULL;

        else if(isBlockedByOther(board,  dest_right, player)){
            /// check only the other --> if it is possible to capture
        }
        else{
            /// add the empty option move to the moves
        }
    }


    if(isBlockedByOther(board,  dest_left, player)){

        if(isBlockedByCorner(board, src, 1, player) || isBlockedBySame(board,  dest_right, player)){
            /// check only the other --> if it is possible to capture
        }
        else if(isBlockedByOther(board,  dest_right, player)){
            /// need to check both sides --> if it is possible to capture
        }
        else{
            /// add the empty to the moves + check the other --> if it is possible to capture
        }
    }


    if(isBlockedByCorner(board, src, 0, player)){

        if(isBlockedBySame(board,  dest_right, player)){
            return NULL;
        }
        else if(isBlockedByOther(board,  dest_right, player)){
            /// check only the other --> if it is possible to capture
        }
        else{
            /// the checker is empty --> add to the moves
        }

    }

    if(isEmptyChecker(board, dest_left)){
        /// first add it to moves
        /// continue checking the others:
        if(isBlockedBySame(board,  dest_right, player) || isBlockedByCorner(board, src, 1, player)){
            /// do nothing
        }
        else if(isBlockedByOther(board,  dest_right, player)){
            /// check the other --> if it is possible to capture
        }
        else{
            /// the right checker is empty too --> add it to the moves also
        }
    }


}

//typedef struct _SingleSourceMovesTreeNode{
//    Board board;
//    checkersPos *pos;
//    unsigned short total_captures_so_far;
//    struct _SingleSourceMovesTreeNode *next_move[2]; // move targets
//} SingleSourceMovesTreeNode;
//
//typedef struct _SingleSourceMovesTree{
//    SingleSourceMovesTreeNode *source;
//}SingleSourceMovesTree;


SingleSourceMovesTree* FindSingleSourceMoves(Board board, checkersPos *src){
    int row = src->row - 'A';
    int col = src->col - '0';

    if(board[row][col] == WHITE || board[row][col] == EMPTY)
        return NULL;
    else{
        SingleSourceMovesTree* tree = (SingleSourceMovesTree*)malloc(sizeof(SingleSourceMovesTree));
        if(tree == NULL)
            exit(1);

        /// call the helper

    }
}