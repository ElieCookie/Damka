//
// Created by Eleanor Borohov on 04/06/2023.
//
#include "general_settings.h"

void printBoardStatus(Board board){
    printf("+-+-+-+-+-+-+-+-+-+\n+ |1|2|3|4|5|6|7|8|\n+-+-+-+-+-+-+-+-+-+\n");

    for(int row = 0; row< BOARD_SIZE; row++){
        printf("|%c|", row+'A');

        for(int col = 0; col< BOARD_SIZE; col++){
            if(board[row][col] == 'T')
                printf("T|");
            else if(board[row][col] == EMPTY || board[row][col] == WHITE)
                printf(" |");
            else if(board[row][col] == 'B')
                printf("B|");
        }
        printf("\n+-+-+-+-+-+-+-+-+-+\n");
    }
}

bool checkIfLastRow(Board board, Player player){
    if(player == 'T'){
        for(int i = 0; i<BOARD_SIZE; i+=2){
            if(board[BOARD_SIZE][i] == player)
                return true;
        }
        return false;
    }
    else{
        for(int i = 1; i<BOARD_SIZE; i+=2){
            if(board[0][i] == player)
                return true;
        }
        return false;
    }
}

int countPieces(Board board, Player player){
    int pieces_counter = 0;

    for(int row = 0; row < BOARD_SIZE; row++){
        for(int col = 0; col < BOARD_SIZE; col++){
            if(board[row][col] == player)
                pieces_counter++;
        }
    }
    return pieces_counter;
}

void PlayGame(Board board, Player starting_player){

    PiecesNum starting_pieces = 12;
    PiecesNum opposing_pieces = 12;
    Player opposing_player;
    bool game_over = false;
    int max_starting_player_captures_count = 0, max_opposing_player_captures_count = 0,
    starting_player_moves_count = 0, opposing_player_moves_count = 0,
    curr_starting_piece_count, curr_opposing_piece_count;


    // Initialize opposing player
    if(starting_player == 'T') {
        opposing_player = 'B';
    }
    else {
        opposing_player = 'T';
    }

    // printing the initial board
    printBoardStatus(board);

    while(!game_over){

        // starting player
        printf("%c's turn:\n", starting_player);
        Turn(board, starting_player);
        starting_player_moves_count++;
        printBoardStatus(board);

        curr_opposing_piece_count = countPieces(board, opposing_player);
        max_starting_player_captures_count = max(max_starting_player_captures_count,
                                                 opposing_pieces - curr_opposing_piece_count);

        opposing_pieces = curr_opposing_piece_count;

        if(curr_opposing_piece_count == 0 || checkIfLastRow(board, starting_player)){
            game_over = true;
            printf("%c wins!\n%c performed %d moves.\n", starting_player,
                   starting_player, starting_player_moves_count);

            if(max_starting_player_captures_count > max_opposing_player_captures_count)
                printf("%c performed the highest number of captures in a single move - %d\n",
                       starting_player, max_starting_player_captures_count);
            else
                printf("%c performed the highest number of captures in a single move - %d\n",
                       opposing_player, max_opposing_player_captures_count);
            break;
        }

        // opposing player
        printf("%c's turn:\n", opposing_player);
        Turn(board, opposing_player);
        opposing_player_moves_count++;
        printBoardStatus(board);

        curr_starting_piece_count = countPieces(board, starting_player);
        max_opposing_player_captures_count = max(max_opposing_player_captures_count,
                                                 starting_pieces - curr_starting_piece_count);

        starting_pieces = curr_starting_piece_count;

        if(curr_starting_piece_count == 0 || checkIfLastRow(board, opposing_player)){
            game_over = true;
            printf("%c wins!\n%c performed %d moves.\n", opposing_player,
                   opposing_player, opposing_player_moves_count);

            if(max_starting_player_captures_count > max_opposing_player_captures_count)
                printf("%c performed the highest number of captures in a single move - %d\n",
                       starting_player, max_starting_player_captures_count);
            else
                printf("%c performed the highest number of captures in a single move - %d\n",
                       opposing_player, max_opposing_player_captures_count);
            break;
        }

    }


}