#pragma once
#include "vex.h"
#include <string>


void move(char direc, int dist, int speed);
void turn(int angle, int speed);
void strafe(char direc, int dist, int speed);
void move_init(void);