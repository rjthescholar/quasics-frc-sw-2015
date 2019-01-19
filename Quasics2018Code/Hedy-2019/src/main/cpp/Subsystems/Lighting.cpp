// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "Lighting.h"
#include "../RobotMap.h"
#include "Commands/LightingDefault.h"

#include <iostream>

#define ENABLE_LOGGING

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Lighting::Lighting() : frc::Subsystem("Lighting") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	// Serial port to be used for communicating with the Arduino.
	serialPort.reset(new frc::SerialPort(115200, frc::SerialPort::kMXP));

	// As an example, to send a command string out the serial port, you would say:
	//
	//     		serialPort->Write(cmd);
	//
}

void Lighting::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new LightingDefault());

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Lighting::Periodic() {
    // Put code here to be run every loop

}

void Lighting::SendCommand(const char* str) {
#ifdef ENABLE_LOGGING
	std::cerr << "Sending command to Arduino: " << str << std::flush;
#endif

	serialPort->Write(str);
}

void Lighting::SendTestString() {
	SendCommand("Does it work?;\n");
}

void Lighting::WriteOn(){
	SendCommand("On;\n");
}

void Lighting::WriteOff(){
	SendCommand("Off;\n");
}

void Lighting::WriteBlue(){
	SendCommand("Blue;\n");
}

void Lighting::WriteGreen(){
	SendCommand("Green;\n");
}

void Lighting::WriteRed(){
	SendCommand("Red;\n");
}

void Lighting::WriteAuto(){
	SendCommand("Auto;\n");
}

void Lighting::WriteTeleOp(){
	SendCommand("TeleOp;\n");
}

char Lighting::GetColor() {
	auto& driverStation = frc::DriverStation::GetInstance();
	auto ds_alliance = driverStation.GetAlliance();
	switch (ds_alliance) {
		case DriverStation::kRed:
			return 'r';
		case DriverStation::kBlue:
			return 'b';
		default:
			return 'g';
	}
}

char Lighting::GetMode(){
	auto& driverStation = frc::DriverStation::GetInstance();
	if (driverStation.IsAutonomous()) {
			return 'a';
	}
	else if(driverStation.IsOperatorControl()){
			return 't';
	}
	return 'u';
}

void Lighting::Stop(){

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
