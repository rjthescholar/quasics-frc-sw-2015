#include "FuelExhaustGate.h"
#include "../RobotMap.h"
#include "WPILib.h"

#define OPEN_VAL		.81
#define CLOSED_VAL		0.19

FuelExhaustGate::FuelExhaustGate() :
		Subsystem("FuelExhaustGate"), outputActuator(RobotMap::outputActuator), doorOpen(
		false) {
	outputActuator->Set(CLOSED_VAL);
}

FuelExhaustGate::~FuelExhaustGate() {
	outputActuator = nullptr;
	outputActuator2 = nullptr;
}

void FuelExhaustGate::Set(bool isOpen) {
	doorOpen = isOpen;
	if (isOpen) {
		outputActuator->Set(OPEN_VAL);
		SmartDashboard::PutBoolean("Gate Up", true);
	} else {
		outputActuator->Set(CLOSED_VAL);
		SmartDashboard::PutBoolean("Gate Up", false);
	}
}

bool FuelExhaustGate::Get() const {
	return doorOpen;
}

FuelExhaustGate::DoorState FuelExhaustGate::GetDoorStatus() const {
	auto position = outputActuator->Get();
	if (position == OPEN_VAL) {
		return eOpen;
	} else if (position == CLOSED_VAL) {
		return eClosed;
	} else {
		return eAjar;
	}
}