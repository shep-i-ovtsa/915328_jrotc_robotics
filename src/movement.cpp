#include "vex.h"
#include <string>
#include <cmath>
#include "movement.h"
#include "robot-config.h"



//variables needed for the math ##################
//################################################
static double WheelDiameter = 4.0;
static double wheelCircumference = 4.9; //diameter x pi
static double motorRes = 350;
static double gearRatio = 1080; //wheelteeth/motorteeth
static double encodersPerRev = motorRes/ gearRatio;
static double distPerCount = wheelCircumference / encodersPerRev;
static std::string units = "mm";
static double wheel_res = 200;
//as of july 29th theese are just placeholder values and SHOULD be changed using the init class once implemented 
//################################################
//adjust as needed when robot built###############




//adjusts the variable table for the math in the other functions.
void move_init(void){// add varables to the parameter aswell. and split into another init if it gets too many

}

void move(char direc, int dist, int speed){
    
}
void turn(int angle, int speed){

}
void strafe(char direc, int dist, int speed){

}
void reset(void){
    LeftDrive.resetPosition();
}

//###########################################
//important math!!!!!
//Distance traveled = Wheel Circumference x wheel rotations
//Rotations = Encoder counts/ counts per revolution
//Distance = &Rotations x circumference
//circumference = pi x D
//encoders per revolution= encoder resolution(just the amount of encoders in a rev)
//if using a gearchain adjust to effective cpr
//effective res = motor res x gear ratio
//gear ratio = wheel sprocket teeth / motor sprocket teeth

