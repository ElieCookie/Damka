#include "functions.h"

// Params: a board
// Prints the current status of the board
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

// Params: a board, a player
// according to the given player, it checks if there is a piece at the beginning of the opponents' side of the board
bool checkIfLastRow(Board board, Player player){
    if(player == 'T'){
        for(int i = 0; i<BOARD_SIZE; i+=2){
            if(board[BOARD_SIZE - 1][i] == player)
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

// Params: a board, a player
// counts the existing pieces of a given player, and returns it
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

// Params: a board, p1 - the player making the move, p2 - the opponent,
// p2_pieces - a pointer to the number of pieces of the opponent,
// p1_moves_count - a pointer to the number of moves of the player making the current move,
// curr_p2_piece_count - pointer to the current number of the opponents piece count,
// max_p1_captures_count - a pointer of the maximal number of captures per move that p1 made,
// max_p2_captures_count - a pointer of the maximal number of captures per move that p2 made

// The function updates the number of moves of p1, updates the current piece count of p2,
// makes the turn and checks if the player won.
bool MakeTurn(Board board, Player p1, Player p2, PiecesNum *p2_pieces, int *p1_moves_count,
              int *curr_p2_piece_count, int *max_p1_captures_count, int *max_p2_captures_count){
    printf("%c's turn:\n", p1);
    Turn(board, p1);
    *p1_moves_count += 1;
    printBoardStatus(board);

    *curr_p2_piece_count = countPieces(board, p2);
    *max_p1_captures_count = max(*max_p1_captures_count, *p2_pieces - *curr_p2_piece_count);

    *p2_pieces = *curr_p2_piece_count;

    if(*curr_p2_piece_count == 0 || checkIfLastRow(board, p1)){
        printf("%c wins!\n%c performed %d moves.\n", p1,
               p1, *p1_moves_count);

        if(*max_p1_captures_count > *max_p2_captures_count)
            printf("%c performed the highest number of captures in a single move - %d\n",
                   p1, *max_p1_captures_count);
        else
            printf("%c performed the highest number of captures in a single move - %d\n",
                   p2, *max_p2_captures_count);
        return true;
    }
    return false;
}

// Params: a board, the starting player
// The function initiates the piece counter of each player, determines the opponent,
// and calls the turns of the players in a loop.
void PlayGame(Board board, Player starting_player) {

    PiecesNum starting_pieces = 12;
    PiecesNum opposing_pieces = 12;
    Player opposing_player;
    bool starting_won = false, opposing_won = false;
    int max_starting_player_captures_count = 0, max_opposing_player_captures_count = 0,
            starting_player_moves_count = 0, opposing_player_moves_count = 0,
            curr_starting_piece_count, curr_opposing_piece_count;


    // Initialize opposing player
    if (starting_player == 'T') {
        opposing_player = 'B';
    } else {
        opposing_player = 'T';
    }

    // printing the initial board
    printBoardStatus(board);

    while (!starting_won || !opposing_won) {

        starting_won = MakeTurn(board, starting_player, opposing_player,
                                &opposing_pieces, &starting_player_moves_count,
                                &curr_opposing_piece_count,
                                &max_starting_player_captures_count,
                                &max_opposing_player_captures_count);

        if(starting_won)
            break;

        opposing_won = MakeTurn(board, opposing_player, starting_player,
                                &starting_pieces, &opposing_player_moves_count,
                                &curr_starting_piece_count,
                                &max_opposing_player_captures_count,
                                &max_starting_player_captures_count);

        if(opposing_won)
            break;
    }
}