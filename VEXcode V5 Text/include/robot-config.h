using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller;

extern motor FrontLeft;
extern motor BackLeft;
extern motor FrontRight;
extern motor BackRight;

extern motor IntakeLeft;
extern motor IntakeRight;

extern motor LiftLeft;
extern motor LiftRight;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );