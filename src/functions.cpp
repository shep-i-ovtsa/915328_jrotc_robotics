#include "robot-config.h"
#include "vex.h"

using namespace vex;

double inchesToDegrees(double inches) {
 return (((inches)/(3.14 * 3.25)) * 360 * (5.0/3.0));
 //NOTE: 5/3 is the gear ratio, adjust as needed
}


void setDTPosition(double inches) {
    double deg = inchesToDegrees(inches);
    LF.setPosition(deg, degrees);
    LM.setPosition(deg, degrees);
    LB.setPosition(deg, degrees);
    RF.setPosition(deg, degrees);
    RM.setPosition(deg, degrees);
    RB.setPosition(deg, degrees);
}

void stopDT() {
    LF.stop();
    LM.stop();
    LB.stop();
    RF.stop();
    RM.stop();
    RB.stop();
}


void spinRightDT(double velocity) {
    RF.spin(forward, velocity, percent);
    RM.spin(forward, velocity, percent);
    RB.spin(forward, velocity, percent);
}

void spinLeftDT(double velocity) {
    LF.spin(forward, velocity, percent);
    LM.spin(forward, velocity, percent);
    LB.spin(forward, velocity, percent);
}

void spinDT(double velocity) {
    spinRightDT(velocity);
    spinLeftDT(velocity);
}



void spinDTPosition(double velocity, double targetInches) {

    setDTPosition(0);

    double targetDegrees = inchesToDegrees(targetInches);

    LF.spinToPosition(targetDegrees, degrees, velocity, rpm, false);
    LM.spinToPosition(targetDegrees, degrees, velocity, rpm, false);
    LB.spinToPosition(targetDegrees, degrees, velocity, rpm, false);
    RF.spinToPosition(targetDegrees, degrees, velocity, rpm, false);
    RM.spinToPosition(targetDegrees, degrees, velocity, rpm, false);
    RB.spinToPosition(targetDegrees, degrees, velocity, rpm, true);

}



void turnForTime(double velocity, double time) {
    spinRightDT(-velocity);
    spinLeftDT(velocity);
    wait(time, msec);
    stopDT();
}
























/*spinRightDT(-velocity);
    spinLeftDT(velocity);
    wait(time, msec);
    stopDT();*/