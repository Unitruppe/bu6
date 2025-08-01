#include "player.h"

#define BOARD_DIM 3
#define BOARD_HEIGHT BOARD_DIM
#define BOARD_WIDTH BOARD_DIM

#define BOARD_FIELD_SIZE 320
#define BOARD_FIELD_OFFSET_X 80
#define BOARD_FIELD_OFFSET_Y 0

#define BOARD_CELL_SIZE (BOARD_FIELD_SIZE / 3)

#define BOARD_DRAW_COLOR WHITE

typedef enum {
    NONE,
    PLAYER_ONE,
    PLAYER_TWO,
} BoardCharacter;

void initPlayerBoard();

void setField(uint8_t x, uint8_t y, Players player);

void drawBoard();

uint8_t drawCell(Players currentPlayer);

uint8_t didSomeoneWin(Players* player);