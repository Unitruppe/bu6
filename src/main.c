#include "init.h"
#include "tic_tac_toe/board.h"

#include "display.h"
#include "delay.h"


int main() {
    initBoard();
    initPlayerBoard();
    initPlayer();
    initCursor();

    drawBoard();

    Players winner;
    while(!didSomeoneWin(&winner)){
        //debugTouch_s();
        Players current = getCurrentPlayer();
        while(!drawCell(current));
        nextPlayer();
    }

    printWinner(winner);

    
    cppp_delay(1000000);

    return 0;
}
