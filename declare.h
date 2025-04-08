#ifndef declare.h
#define declare.h
#include"Header.h"
#define WINDOWTITLE "GALAXY"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int SHIP_HEAD_WIDTH = 16;
const int SHIP_HEAD_HEIGHT = 20;
const int SHIP_BODY_WIDTH = 54;
const int SHIP_BODY_HEIGHT = 30;
const int BULLET_WIDTH = 2;
const int BULLET_HEIGHT = 10;
const int SHIP_Y = SCREEN_WIDTH - 60;
const int TIME_BURST = 13;
const int DENSITY = 50;
const int AMMO = 100;
const int QUANTITY = 500;
const int BULLET_SPEED = 20;
const int BODY_TIME = 10;
struct ship_struct
{
    int X;
    int Y;
};

struct bullet_struct
{
    bool SHOW;
    int TIME;
    int DISTANCE;
    int X;
    int Y;
};

struct meteorite_struct
{
    bool SHOW;
    int BURST;
    int X;
    int Y;
    int VECTOR_X;
    int VECTOR_Y;
    int SIZE;
};
#endif
