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
// leftFront            motor         1               
// leftRear             motor         2               
// rightFront           motor         3               
// rightRear            motor         4               
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
    xi = Controller.Axis4.position();
    yi = Controller.Axis3.position();
    //

    //xdrive conversions
    cy1 = yi; cy2 = yi;
    cx1 = -xi; cx2 = xi;
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

    FrontRight.spin(fwd, xo + Controller.Axis1.position(), velocityUnits::pct);
    BackLeft.spin(fwd, xo - Controller.Axis1.position(), velocityUnits::pct);
    //

  }

}
