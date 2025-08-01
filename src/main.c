#include "init.h"
#include "button.h"
#include "acceleration_app.h"

#include "gfx.h"
#include "display.h"
#include "tic_tac_toe/board.h"


int main() {
    initBoard();
    initPlayerBoard();
    initPlayer();

    setField(0,0, ONE);

    setField(0,1, TWO);

    drawBoard();

    return 0;
}
