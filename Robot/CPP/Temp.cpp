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
        
        Solenoid *TestSolenoid;
        
        Relay *Relay1;
        Relay *Relay2;
        Relay *Relay3;
        Relay *Relay4;
        Relay *Relay5;
        Relay *Relay6;
        Relay *Relay7;
        Relay *Relay8;

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
                airCompressor = new Compressor(1,8);     
                airCompressor->Start();
                
                //TestSolenoid = new Solenoid(7);
                Relay1 = new Relay(1);
                Relay2 = new Relay(2);
                Relay3 = new Relay(3);
                Relay4 = new Relay(4);
                Relay5 = new Relay(5);
                Relay6 = new Relay(6);
                Relay7 = new Relay(7);
                Relay8 = new Relay(8);
        }
        
        void RobotInit(void)
        {
        	/* Once the start function is called no further programming
        	 * is required. However if needed the Stop() function can be
        	 * called.                                                   
        	 * */
        	
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
        	//TestSolenoid->Set(true);
        }
        
        void TeleopPeriodic(void)
        {
        	
        		Relay1->Set(Relay::kOn);
        		Relay2->Set(Relay::kOn);
        		Relay3->Set(Relay::kOn);
        		Relay4->Set(Relay::kOn);
        		Relay5->Set(Relay::kOn);
        		Relay6->Set(Relay::kOn);
        		Relay7->Set(Relay::kOn);
        		Relay8->Set(Relay::kOn);
                //Drive code
                leftFrontDrive->Set(-1 * leftStick->GetY());
                rightFrontDrive->Set(rightStick->GetY());
                leftRearDrive->Set(-1 * leftStick->GetY());
                rightRearDrive->Set(rightStick->GetY());
                
                // airCompressor->Start();
                // Simple Button Drive Forward
                if(rightStick->GetRawButton(3))
                {
                	leftFrontDrive->Set(-1);
                	rightFrontDrive->Set(1);
                	leftRearDrive->Set(-1);
                	rightRearDrive->Set(1);
                }
                
                // Simple Button Drive Backwards
                else if(rightStick->GetRawButton(2))
                {
                	leftFrontDrive->Set(1);
                	rightFrontDrive->Set(-1);
                	leftRearDrive->Set(1);
                	rightRearDrive->Set(-1);
                }
                else if(leftStick->GetRawButton(4))
                {
                	leftFrontDrive->Set(-1);
                	leftRearDrive->Set(-1);
                }
                else if(rightStick->GetRawButton(5))
                {
                	rightFrontDrive->Set(1);
                	rightRearDrive->Set(1);
                }
                
                // Code to print to the user messages box in the Driver Station
                LCD->PrintfLine(DriverStationLCD::kUser_Line1, "Hello World");
                LCD->Printf(DriverStationLCD::kUser_Line2,1,"Y Left: %f", leftStick->GetY());
                LCD->Printf(DriverStationLCD::kUser_Line3,1,"Y Right: %f", rightStick->GetY());
               // LCD->Printf(DriverStationLCD::kUser_Line4,1,"y Right: %f", rightFrontDrive->Get());
                LCD->UpdateLCD();
                Wait(0.2); 
        }
};

START_ROBOT_CLASS(BuiltinDefaultCode);
