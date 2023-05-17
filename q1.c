#include "general_settings.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LEFT 0
#define RIGHT 1

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
    checkMemoryAllocation(dest);

    // going down
    if(player == 'T'){

        // going left
        if(direction == 0){
                dest->row = (src->row) + 1;
                dest->col = (src->col) - 1;
                return dest;
        }
            // going right
        else{
                dest->row = (src->row) + 1;
                dest->col = (src->col) + 1;
                return dest;
        }
    }

        // going up
    else if(player == 'B'){

        // going left
        if(direction == 0){
                dest->row = (src->row) - 1;
                dest->col = (src->col) - 1;
                return dest;
        }
            // going right
        else{
                dest->row = (src->row) - 1;
                dest->col = (src->col) + 1;
                return dest;
        }
    }
    else
        return NULL;
}

bool isEmptyChecker(Board board, checkersPos *dest){
    int row = dest->row - 'A';
    int col = dest->col - '0' - 1;

    if(board[row][col] == EMPTY)
        return true;
    return false;
}

bool noPlayer(Board board, checkersPos *src){
    int row = src->row - 'A';
    int col = src->col - '0' - 1;

    if(board[row][col] == EMPTY || board[row][col] == WHITE)
        return true;
    else
        return false;
}

bool isCorruptedPos(checkersPos *src){
    if(src->row > 'H' || src->row < 'A' || src->col > '8' || src->col < '1')
        return true;
    return false;
}

SingleSourceMovesTreeNode* FindSingleSourceMove(Board board, checkersPos *src, Player player,
                                                unsigned short total_captures_so_far){
    if(noPlayer(board, src) || isCorruptedPos(src))
        return NULL;
    SingleSourceMovesTreeNode* left = NULL;
    SingleSourceMovesTreeNode* right = NULL;
    checkersPos* dest_left = findDest(src, LEFT, player);
    checkersPos* dest_right = findDest(src, RIGHT, player);

    /// left side
    if(isBlockedBySame(board, dest_left, player))
        left = NULL;
    else if(isBlockedByOther(board, dest_left, player))
    {
        checkersPos* cap_dest = findDest(dest_left, LEFT,player);
        if(isEmptyChecker(board, cap_dest)) {
            board[src->row - 'A'][src->col - '0' - 1] = EMPTY;
            board[cap_dest->row - 'A'][cap_dest->col - '0' - 1] = player;
            board[dest_left->row - 'A'][dest_left->col - '0' - 1] = EMPTY;
            left = FindSingleSourceMove(board, cap_dest, player, total_captures_so_far + 1);
        }
        else
            left = NULL;
    }
    else if(isEmptyChecker(board, dest_left)) {
        board[src->row - 'A'][src->col - '0' - 1] = EMPTY;
        board[dest_left->row - 'A'][dest_left->col - '0' - 1] = player;

        left = (SingleSourceMovesTreeNode*) malloc(sizeof(SingleSourceMovesTreeNode));
        left->pos = dest_left;
        left->total_captures_so_far = total_captures_so_far;
    }
    /// right side
    if(isBlockedBySame(board, dest_right, player))
        right = NULL;
    else if(isBlockedByOther(board, dest_right, player))
    {
        checkersPos* cap_dest = findDest(dest_right, RIGHT, player);
        if(isEmptyChecker(board, cap_dest)) {
            board[cap_dest->row - 'A'][cap_dest->col - '0' - 1] = player;
            board[src->row - 'A'][src->col - '0' - 1] = EMPTY;
            board[dest_right->row - 'A'][dest_right->col - '0' - 1] = EMPTY;

            right = FindSingleSourceMove(board, cap_dest, player, total_captures_so_far + 1);
        }
        else
            right = NULL;
    }
    else if(isEmptyChecker(board, dest_right)) {
        board[src->row - 'A'][src->col - '0' - 1] = EMPTY;
        board[dest_right->row - 'A'][dest_right->col - '0' - 1] = player;

        right = (SingleSourceMovesTreeNode*) malloc(sizeof(SingleSourceMovesTreeNode));
        right->pos = dest_right;
        right->total_captures_so_far = total_captures_so_far;
    }
    SingleSourceMovesTreeNode* root = (SingleSourceMovesTreeNode*) malloc(sizeof(SingleSourceMovesTreeNode));
    checkMemoryAllocation(root);

    root->pos = src;
    root->next_move[LEFT] = left;
    root->next_move[RIGHT] = right;
    root->total_captures_so_far = total_captures_so_far;
    return root;
}

SingleSourceMovesTree* FindSingleSourceMoves(Board board, checkersPos *src){
    int row = src->row - 'A';
    int col = src->col - '0' - 1;

    SingleSourceMovesTree* tree = (SingleSourceMovesTree*)malloc(sizeof(SingleSourceMovesTree));
    checkMemoryAllocation(tree);

    unsigned short total_captures_so_far = 0;
    tree->source = FindSingleSourceMove(board, src, board[row][col], total_captures_so_far);
    return tree;
}

void PrintSingleSourceMovesTree(SingleSourceMovesTreeNode* node){
    if(node == NULL)
        return;

    if(node->pos == NULL)
        return;

    printf("move: %c%c\n", node->pos->row, node->pos->col);
    PrintSingleSourceMovesTree(node->next_move[LEFT]);
    PrintSingleSourceMovesTree(node->next_move[RIGHT]);
}
