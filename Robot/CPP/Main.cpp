#include "WPILib.h"

class BuiltinDefaultCode : public IterativeRobot
{
        Joystick *rightStick, *leftStick;
        Victor *leftFrontDrive, *rightFrontDrive, *leftRearDrive, *rightRearDrive;
        
        
public:
        BuiltinDefaultCode(void)        
        {
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
        {/*
                shooterMotor->Set(-1.0f);
                time.Reset();
                time.Start();*/
        }
        
        void TeleopInit(void)
        {
        }
        
        void DisabledPeriodic(void)
        {
        }
        
        void AutonomousPeriodic(void)
        {/*
                if (time.HasPeriodPassed(10000));
                {
                        diskPusher->Set(1.0f);
                        shootTimer.Reset();
                        shootTimer.Start();
                }
                if (shootTimer.HasPeriodPassed(launchTimer))
                        diskPusher->Set(0.0f);*/
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
