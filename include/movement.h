#pragma once
#include "vex.h"
#include <string>


#include "vex.h"
#include <string>
#include <cmath>
#include "movement.h"
#include "robot-config.h"


class Drive{
    private:

        //variables needed for the math ##################
        //################################################
        double WheelDiameter;
        double wheelCircumference ; //diameter x pi
        double motorRes;
        double gearRatio; //wheelteeth/motorteeth
        double wheel_res; //300 or 900 or 1800-> 6:1 / 18:1 / 32:1
        double encodersPerRev;
        double distPerCount;
    public:
        //adjusts the variable table for the math in the other functions.
        Drive(double wheelDia, double gearRatio, double motorRes);
        void move(char direc, int dist, int speed);
        void turn(int angle, int speed);
        void strafe(char direc, int dist, int speed);
        void reset(void);
};
