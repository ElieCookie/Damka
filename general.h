#ifndef GENERAL_H
#define GENERAL_H

#define BOARD_SIZE 8
#define INITIAL_PIECE_NUM 12

// Piece constants
#define EMPTY 'E'
#define GRAY 'g'
#define WHITE 'w'
#define TOP_PLAYER 'T'
#define BOTTOM_PLAYER 'B'
#define UP 'U'
#define DOWN 'D'

typedef struct _checkersPos{
    char row, col;
} checkersPos;

typedef unsigned char Board[BOARD_SIZE][BOARD_SIZE];
typedef unsigned char Player;

// Assign players
Player t_player = 'T';
Player b_player = 'B';

typedef int PiecesNum;
PiecesNum T_pieces = 12;
PiecesNum B_pieces = 12;

// Function prototypes
void init_board(Board *board);
void print_board(Board *board);
int is_valid_move(Board *board, Player player, int from_row, int from_col, int to_row, int to_col);
void make_move(Board *board, Player player, int from_row, int from_col, int to_row, int to_col);
int is_game_over(Board *board, Player player);

#endif //GENERAL_H
