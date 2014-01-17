#include "WPILib.h"

class BuiltinDefaultCode : public IterativeRobot
{
        Joystick *rightStick, *leftStick;
        Victor *leftFrontDrive, *rightFrontDrive, *leftRearDrive, *rightRearDrive;
        DriverStationLCD *LCD;
        
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
                
                LCD = DriverStationLCD::GetInstance();
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
        		leftFrontDrive->Set(1);
        		leftRearDrive->Set(1);
        	
        		rightRearDrive->Set(1);
        		rightFrontDrive->Set(1);
        }
        
        void TeleopPeriodic(void)
        {
                //Drive code
                leftFrontDrive->Set(-1 * leftStick->GetY());
                rightFrontDrive->Set(rightStick->GetY());
                leftRearDrive->Set(-1 * leftStick->GetY());
                rightRearDrive->Set(rightStick->GetY());
                
                LCD->PrintfLine(DriverStationLCD::kUser_Line1, "Hello World");
                LCD->UpdateLCD();
                Wait(0.2); 
        }
};

START_ROBOT_CLASS(BuiltinDefaultCode);
