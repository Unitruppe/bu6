#ifndef PLAYER_H
#define PLAYER_H

typedef enum {
    ONE,
    TWO
} Players;

void initPlayer();

Players getCurrentPlayer();

void nextPlayer();

#endif