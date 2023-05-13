#include "general_settings.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isCorner(Board board, checkersPos *src){

}

bool isBlockedBySame(Board board, checkersPos *dest, Player player){

}

bool isBlockedByOther(Board board, checkersPos *dest, Player player){

}

checkersPos* findDest(Board board, checkersPos *src, int direction, Player player){

}

bool canCapture(Board board, checkersPos *src, int direction, Player player){
    /// if the checker after the other player's piece is blocked (doesn't matter by who) /
    /// it is the corner (can check using the type of player and indexes of the src)
    /// return false, else if the checker is empty we can capture.
}

bool isBlockedByCorner(Board board, checkersPos *src, int direction, Player player){

}

bool isEmptyChecker(Board board, checkersPos *src, int direction, Player player){

}

SingleSourceMovesTreeNode* FindSingleSourceMovesHelp(Board board, checkersPos *src,
                                                     unsigned short total_captures_so_far, Player player){

    if(isCorner(board, src))
        return NULL;

    checkersPos *dest_left = findDest(board, src, 0, player);
    checkersPos *dest_right = findDest(board, src, 1, player);

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

    if(isEmptyChecker(board, src, 0, player)){
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
