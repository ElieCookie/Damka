//
// Created by Lidor Levi on 13/05/2023.
//

#include "general_settings.h"

//This function gets a SingleSourceMovesTree pointer moves_tree and finds the optimal move from the tree using the helper function FindSingleSourceOptimalMoveHelper
SingleSourceMovesList * FindSingleSourceOptimalMove(SingleSourceMovesTree* moves_tree) {
    SingleSourceMovesList* res = calloc(1, sizeof (SingleSourceMovesList));
    checkMemoryAllocation(res);
    Player currentPlayer = moves_tree->source->board[moves_tree->source->pos->row - 'A'][moves_tree->source->pos->col - '1'];
    FindSingleSourceOptimalMoveHelper(moves_tree->source, currentPlayer, res);
    return res;
}


//This function gets SingleSourceMovesTreeNode pointer moves_cell, a Player and  a SingleSourceMovesList pointer res.
//The function is a helper function to FindSingleSourceOptimalMove. it finds the optimal SingleSourceMovesTreeNode move from the original SingleSourceMovesTree and adds that to res
void FindSingleSourceOptimalMoveHelper(SingleSourceMovesTreeNode* moves_cell, Player player, SingleSourceMovesList* res) {
    if(moves_cell == NULL)
        return;
    addMovesListCellToEndOfList(res, createMovesListCell(moves_cell->pos, moves_cell->total_captures_so_far));
    if(moves_cell->next_move[0] == NULL && moves_cell->next_move[1] == NULL)
        return;
    else if(moves_cell->next_move[0] != NULL && moves_cell->next_move[1] == NULL)
        FindSingleSourceOptimalMoveHelper(moves_cell->next_move[0], player, res);
    else if(moves_cell->next_move[0] == NULL && moves_cell->next_move[1] != NULL)
        FindSingleSourceOptimalMoveHelper(moves_cell->next_move[1], player, res);
    else if(moves_cell->next_move[0] != NULL && moves_cell->next_move[1] != NULL) {
        int leftHeight = SubTreeHeight(moves_cell->next_move[0]);
        int rightHeight = SubTreeHeight(moves_cell->next_move[1]);
        if(rightHeight > leftHeight)
            FindSingleSourceOptimalMoveHelper(moves_cell->next_move[1], player, res);
        else if(leftHeight > rightHeight)
            FindSingleSourceOptimalMoveHelper(moves_cell->next_move[0], player, res);
        else
                FindSingleSourceOptimalMoveHelper(moves_cell->next_move[findHigherSide(moves_cell->next_move[0]->total_captures_so_far, moves_cell->next_move[1]->total_captures_so_far, player)], player, res);
    }
}


//This function gets 2 integer numbers, left and right and a player
//The function returns the higher size, if they equal, it returns RIGHT if the player is TOP_PLAYER otherwise it returns LEFT.
int findHigherSide(int left, int right, Player player) {
    if (left > right)
        return LEFT;
    else if(right > left)
        return RIGHT;
    else {
        if(player == TOP_PLAYER)
            return RIGHT;
        else return LEFT;
    }
}