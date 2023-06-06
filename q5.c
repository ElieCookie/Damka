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

    // Initialize opposing player
    if(starting_player == 'T') {
        opposing_player = 'B';
    }
    else {
        opposing_player = 'T';
    }


    while(!game_over){

        Turn(board, starting_player);
        printBoardStatus(board);
        if(countPieces(board, opposing_player) == 0 || checkIfLastRow(board, starting_player)){
            game_over = true;
            printf("%c wins!\n", starting_player);
            break;
        }

        Turn(board, opposing_player);
        printBoardStatus(board);
        if(countPieces(board, starting_player) || checkIfLastRow(board, opposing_player)){
            game_over = true;
            printf("%c wins!\n", opposing_player);
            break;
        }

    }


}