#ifndef PONG_H
#define PONG_H

#include <libIO.h>
#include <colors.h>
#include <shell.h>
#include <syscalls.h>

#define WIDTH 1024  //x
#define HEIGHT 540  //y
//cada char es de 8x16 pixeles y la pantalla es de 1024x768 pixeles
#define RENGLON 16
#define LETRA 8

#define PADDLE_HEIGHT 40
#define PADDLE_WIDTH 4

#define PADDLE1_X_POSITION (5 * LETRA - 1)
#define PADDLE2_X_POSITION (WIDTH - PADDLE_WIDTH - 5 * LETRA - 1)

#define BALL_RADIUS 4

#define TOP_BOUNDARY (RENGLON * 4)
#define BOTTOM_BOUNDARY (HEIGHT - RENGLON - 2)

void menuPong();
void playPong();
void drawScreen();
void setup(int reset);
void movePlayer(char c);
void moveBall();
void drawObjects(int xFrom, int xTo, int yFrom, int yTo, int color);
void drawPaddle(int x, int y, int player);
void undrawPaddle(int x, int y);
void drawBall(int x, int y);
void undrawBall(int x, int y);
void updateCoords();

#endif