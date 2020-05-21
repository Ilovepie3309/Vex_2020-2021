/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Liam Schultz                                              */
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

  //xoutput youtput
  float xo; float yo;

  //multipliers
  float spin;

  //diagmulti/smoothing
  float smooth;

  //speed vals
  float intakeSpeed = 100;

  while (true)
  {

    //get joystick values
    yi = Controller.Axis4.position();
    xi = Controller.Axis3.position();
    //

    //converted drive values
    yo = (yi + xi) / 2;
    xo = (yi - xi) / 2;
    //

    //spin multiplier
    spin = (100 - abs(Controller.Axis1.position()));
    //

    //smoothing multiplier
    smooth = fabs(fabs(yi) - fabs(xi)) + 100;

    xo = (xo * smooth)/100;
    yo = (yo * smooth)/100;

    xo /= 2;//simplify
    yo /= 2;
    //

    //apply drive motor control
    FrontLeft.spin(fwd, yo + Controller.Axis1.position(), velocityUnits::pct);
    BackRight.spin(fwd, yo - Controller.Axis1.position(), velocityUnits::pct);

    FrontRight.spin(fwd, xo + Controller.Axis1.position(), velocityUnits::pct);
    BackLeft.spin(fwd, xo - Controller.Axis1.position(), velocityUnits::pct);
    //

    //intake control
    if(Controller.ButtonL1.pressing())
    {

      IntakeLeft.spin(fwd, -intakeSpeed, velocityUnits::pct);
      IntakeRight.spin(fwd, -intakeSpeed, velocityUnits::pct);

    }
    else if(Controller.ButtonL2.pressing())
    {

      IntakeLeft.spin(fwd, intakeSpeed, velocityUnits::pct);
      IntakeRight.spin(fwd, intakeSpeed, velocityUnits::pct);

    }
    //

    //lift control
    if(Controller.ButtonR1.pressing())
    {

      LiftLeft.spin(fwd, intakeSpeed, velocityUnits::pct);
      LiftRight.spin(fwd, intakeSpeed, velocityUnits::pct);

    }
    else if(Controller.ButtonR2.pressing())
    {

      LiftLeft.spin(fwd, -intakeSpeed, velocityUnits::pct);
      LiftRight.spin(fwd, -intakeSpeed, velocityUnits::pct);

    }
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
