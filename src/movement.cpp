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

        //static std::string units = "mm";
        //as of july 29th theese are just placeholder values and SHOULD be changed using the init class once implemented 
        //################################################
        //adjust as needed when robot built###############



    public:
        //adjusts the variable table for the math in the other functions.
        Drive(double wheelDia, double gearRatio, double motorRes)
        :WheelDiameter(wheelDia), gearRatio(gearRatio), motorRes(motorRes){
            wheelCircumference = M_PI * WheelDiameter;
            encodersPerRev = motorRes / gearRatio;
            distPerCount = wheelCircumference / encodersPerRev;
            if(wheelCircumference ==2){

            }
        }

        void move(char direc, int dist, int speed){
            
        }
        void turn(int angle, int speed){

        }
        void strafe(char direc, int dist, int speed){

        }
        void reset(void){
            LeftDrive.resetPosition();
            RightDrive.resetPosition();
        }
};

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

