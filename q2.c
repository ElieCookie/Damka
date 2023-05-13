//
// Created by Lidor Levi on 13/05/2023.
//

#include "general_settings.h"

SingleSourceMovesList * FindSingleSourceOptimalMove(SingleSourceMovesTree* moves_tree) {
    SingleSourceMovesList* res;
    makeEmptyList(res);
    int currentPlayerSymbol = moves_tree->source->board[moves_tree->source->pos->row][moves_tree->source->pos->col];
    FindSingleSourceOptimalMoveHelper(moves_tree->source, currentPlayerSymbol, res);
    return res;
}


void FindSingleSourceOptimalMoveHelper(SingleSourceMovesTreeNode* moves_cell, char player, SingleSourceMovesList* res) {
    if(moves_cell == NULL)
        return;
    addMovesListCellToStartList(res, createMovesListCell(moves_cell->pos, moves_cell->total_captures_so_far));
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
        else {
            if(player == TOP_PLAYER)
                FindSingleSourceOptimalMoveHelper(moves_cell->next_move[1], player, res);
            else
                FindSingleSourceOptimalMoveHelper(moves_cell->next_move[0], player, res);

        }
    }
}