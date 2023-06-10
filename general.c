#include "general.h"
#include <stdio.h>
#include <stdlib.h>

void init_board(Board *board) {
    // Initialize the board to its starting position:
    // the initial positions of the players & empty squares
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                (*board)[row][col] = WHITE;
            }
            else if (row<3 && (row + col) % 2 == 1){
                (*board)[row][col] = TOP_PLAYER;
            }
            else if (row>4 && (row + col) % 2 == 1){
                (*board)[row][col] = BOTTOM_PLAYER;
            }
            else{
                (*board)[row][col] = EMPTY;
            }
        }
    }
}


void checkMemoryAllocation(void* ptr) {
    //This function gets a pointer ptr and checks if he is NULL - if yes exits the program.
    if(ptr == NULL) {
        printf("Memory Allocation Failed");
        exit(1);
    }
}