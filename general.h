#ifndef GENERAL_H
#define GENERAL_H

#define BOARD_SIZE 8
#define INITIAL_PIECE_NUM 12

// Piece constants
#define EMPTY 'E'
#define WHITE 'w'
#define TOP_PLAYER 'T'
#define BOTTOM_PLAYER 'B'
#define LEFT 0
#define RIGHT 1

typedef struct _checkersPos{
    char row, col;
} checkersPos;

typedef unsigned char Board[BOARD_SIZE][BOARD_SIZE];
typedef unsigned char Player;
typedef int PiecesNum;

// Function prototypes
void init_board(Board *board);
void print_board(Board *board);
void checkMemoryAllocation(void* ptr);
#endif //GENERAL_H
