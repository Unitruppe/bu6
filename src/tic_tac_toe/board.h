#include "player.h"
#include "gfx.h"

#define BOARD_HEIGHT 3
#define BOARD_WIDTH 3

#define BOARD_DRAW_COLOR WHITE

typedef enum {
    NONE,
    PLAYER_ONE,
    PLAYER_TWO,
} BoardCharacter;

void initPlayerBoard();

void setField(uint8_t x, uint8_t y, Players player);

void drawBoard();