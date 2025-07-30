//#pragma once

/* These prevent header files from being included multiple times*/
#ifndef PID_H //if header file is not defined
#define PID_H // define it


void drivePID(double targetInches, double kP, double kI, double kD);
void turnPID(double targetAngle, double kP, double kI, double kD);


#endif //end of define