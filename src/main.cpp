/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       katherinezeng                                             */
/*    Created:      5/27/2025, 10:30:19 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include <cmath>
#include "vex.h"
#include "robot-config.h"
#include "autons.h"
#include "auton-selector.h"
#include "arm.h"
#include "functions.h"

using namespace vex;

// A global instance of competition
competition Competition;


// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  vexcodeInit();
  displayAutonSelector();
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  
  switch (getSelectedAuton()) {
    case 0:
      rightAuton();
      break;
    case 1:
      leftAuton();
      break;
    case 2:
      skillsAuton();
      break;
    default:
      Brain.Screen.print("No valid auton selected!");
      break;
  }
 


}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {

  while (true) {
    // ========== DRIVE CONTROL ========== //
    double left_inp = Controller.Axis3.position();
    double right_inp = Controller.Axis2.position();

    //take controller input1(fwd) and set LeftDrive to spin at that speed as a percent of its total kph

    //deadzone is set to 5 + or -
    if(fabs(left_inp) > 5){
      LeftDrive.spin(directionType::fwd, left_inp, velocityUnits::pct);
    } else {
      LeftDrive.stop(coast);
    }
    if(fabs(right_inp) > 5){ //take controller input2 same as input1 but for the RightDrive deadzone is the same

      RightDrive.spin(directionType::fwd, right_inp, velocityUnits::pct);
    } else {
      RightDrive.stop(coast);
    }

  //i beg you!!! dont waste cpu cycles T-T
  task::sleep(20); //20ms rest to let the cpu finalize processes.
}

}
//
// Main will set up the competition functions and callbacks.
//
int main() {
  vexcodeInit();
  pre_auton();

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  //Competition.test_auton();
  //Competition.test_driver();


  while (true) {
    wait(100, msec); //sorry... dont want to overwhelm the robot lml.you HAVE 100 MILS TO SPARE
  }
}
