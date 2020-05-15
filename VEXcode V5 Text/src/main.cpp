/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\BumAndTheSniff                                   */
/*    Created:      Thu May 14 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// cont                 controller    N/A             
// FrontLeft            motor         1               
// BackLeft             motor         2               
// FrontRight           motor         3               
// BackRight            motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  //xinput yinput
  float xi; float yi;

  //converted x/y
  float cx1; float cx2; float cy1; float cy2;

  //xoutput youtput
  float xo; float yo;

  //multipliers
  float spin;

  while (true)
  {

    //get joystick values
    yi = Controller.Axis4.position();
    xi = Controller.Axis3.position();
    //

    //xdrive conversions
    cy1 = yi; cy2 = yi;
    cx1 = xi; cx2 = -xi;
    //

    //drive outputs
    yo = (cy1 + cx1) / 2;
    xo = (cy2 + cx2) / 2;
    //

    //spin multiplier
    spin = (100 - abs(Controller.Axis1.position()));
    //

    //apply drive motor control
    FrontLeft.spin(fwd, yo - Controller.Axis1.position(), velocityUnits::pct);
    BackRight.spin(fwd, yo + Controller.Axis1.position(), velocityUnits::pct);

    FrontRight.spin(fwd, xo - Controller.Axis1.position(), velocityUnits::pct);
    BackLeft.spin(fwd, xo + Controller.Axis1.position(), velocityUnits::pct);
    //

    //debug temps
    Brain.Screen.clearScreen(color::black);
    Brain.Screen.setCursor(1,0);
    Brain.Screen.print("FrontLeft: %f degrees",FrontLeft.temperature(temperatureUnits::celsius));
    Brain.Screen.setCursor(2,0);
    Brain.Screen.print("BackLeft: %f degrees",BackLeft.temperature(temperatureUnits::celsius));
    Brain.Screen.setCursor(3,0);
    Brain.Screen.print("FrontRight: %f degrees",FrontRight.temperature(temperatureUnits::celsius));
    Brain.Screen.setCursor(4,0);
    Brain.Screen.print("BackRight: %f degrees",BackRight.temperature(temperatureUnits::celsius));
    //

    task::sleep(100);

  }

}
