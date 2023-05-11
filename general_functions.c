#include <stdio.h>
#include <stdlib.h>
// #include "general.h"
#include "general_settings.h"

//void find_moves_recursive(SingleSourceMovesTreeNode **node, int player, int depth);

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

void print_board(Board *board) {
    // Print the board to the console
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch ((*board)[row][col]) {
                case EMPTY:
                    printf(" -");
                    break;
                case GRAY:
                    printf(" g");
                    break;
                case WHITE:
                    printf(" w");
                    break;
                case TOP_PLAYER:
                    printf(" T");
                    break;
                case BOTTOM_PLAYER:
                    printf(" B");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}

void init_single_source_moves_tree(SingleSourceMovesTree *moves){
    moves->source = NULL;
}

void init_single_source_moves_tree_node(SingleSourceMovesTreeNode *move){
    move->pos = NULL;
    move->total_captures_so_far = 0;
}

void initPieces(Piece *pieces, Player p, unsigned char direction, Board board) {
    int piece_count=0;
    int start_row, end_row;

    if(p == t_player){
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
    for (int i = 0; i <= num; i++) {
        printf("Pos: %c%c\nPlayer: %c\n", pieces[i].pos->row, pieces[i].pos->col, pieces[i].player);
    }
}


//
//int is_valid_move(Board *board, int player, int from_row, int from_col, int to_row, int to_col) {
//    // Check if the move is valid
//    // Return 1 if the move is valid, 0 otherwise
//
//    // Check if the destination is out of bounds
//    if (to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) {
//        return 0;
//    }
//
//    // Check if the destination is occupied
//    if ((*board)[to_row][to_col] != EMPTY) {
//        return 0;
//    }
//
//    // Check if the player is moving in the right direction
//    if (player == WHITE && to_row >= from_row) {
//        return 0;
//    }
//    if (player == GRAY && to_row <= from_row) {
//        return 0;
//    }
//    // Check if the move is a capture
//    if (abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2) {
//        // Check if there is a piece to capture
//        int captured_row = (to_row + from_row) / 2;
//        int captured_col = (to_col + from_col) / 2;
//        if ((*board)[captured_row][captured_col] == EMPTY) {
//            return 0;
//        }
//
//        // Check if the piece being captured is of the opposite color
//        if (((*board)[captured_row][captured_col] == GRAY || (*board)[captured_row][captured_col] == GRAY_KING) && player == WHITE) {
//            return 0;
//        }
//        if (((*board)[captured_row][captured_col] == WHITE || (*board)[captured_row][captured_col] == WHITE_KING) && player == GRAY) {
//            return 0;
//        }
//
//        return 1;
//    }
//
//// Check if the move is a regular move
//    if (abs(to_row - from_row) == 1 && abs(to_col - from_col) == 1) {
//        return 1;
//    }
//
//    return 0;
//}
//
//void make_move(Board *board, int player, int from_row, int from_col, int to_row, int to_col) {
//// Make the move on the board
//    (*board)[to_row][to_col] = (*board)[from_row][from_col];
//    (*board)[from_row][from_col] = EMPTY;
//
//// If the piece has reached the opposite end of the board, crown it a king
//    if (player == WHITE && to_row == 0) {
//        (*board)[to_row][to_col] = WHITE_KING;
//    }
//    if (player == GRAY && to_row == BOARD_SIZE - 1) {
//        (*board)[to_row][to_col] = GRAY_KING;
//    }
//
//// If the move is a capture, remove the captured piece
//    if (abs(to_row - from_row) == 2 && abs(to_col - from_col) == 2) {
//        int captured_row = (to_row + from_row) / 2;
//        int captured_col = (to_col + from_col) / 2;
//        (*board)[captured_row][captured_col] = EMPTY;
//    }
//}
//
//int is_game_over(Board *board, int player) {
//// Check if the game is over
//// Return 1 if the game is over, 0 otherwise
//// Check if the player has any pieces left
//    for (int row = 0; row < BOARD_SIZE; row++) {
//        for (int col = 0; col < BOARD_SIZE; col++) {
//            if ((player == WHITE && ((*board)[row][col] == WHITE || (*board)[row][col] == WHITE_KING)) ||
//                (player == GRAY && ((*board)[row][col] == GRAY || (*board)[row][col] == GRAY_KING))) {
//                return 0;
//            }
//        }
//    }
//
//    return 1;
//}
//
//SingleSourceMovesTree* FindSingleSourceMoves(Board board, checkersPos *src) {
//// Find all possible moves for a single piece
//// Return a binary tree with all the move options of the player
//// Check if the source position contains a piece of the player
//    if ((board)[src->row - 'A'][src->col - '1'] == EMPTY ||
//        (board)[src->row - 'A'][src->col - '1'] == ((player == WHITE) ? GRAY : WHITE) ||
//        ((player == WHITE) && ((board)[src->row - 'A'][src->col - '1'] == GRAY_KING)) ||
//        ((player == GRAY) && ((board)[src->row - 'A'][src->col - '1'] == WHITE_KING))) {
//        return NULL;
//    }
//
//// Create a new tree node for the source position
//    SingleSourceMovesTreeNode *root = (SingleSourceMovesTreeNode *) malloc(sizeof(SingleSourceMovesTreeNode));
//    root->board = board;
//    root->pos = src;
//    root->total_captures_so_far = 0;
//    root->next_move[0] = NULL;
//    root->next_move[1] = NULL;
//
//// Find all possible moves from the source position
//    find_moves_recursive(&root, player, 0);
//
//// Create a new tree with the root node
//    SingleSourceMovesTree *tree = (SingleSourceMovesTree *) malloc(sizeof(SingleSourceMovesTree));
//    tree->source = root;
//
//    return tree;
//}
//
//void find_moves_recursive(SingleSourceMovesTreeNode **node, int player, int depth) {
//// Find all possible moves for a piece recursively
//// Update the tree with the new nodes
//// Stop searching if the maximum depth has been reached
//    if (depth >= MAX_DEPTH) {
//        return;
//    }
//
//// Get the position of the piece
//    int row = (*node)->pos->row - 'A';
//    int col = (*node)->pos->col - '1';
//
//// Check if the piece can move diagonally to the left
//    if ((row - 1 >= 0) && (col - 1 >= 0)) {
//        if (is_valid_move(&((*node)->board), player, row, col, row - 1, col - 1)) {
//            // Create a new node for the move
//            SingleSourceMovesTreeNode *new_node = (SingleSourceMovesTreeNode *) malloc(sizeof(SingleSourceMovesTreeNode));
//            new_node->board = (*node)->board;
//            new_node->pos = (checkersPos *) malloc(sizeof(checkersPos));
//            new_node->pos->row = 'A' + row - 1;
//            new_node->pos->col = '1' + col - 1;
//            new_node->total_captures_so_far = (*node)->total_captures_so_far;
//            new_node->next_move[0] = NULL;
//            new_node->next_move[1] = NULL;
//
//            // Make the move on the new board
//            make_move(&(new_node->board), player, row, col, row - 1, col - 1);
//
//            // Update the capture count
//            if (abs(row - (row - 1)) == 2 && abs(col - (col - 1)) == 2) {
//                new_node->total_captures_so_far++;
//            }
//
//            // Add the new node to the tree
//            if ((*node)->next_move[0] == NULL) {
//                (*node)->next_move[0] = new_node;
//            } else {
//                (*node)->next_move[1] = new_node;
//            }
//
//            // Continue searching from the new node
//            find_moves_recursive(&(new_node), player, depth + 1);
//        }
//    }
//
//// Check if the piece can
//// move diagonally to the right
//    if ((row - 1 >= 0) && (col + 1 < size)) {
//        if (is_valid_move(&((*node)->board), player, row, col, row - 1, col + 1)) {
//            // Create a new node for the move
//            SingleSourceMovesTreeNode *new_node = (SingleSourceMovesTreeNode *) malloc(sizeof(SingleSourceMovesTreeNode));
//            new_node->board = (*node)->board;
//            new_node->pos = (checkersPos *) malloc(sizeof(checkersPos));
//            new_node->pos->row = 'A' + row - 1;
//            new_node->pos->col = '1' + col + 1;
//            new_node->total_captures_so_far = (*node)->total_captures_so_far;
//            new_node->next_move[0] = NULL;
//            new_node->next_move[1] = NULL;
//
//            // Make the move on the new board
//            make_move(&(new_node->board), player, row, col, row - 1, col + 1);
//
//            // Update the capture count
//            if (abs(row - (row - 1)) == 2 && abs(col - (col + 1)) == 2) {
//                new_node->total_captures_so_far++;
//            }
//
//            // Add the new node to the tree
//            if ((*node)->next_move[0] == NULL) {
//                (*node)->next_move[0] = new_node;
//            } else {
//                (*node)->next_move[1] = new_node;
//            }
//
//            // Continue searching from the new node
//            find_moves_recursive(&(new_node), player, depth + 1);
//        }
//    }
//
//// Check if the piece is a king and can move diagonally to the left and right in both directions
//    if (((*node)->board)[row][col] == ((player == WHITE) ? WHITE_KING : GRAY_KING)) {
//        // Check if the piece can move diagonally to the left and up
//        if ((row + 1 < size) && (col - 1 >= 0)) {
//            if (is_valid_move(&((*node)->board), player, row, col, row + 1, col - 1)) {
//                // Create a new node for the move
//                SingleSourceMovesTreeNode *new_node = (SingleSourceMovesTreeNode *) malloc(sizeof(SingleSourceMovesTreeNode));
//                new_node->board = (*node)->board;
//                new_node->pos = (checkersPos *) malloc(sizeof(checkersPos));
//                new_node->pos->row = 'A' + row + 1;
//                new_node->pos->col = '1' + col - 1;
//                new_node->total_captures_so_far = (*node)->total_captures_so_far;
//                new_node->next_move[0] = NULL;
//                new_node->next_move[1] = NULL;
//
//                // Make the move on the new board
//                make_move(&(new_node->board), player, row, col, row + 1, col - 1);
//
//                // Update the capture count
//                if (abs(row - (row + 1)) == 2 && abs(col - (col - 1)) == 2) {
//                    new_node->total_captures_so_far++;
//                }
//
//                // Add the new node to the tree
//                if ((*node)->next_move[0] == NULL) {
//                    (*node)->next_move[0] = new_node;
//                } else {
//                    (*node)->next_move[1] = new_node;
//                }
//                // Continue searching from the new node
//                find_moves_recursive(&(new_node), player, depth + 1);
//            }
//        }
//
//        // Check if the piece can move diagonally to the left and down
//        if ((row - 1 >= 0) && (col - 1 >= 0)) {
//            if (is_valid_move(&((*node)->board), player, row, col, row - 1, col - 1)) {
//                // Create a new node for the move
//                SingleSourceMovesTreeNode *new_node = (SingleSourceMovesTreeNode *) malloc(sizeof(SingleSourceMovesTreeNode));
//                new_node->board = (*node)->board;
//                new_node->pos = (checkersPos *) malloc(sizeof(checkersPos));
//                new_node->pos->row = 'A' + row - 1;
//                new_node->pos->col = '1' + col - 1;
//                new_node->total_captures_so_far = (*node)->total_captures_so_far;
//                new_node->next_move[0] = NULL;
//                new_node->next_move[1] = NULL;
//
//                // Make the move on the new board
//                make_move(&(new_node->board), player, row, col, row - 1, col - 1);
//
//                // Update the capture count
//                if (abs(row - (row - 1)) == 2 && abs(col - (col - 1)) == 2) {
//                    new_node->total_captures_so_far++;
//                }
//
//                // Add the new node to the tree
//                if ((*node)->next_move[0] == NULL) {
//                    (*node)->next_move[0] = new_node;
//                } else {
//                    (*node)->next_move[1] = new_node;
//                }
//
//                // Continue searching from the new node
//                find_moves_recursive(&(new_node), player, depth + 1);
//            }
//        }
//
//        // Check if the piece can move diagonally to the right and up
//        if ((row + 1 < size) && (col + 1 < size)) {
//            if (is_valid_move(&((*node)->board), player, row, col, row + 1, col + 1)) {
//                // Create a new node for the move
//                SingleSourceMovesTreeNode *new_node = (SingleSourceMovesTreeNode *) malloc(sizeof(SingleSourceMovesTreeNode));
//                new_node->board = (*node)->board;
//                new_node->pos = (checkersPos *) malloc(sizeof(checkersPos));
//                new_node->pos->row = 'A' + row + 1;
//                new_node->pos->col = '1' + col + 1;
//                new_node->total_captures_so_far = (*node)->total_captures_so_far;
//                new_node->next_move[0] = NULL;
//                new_node->next_move[1] = NULL;
//
//                // Make the move on the new board
//                make_move(&(new_node->board), player, row, col, row + 1, col + 1);
//
//                // Update the capture count
//                if (abs(row - (row + 1)) == 2 && abs(col - (col + 1)) == 2) {
//                    new_node->total_captures_so_far++;
//                }
//
//                // Add the new node to the tree
//                if ((*node)->next_move[0] == NULL) {
//                    (*node)->next_move[0] = new_node;
//                } else {
//                    (*node)->next_move[1] = new_node;
//                }
//
//                // Continue searching from the new node
//                find_moves_recursive(&(new_node),player, depth + 1);
//            }
//        }
//        // Check if the piece can move diagonally to the left and up
//        if ((row + 1 < size) && (col - 1 >= 0)) {
//            if (is_valid_move(&((*node)->board), player, row, col, row + 1, col - 1)) {
//                // Create a new node for the move
//                SingleSourceMovesTreeNode *new_node = (SingleSourceMovesTreeNode *) malloc(sizeof(SingleSourceMovesTreeNode));
//                new_node->board = (*node)->board;
//                new_node->pos = (checkersPos *) malloc(sizeof(checkersPos));
//                new_node->pos->row = 'A' + row + 1;
//                new_node->pos->col = '1' + col - 1;
//                new_node->total_captures_so_far = (*node)->total_captures_so_far;
//                new_node->next_move[0] = NULL;
//                new_node->next_move[1] = NULL;
//
//                // Make the move on the new board
//                make_move(&(new_node->board), player, row, col, row + 1, col - 1);
//
//                // Update the capture count
//                if (abs(row - (row + 1)) == 2 && abs(col - (col - 1)) == 2) {
//                    new_node->total_captures_so_far++;
//                }
//
//                // Add the new node to the tree
//                if ((*node)->next_move[0] == NULL) {
//                    (*node)->next_move[0] = new_node;
//                } else {
//                    (*node)->next_move[1] = new_node;
//                }
//
//                // Continue searching from the new node
//                find_moves_recursive(&(new_node), player, depth + 1);
//            }
//        }
//
//        // Check if the piece can move diagonally to the right and down
//        if ((row - 1 >= 0) && (col + 1 < size)) {
//            if (is_valid_move(&((*node)->board), player, row, col, row - 1, col + 1)) {
//                // Create a new node for the move
//                SingleSourceMovesTreeNode *new_node = (SingleSourceMovesTreeNode *) malloc(sizeof(SingleSourceMovesTreeNode));
//                new_node->board = (*node)->board;
//                new_node->pos = (checkersPos *) malloc(sizeof(checkersPos));
//                new_node->pos->row = 'A' + row - 1;
//                new_node->pos->col = '1' + col + 1;
//                new_node->total_captures_so_far = (*node)->total_captures_so_far;
//                new_node->next_move[0] = NULL;
//                new_node->next_move[1] = NULL;
//
//                // Make the move on the new board
//                make_move(&(new_node->board), player, row, col, row - 1, col + 1);
//
//                // Update the capture count
//                if (abs(row - (row - 1)) == 2 && abs(col - (col + 1)) == 2) {
//                    new_node->total_captures_so_far++;
//                }
//
//                // Add the new node to the tree
//                if ((*node)->next_move[0] == NULL) {
//                    (*node)->next_move[0] = new_node;
//                } else {
//                    (*node)->next_move[1] = new_node;
//                }
//
//                // Continue searching from the new node
//                find_moves_recursive(&(new_node), player, depth + 1);
//            }
//        }
//    }
//
//
//
