#include "player.h"

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

// void drawChar(){
//     if(currentPlayer == 0){
        
//     }

//     else {

//     }
// }






