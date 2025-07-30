#include "vex.h"
#include "robot-config.h"

int selectedAuton = 0;

const char* autonNames[] = { "Right Auton", "Left Auton", "Skills"};
const int autonCount = 3;

using namespace vex;

int getSelectedAuton() {
  return selectedAuton;
}

void displayAutonSelector() {
  while (true) {
  
    if (Controller.ButtonLeft.pressing()) {
      selectedAuton = (selectedAuton - 1 + autonCount) % autonCount;
    }
    if (Controller.ButtonRight.pressing()) {
      selectedAuton = (selectedAuton + 1) % autonCount;
    }

    if (Controller.ButtonX.pressing()) {
      vex::task::sleep(600);
      if (Controller.ButtonX.pressing()) {
        Controller.rumble("..");
        break;
      }
    }

    Controller.Screen.clearScreen();
    Controller.Screen.setCursor(1, 1);
    Controller.Screen.print("Auton: %s", autonNames[selectedAuton]);
    task::sleep(300);

  }
}