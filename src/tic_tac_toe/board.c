#include <stdint.h>
#include "gfx.h"

#include "analog.h"
#include "board.h"

BoardCharacter board[BOARD_HEIGHT][BOARD_WIDTH];

void initPlayerBoard() {
    for(int i = 0; i < BOARD_WIDTH; i++) {
        for(int j = 0; j < BOARD_HEIGHT; j++) {
            board[j][i] = NONE;
        }
    }
}

void setField(uint8_t x, uint8_t y, Players player) {
    switch (player) {
        case ONE:
            board[y][x] = PLAYER_ONE;
            break;
        case TWO:
            board[y][x] = PLAYER_TWO;
            break;
    }
}


void drawOInCell(int x, int y) {
    int cx = BOARD_FIELD_OFFSET_X + x * BOARD_CELL_SIZE + BOARD_CELL_SIZE / 2;
    int cy = BOARD_FIELD_OFFSET_Y + y * BOARD_CELL_SIZE + BOARD_CELL_SIZE / 2;

    int radius = BOARD_CELL_SIZE / 3; 

    cppp_drawCircle(cx, cy, radius, BOARD_DRAW_COLOR);
}

void drawXInCell(int x, int y) {
    int cx = BOARD_FIELD_OFFSET_X + x * BOARD_CELL_SIZE + BOARD_CELL_SIZE / 2;
    int cy = BOARD_FIELD_OFFSET_Y + y * BOARD_CELL_SIZE + BOARD_CELL_SIZE / 2;

    int lineLength = BOARD_CELL_SIZE / 3; 

    cppp_drawLine(cx - lineLength, cy - lineLength, cx + lineLength, cy + lineLength, BOARD_DRAW_COLOR);
    cppp_drawLine(cx - lineLength, cy + lineLength, cx + lineLength, cy - lineLength, BOARD_DRAW_COLOR); 
}

void drawBoard() {
    // Draw vertical lines
    cppp_drawLine(BOARD_FIELD_OFFSET_X + BOARD_CELL_SIZE, BOARD_FIELD_OFFSET_Y, BOARD_FIELD_OFFSET_X + BOARD_CELL_SIZE, BOARD_FIELD_OFFSET_Y + BOARD_FIELD_SIZE, BOARD_DRAW_COLOR);
    cppp_drawLine(BOARD_FIELD_OFFSET_X + 2 * BOARD_CELL_SIZE, BOARD_FIELD_OFFSET_Y, BOARD_FIELD_OFFSET_X + 2 * BOARD_CELL_SIZE, BOARD_FIELD_OFFSET_Y + BOARD_FIELD_SIZE, BOARD_DRAW_COLOR);

    // Draw horizontal lines
    cppp_drawLine(BOARD_FIELD_OFFSET_X, BOARD_FIELD_OFFSET_Y + BOARD_CELL_SIZE, BOARD_FIELD_OFFSET_X + BOARD_FIELD_SIZE, BOARD_FIELD_OFFSET_Y + BOARD_CELL_SIZE, BOARD_DRAW_COLOR);
    cppp_drawLine(BOARD_FIELD_OFFSET_X, BOARD_FIELD_OFFSET_Y + 2 * BOARD_CELL_SIZE, BOARD_FIELD_OFFSET_X + BOARD_FIELD_SIZE, BOARD_FIELD_OFFSET_Y + 2 * BOARD_CELL_SIZE, BOARD_DRAW_COLOR);
}

uint8_t drawCell(Players currentPlayer) {
    uint16_t x = cppp_readTouchX();
    uint16_t y = cppp_readTouchY();
    uint16_t z = cppp_readTouchZ();

    if (z < 100) return 0;

    if (x >= BOARD_FIELD_OFFSET_X && x < BOARD_FIELD_OFFSET_X + BOARD_FIELD_SIZE &&
        y >= BOARD_FIELD_OFFSET_Y && y < BOARD_FIELD_OFFSET_Y + BOARD_FIELD_SIZE) {

        
        int i = (x - BOARD_FIELD_OFFSET_X) / BOARD_CELL_SIZE; 
        int j = (y - BOARD_FIELD_OFFSET_Y) / BOARD_CELL_SIZE; 

        
        if (board[j][i] == NONE) {
            board[j][i] = (currentPlayer == PLAYER_ONE) ? PLAYER_ONE : PLAYER_TWO;

            if (board[j][i] == PLAYER_ONE) {
                drawXInCell(i, j);
            } else {
                drawOInCell(i, j);
            }
            return 1;
        }
    }

    return 0;
}

void setPlayerFromCharacter(BoardCharacter c, Players* player){
    switch(c) {
        case PLAYER_ONE: *player = ONE; break;
        case PLAYER_TWO: *player = TWO; break;
        default: break;
    }
}

uint8_t didSomeoneWin(Players* player){
    for(int i = 0; i < BOARD_DIM; i++) {
        if (board[0][i] != NONE && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            setPlayerFromCharacter(board[0][i], player);
            return 1;
        }
        else if(board[i][0] != NONE && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            setPlayerFromCharacter(board[0][i], player);
            return 1;
        }
    }

    if (board[0][0] != NONE && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        setPlayerFromCharacter(board[0][0], player);
        return 1;
    }

    if (board[0][2] != NONE && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        setPlayerFromCharacter(board[0][2], player);
        return 1;
    }
    
    return 0;      
}
