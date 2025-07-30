//These prevent header files from being included multiple times
#ifndef FUNCTIONS_H //if header file is not defined
#define FUNCTIONS_H // define it

double inchesToDegrees(double inches);
void setDTPosition(double inches);
void spinDT(double velocity);
void stopDT();
void spinRightDT(double velocity);
void spinLeftDT(double velocity);

void spinDTPosition(double velocity, double targetInches);
void turnForTime(double velocity, double time);


#endif //end of define