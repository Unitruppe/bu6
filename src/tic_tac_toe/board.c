#include <stdint.h>
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
    int fieldX = 80;
    int fieldY = 0;
    int fieldSize = 320;
    int cellSize = fieldSize / 3;

    int cx = fieldX + x * cellSize + cellSize / 2;
    int cy = fieldY + y * cellSize + cellSize / 2;

    int radius = cellSize / 3; 

    cppp_drawCircle(cx, cy, radius, BOARD_DRAW_COLOR);
}

void drawXInCell(int x, int y) {
    int fieldX = 80;
    int fieldY = 0;
    int fieldSize = 320;
    int cellSize = fieldSize / 3;

    int cx = fieldX + x * cellSize + cellSize / 2;
    int cy = fieldY + y * cellSize + cellSize / 2;

    int lineLength = cellSize / 3; 

    cppp_drawLine(cx - lineLength, cy - lineLength, cx + lineLength, cy + lineLength, BOARD_DRAW_COLOR);
    cppp_drawLine(cx - lineLength, cy + lineLength, cx + lineLength, cy - lineLength, BOARD_DRAW_COLOR); 
}

void drawBoard() {
    int fieldX = 80;  
    int fieldY = 0;   
    int fieldSize = 320;
    int cellSize = fieldSize / 3;

    // Draw vertical lines
    cppp_drawLine(fieldX + cellSize, fieldY, fieldX + cellSize, fieldY + fieldSize, BOARD_DRAW_COLOR);
    cppp_drawLine(fieldX + 2 * cellSize, fieldY, fieldX + 2 * cellSize, fieldY + fieldSize, BOARD_DRAW_COLOR);

    // Draw horizontal lines
    cppp_drawLine(fieldX, fieldY + cellSize, fieldX + fieldSize, fieldY + cellSize, BOARD_DRAW_COLOR);
    cppp_drawLine(fieldX, fieldY + 2 * cellSize, fieldX + fieldSize, fieldY + 2 * cellSize, BOARD_DRAW_COLOR);

    for(int i = 0; i < BOARD_WIDTH; i++) {
        for(int j = 0; j < BOARD_HEIGHT; j++) {
            switch (board[j][i]) {
                case NONE:
                    break;
                case PLAYER_ONE:
                    drawXInCell(i, j);
                    break;
                case PLAYER_TWO:
                    drawOInCell(i, j);
                    break;

            }
        }
    }
}

