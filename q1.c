#include "general_settings.h"

// Params: a game board, a destination position and a player
// Checks if the destination position is occupied by a piece of the same player
bool isBlockedBySame(Board board, checkersPos *dest, Player player){
    int row = dest->row - 'A';
    int col = dest->col - '0' - 1;

    return (board[row][col] == player);
}

// Params: a game board, a destination position and a player
// Checks if the destination position is occupied by a piece of the opposite player
bool isBlockedByOther(Board board, checkersPos *dest, Player player){
    int row = dest->row - 'A';
    int col = dest->col - '0' - 1;

    return(((player == 'T') && (board[row][col] == 'B')) || ((player == 'B') && (board[row][col] == 'T')));
}

// Params: source position, direction of move, player
// Finds the destination position of the player according to the source position, and returns it,
// if no destination was found returns Null
checkersPos* findDest(checkersPos *src, int direction, Player player){
    checkersPos *dest = (checkersPos*) malloc(sizeof(checkersPos));
    checkMemoryAllocation(dest);

    // going down
    if(player == 'T'){

        // going left
        if(direction == 0){
                dest->row = (src->row) + 1;
                dest->col = (src->col) - 1;
                return dest;
        }
            // going right
        else{
                dest->row = (src->row) + 1;
                dest->col = (src->col) + 1;
                return dest;
        }
    }

        // going up
    else if(player == 'B'){

        // going left
        if(direction == 0){
                dest->row = (src->row) - 1;
                dest->col = (src->col) - 1;
                return dest;
        }
            // going right
        else{
                dest->row = (src->row) - 1;
                dest->col = (src->col) + 1;
                return dest;
        }
    }
    else
        return NULL;
}


// Params: a game board, a destination position
// Checks if the destination position is an empty checker
bool isEmptyChecker(Board board, checkersPos *dest){
    int row = dest->row - 'A';
    int col = dest->col - '0' - 1;

    return(board[row][col] == EMPTY);
}

// Params: a game board, a source position
// Checks if the source position is an empty/white checker
bool noPlayer(Board board, checkersPos *src){
    int row = src->row - 'A';
    int col = src->col - '0' - 1;

    return(board[row][col] == EMPTY || board[row][col] == WHITE);
}

// Params: a source position
// Checks if the source position is out of the board boundaries
bool isCorruptedPos(checkersPos *src){
    return(src->row > 'H' || src->row < 'A' || src->col > '8' || src->col < '1');
}

// Params: a source board, and a pointer to the destination board
// copies the values from the source board to the destination board
void copyBoard(Board *dest, Board src){
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if(src[row][col] == EMPTY)
                (*dest)[row][col] = EMPTY;
            else if (src[row][col] == WHITE)
                (*dest)[row][col] = WHITE;
            else if (src[row][col] == TOP_PLAYER)
                (*dest)[row][col] = TOP_PLAYER;
            else if (src[row][col] == BOTTOM_PLAYER)
                (*dest)[row][col] = BOTTOM_PLAYER;
        }
    }
}

// Params: a board, the source position, a player, and the number of total captures
// executes the flow of the capturing move, assures that the immediate move after a capture,
// will do another capture or finish move, then returns the root of the tree
SingleSourceMovesTreeNode* CaptureFlow(Board board, checkersPos* src, Player player, unsigned short total_captures_so_far) {
    if (noPlayer(board, src) || isCorruptedPos(src))
        return NULL;

    SingleSourceMovesTreeNode *root = (SingleSourceMovesTreeNode *) malloc(sizeof(SingleSourceMovesTreeNode));
    checkMemoryAllocation(root);

    // Copy the board to the root node
    copyBoard(&root->board, board);

    root->pos = src;
    root->next_move[LEFT] = NULL;
    root->next_move[RIGHT] = NULL;
    root->total_captures_so_far = total_captures_so_far;

    checkersPos *dest_left = findDest(src, LEFT, player);
    checkersPos *dest_right = findDest(src, RIGHT, player);

    // handling the left side
    if (isBlockedByOther(board, dest_left, player)) {
        // the destination after the capture
        checkersPos *cap_dest = findDest(dest_left, LEFT, player);
        // if destination for capture is empty
        if (isEmptyChecker(board, cap_dest)) {
            Board left_board;
            copyBoard(&left_board, board);
            left_board[src->row - 'A'][src->col - '0' - 1] = EMPTY;
            left_board[cap_dest->row - 'A'][cap_dest->col - '0' - 1] = player;
            left_board[dest_left->row - 'A'][dest_left->col - '0' - 1] = EMPTY;

            root->next_move[LEFT] = CaptureFlow(left_board, cap_dest, player, total_captures_so_far + 1);
        }
    }

    // handling the right side
    if (isBlockedByOther(board, dest_right, player)) {
        // the destination after the capture
        checkersPos *cap_dest = findDest(dest_right, RIGHT, player);
        if (isEmptyChecker(board, cap_dest)) {
            Board right_board;
            copyBoard(&right_board, board);
            right_board[cap_dest->row - 'A'][cap_dest->col - '0' - 1] = player;
            right_board[src->row - 'A'][src->col - '0' - 1] = EMPTY;
            right_board[dest_right->row - 'A'][dest_right->col - '0' - 1] = EMPTY;

            root->next_move[RIGHT] = CaptureFlow(right_board, cap_dest, player, total_captures_so_far + 1);
        }
    }
    return root;
}

