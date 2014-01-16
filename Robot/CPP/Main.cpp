#include "WPILib.h"

class BuiltinDefaultCode : public IterativeRobot
{
        Joystick *rightStick, *leftStick;
        Victor *leftFrontDrive, *rightFrontDrive, *leftRearDrive, *rightRearDrive;
        
        
public:
        BuiltinDefaultCode(void)        
        {
                // Declare Motor Controllers(Victor) and Joysticks
                rightStick = new Joystick(1);
                leftStick = new Joystick(2);
                
                leftFrontDrive = new Victor(4);
                rightFrontDrive = new Victor(2);
                leftRearDrive = new Victor(3);
                rightRearDrive = new Victor(1);
        }
        
        void RobotInit(void)
        {
        }
        
        void DisabledInit(void)
        {
        }
        
        void AutonomousInit(void)
        {
        }
        
        void TeleopInit(void)
        {
        }
        
        void DisabledPeriodic(void)
        {
        }
        
        void AutonomousPeriodic(void)
        {
        }        
        
        void TeleopPeriodic(void)
        {
                //Drive code
                leftFrontDrive->Set(leftStick->GetY());
                rightFrontDrive->Set(-1 * rightStick->GetY());
                leftRearDrive->Set(leftStick->GetY());
                rightRearDrive->Set(-1 * rightStick->GetY());
        }
};

START_ROBOT_CLASS(BuiltinDefaultCode);
