#include "general_settings.h"

MultipleSourceMovesListCell* MostOptimalMoveFrom(MultipleSourceMovesListCell* move, Player player){
    if(move == NULL)
        return NULL;

    MultipleSourceMovesListCell* optimal = move;
    MultipleSourceMovesListCell* curr = move->next;
    while (curr)
    {
        if(optimal->single_source_moves_list->head->captures < curr->single_source_moves_list->head->captures)
        {
            optimal = curr;
        }
        else if(optimal->single_source_moves_list->head->captures == curr->single_source_moves_list->head->captures)
        {
            if(player == 'T')
            {
                if(optimal->single_source_moves_list->head->position->row <
                    curr->single_source_moves_list->head->position->row)
                {
                    optimal = curr;
                }
                else if((optimal->single_source_moves_list->head->position->row ==
                        curr->single_source_moves_list->head->position->row) &&
                        (optimal->single_source_moves_list->head->position->col <
                       curr->single_source_moves_list->head->position->col))
                {
                        optimal = curr;
                }
            }
            else
            {
                if(optimal->single_source_moves_list->head->position->row >
                   curr->single_source_moves_list->head->position->row)
                {
                    optimal = curr;
                }
                else if((optimal->single_source_moves_list->head->position->row ==
                         curr->single_source_moves_list->head->position->row) &&
                        (optimal->single_source_moves_list->head->position->col >
                         curr->single_source_moves_list->head->position->col))
                {
                    optimal = curr;
                }
            }
        }
        curr = curr->next;
    }

    return optimal;
}

void updateBoard(Board board, MultipleSourceMovesListCell* move){

}

void Turn(Board board, Player player){
    MultipleSourceMovesList* moves = FindAllPossiblePlayerMoves(board, player);
    MultipleSourceMovesListCell* optimal_move = MostOptimalMoveFrom(moves->head, player);
    updateBoard(board, optimal_move);
}