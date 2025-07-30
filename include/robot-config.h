#ifndef ROBOT_CONFIG_H
#define ROBOT_CONFIG_H

#include "vex.h" //definitions depend on definitions in vex.h

//extern: there is a variable, no need to make another variable to reference it
extern vex::brain Brain;
extern vex::controller Controller;
extern vex::competition Competition;

//TODO: group into drivetrain

extern vex::motor LB;
extern vex::motor LM;
extern vex::motor LF;
extern vex::motor RB;
extern vex::motor RM;
extern vex::motor RF;

extern vex::motor_group LeftDrive;
extern vex::motor_group RightDrive;

extern vex::drivetrain Drivetrain;

//extern vex::motor Arm1;
//extern vex::motor Arm2;

//extern vex::inertial InertialSensor;

//extern vex::digital_out DoubleActingPiston;
//extern vex::digital_out SingleActingPiston;

void vexcodeInit();

#endif