#include "player.h"
#include "../touch.h"
#include "../display.h"

Players currentPlayer;

void initPlayer(){
    currentPlayer = 0;
}

Players getCurrentPlayer() {
    return currentPlayer;
}

void nextPlayer() {
    currentPlayer = (currentPlayer + 1) % 2;
}

void printWinner(Players winner){
    setTextSize(2);
    setTextColor(RED);

    switch(winner){
        case ONE: writeCenteredText("Player 1 wins"); break;
        case TWO: writeCenteredText("Player 2 wins"); break;
    }
}