// Params: a board, the source position, a player, and the number of total captures
// executes the regular flow of the move, building a tree with the relevant moves for one turn,
// then returns the root of the tree
SingleSourceMovesTreeNode* FindSingleSourceMove(Board board, checkersPos* src, Player player, unsigned short total_captures_so_far) {
    if (noPlayer(board, src) || isCorruptedPos(src))
        return NULL;

    SingleSourceMovesTreeNode* root = (SingleSourceMovesTreeNode*)malloc(sizeof(SingleSourceMovesTreeNode));
    checkMemoryAllocation(root);

    // Copy the board to the root node
    copyBoard(&root->board, board);

    root->pos = src;
    root->next_move[LEFT] = NULL;
    root->next_move[RIGHT] = NULL;
    root->total_captures_so_far = total_captures_so_far;

    checkersPos* dest_left = findDest(src, LEFT, player);
    checkersPos* dest_right = findDest(src, RIGHT, player);

    // Handle the left side
    if (!isBlockedBySame(board, dest_left, player)) {
        if (isBlockedByOther(board, dest_left, player)) {
            // the destination after the capture
            checkersPos* cap_dest = findDest(dest_left, LEFT, player);
            // if destination for capture is empty
            if (isEmptyChecker(board, cap_dest)) {
                Board left_board;
                copyBoard(&left_board, board);
                left_board[src->row - 'A'][src->col - '0' - 1] = EMPTY;
                left_board[cap_dest->row - 'A'][cap_dest->col - '0' - 1] = player;
                left_board[dest_left->row - 'A'][dest_left->col - '0' - 1] = EMPTY;

                root->next_move[LEFT] = CaptureFlow(left_board, cap_dest, player, total_captures_so_far + 1);
            }
        } else if (isEmptyChecker(board, dest_left)) {
            Board left_board;
            copyBoard(&left_board, board);
            left_board[src->row - 'A'][src->col - '0' - 1] = EMPTY;
            left_board[dest_left->row - 'A'][dest_left->col - '0' - 1] = player;

            SingleSourceMovesTreeNode* left_node = (SingleSourceMovesTreeNode*)malloc(sizeof(SingleSourceMovesTreeNode));
            checkMemoryAllocation(left_node);

            // Copy the board to the left node
            copyBoard(&left_node->board, left_board);

            left_node->pos = dest_left;
            left_node->next_move[LEFT] = NULL;
            left_node->next_move[RIGHT] = NULL;
            left_node->total_captures_so_far = total_captures_so_far;

            root->next_move[LEFT] = left_node;
        }
    }

    // Handle the right side
    if (!isBlockedBySame(board, dest_right, player)) {
        if (isBlockedByOther(board, dest_right, player)) {
            // the destination after the capture
            checkersPos* cap_dest = findDest(dest_right, RIGHT, player);
            if (isEmptyChecker(board, cap_dest)) {
                Board right_board;
                copyBoard(&right_board, board);
                right_board[cap_dest->row - 'A'][cap_dest->col - '0' - 1] = player;
                right_board[src->row - 'A'][src->col - '0' - 1] = EMPTY;
                right_board[dest_right->row - 'A'][dest_right->col - '0' - 1] = EMPTY;

                root->next_move[RIGHT] = CaptureFlow(right_board, cap_dest, player, total_captures_so_far + 1);
            }
        } else if (isEmptyChecker(board, dest_right)) {
            Board right_board;
            copyBoard(&right_board, board);
            right_board[src->row - 'A'][src->col - '0' - 1] = EMPTY;
            right_board[dest_right->row - 'A'][dest_right->col - '0' - 1] = player;

            SingleSourceMovesTreeNode* right_node = (SingleSourceMovesTreeNode*)malloc(sizeof(SingleSourceMovesTreeNode));
            checkMemoryAllocation(right_node);

            // Copy the board to the right node
            copyBoard(&right_node->board, right_board);

            right_node->pos = dest_right;
            right_node->next_move[LEFT] = NULL;
            right_node->next_move[RIGHT] = NULL;
            right_node->total_captures_so_far = total_captures_so_far;

            root->next_move[RIGHT] = right_node;
        }
    }
    return root;
}

// Params: a board, the source position
// calls the helper function to build the moves tree
SingleSourceMovesTree* FindSingleSourceMoves(Board board, checkersPos *src){
    int row = src->row - 'A';
    int col = src->col - '0' - 1;

    SingleSourceMovesTree* tree = (SingleSourceMovesTree*)malloc(sizeof(SingleSourceMovesTree));
    checkMemoryAllocation(tree);

    unsigned short total_captures_so_far = 0;
    tree->source = FindSingleSourceMove(board, src, board[row][col], total_captures_so_far);
    return tree;
}
