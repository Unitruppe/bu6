#include "init.h"
#include "tic_tac_toe/board.h"

#include "display.h"
#include "touch.h"


int main() {
    initBoard();
    initPlayerBoard();
    initPlayer();

    drawBoard();

    Players winner;
    while(!didSomeoneWin(&winner)){
        //debugTouch_s();
        Players current = getCurrentPlayer();
        while(!drawCell(current));
        nextPlayer();
    }

    initCursor();
    writeText("Finished");



    return 0;
}
