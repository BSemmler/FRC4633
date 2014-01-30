#include "WPILib.h"
//#include "Drive.h"


using namespace std;

class BuiltinDefaultCode : public IterativeRobot
{
		// Declare Joysticks
        Joystick *rightStick, *leftStick;
        
        // Declare Victor Motor Controllers
        Victor *leftFrontDrive, *rightFrontDrive, *leftRearDrive, *rightRearDrive;
        
        // Declare Driverstation Message window
        DriverStationLCD *LCD;
        
        // Declare Aircompressor
        Compressor *airCompressor;

public:
        BuiltinDefaultCode(void)
        {
                // Initialize Joysticks and their ports
                rightStick = new Joystick(1);
                leftStick = new Joystick(2);
                
                // Initialize Victor Motor Controllers with PWM ports
                leftFrontDrive = new Victor(4);
                rightFrontDrive = new Victor(2);
                leftRearDrive = new Victor(3);
                rightRearDrive = new Victor(1);
                
                // Enable printing messages to Driver station
                LCD = DriverStationLCD::GetInstance();
                
                // Create AirCompressor Object with sensor 
                airCompressor = new Compressor(1,5);          
        }
        
        void RobotInit(void)
        {
        	/* Once the start function is called no further programming
        	 * is required. However if needed the Stop() function can be
        	 * called.                                                   
        	 * */
        	airCompressor->Start();
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
        	//airCompressor->Stop();
        }
        
        void AutonomousPeriodic(void)
        {
        	// Basic motor test code 
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
                
                //airCompressor->Start();
                // Simple Button Drive Forward
                if(rightStick->GetRawButton(3))
                {
                	leftFrontDrive->Set(-1);
                	rightFrontDrive->Set(1);
                	leftRearDrive->Set(-1);
                	rightRearDrive->Set(1);
                }
                
                // Simple Button Drive Backwards
                if(rightStick->GetRawButton(2))
                {
                	leftFrontDrive->Set(1);
                	rightFrontDrive->Set(-1);
                	leftRearDrive->Set(1);
                	rightRearDrive->Set(-1);
                }
                
                // Code to print to the user messages box in the Driver Station
                LCD->PrintfLine(DriverStationLCD::kUser_Line1, "Hello World");
                LCD->Printf(DriverStationLCD::kUser_Line2,1,"Y Left: %f", leftStick->GetY());
                LCD->Printf(DriverStationLCD::kUser_Line3,1,"Y Right: %f", rightStick->GetY());
                LCD->UpdateLCD();
                Wait(0.2); 
        }
};

START_ROBOT_CLASS(BuiltinDefaultCode);
