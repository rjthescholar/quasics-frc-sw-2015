#include "GearTeleop.h"
#include "../Robot.h"
#include "../RobotVariables.h"
#include <iostream>

GearTeleop::GearTeleop() {
	Requires(Robot::gear.get());
	previousValue = false;
	counter = 0;
	isOpening = false;
}

void GearTeleop::Initialize() {
	previousValue = false;
	counter = 0;
	isOpening = false;
}

// Called repeatedly when this Command is scheduled to run
void GearTeleop::Execute() {
	if (!Robot::oi->getAuxStick()->GetRawButton(GearActuatorButton)
			&& previousValue) {
		Robot::gear->Set(!Robot::gear->Get());
		Robot::gear->SetKicker(false);

		if (Robot::gear->Get()) {
			isOpening = true;
		}
	}

	if (isOpening && counter < 25) {
		counter++;
	} else if (isOpening && counter >= 25) {
		Robot::gear->SetKicker(true);
		counter = 0;
		isOpening = false;
	}
	SmartDashboard::PutBoolean("GateOpen", Robot::gear->Get());
	previousValue = Robot::oi->getAuxStick()->GetRawButton(GearActuatorButton);
}

// Make this return true when this Command no longer needs to run execute()
bool GearTeleop::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void GearTeleop::End() {
	previousValue = false;
	counter = 0;
	isOpening = false;

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearTeleop::Interrupted() {
	previousValue = false;
	counter = 0;
	isOpening = false;
}
