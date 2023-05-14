#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "general_settings.h"

void initPieces(Piece *pieces, Player p, unsigned char direction, Board board) {
    int piece_count=0;
    int start_row, end_row;

    if(p == 'T'){
        start_row = 0;
        end_row = 2;
    }
    else{
        start_row = 5;
        end_row = 7;
    }

    for (int row = start_row; row <= end_row; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
             // initialize each Piece
            if(board[row][col] == p){
                pieces[piece_count].pos = (checkersPos*)malloc(sizeof(checkersPos));
                if(pieces[piece_count].pos == NULL)
                    exit(1);

                pieces[piece_count].pos->row = row + 'A';
                pieces[piece_count].pos->col = col + '1';

                pieces[piece_count].player = p;
                pieces[piece_count].moves.source = NULL;
                pieces[piece_count].direction = direction;
               
                piece_count++;
            }    
        }
    }
}

void print_all_pieces(Piece *pieces, PiecesNum num){
    for (int i = 0; i < num; i++) {
        printf("Pos: %c%c\nPlayer: %c\n", pieces[i].pos->row, pieces[i].pos->col, pieces[i].player);
    }
}