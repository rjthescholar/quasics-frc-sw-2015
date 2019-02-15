// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "Subsystems/Elevator.h"

#include <iostream>
#include "Commands/AdjustElevator.h"
#include "ConfigurationFlags.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Elevator::Elevator() : frc::Subsystem("Elevator") {
  // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
  elevatorFirmStopLow.reset(new frc::DigitalInput(8));
  elevatorFirmStopHigh.reset(new frc::DigitalInput(7));
  hallEffectLowElevator.reset(new frc::DigitalInput(0));
  hallEffectHighElevator.reset(new frc::DigitalInput(1));
  elevatorMotor.reset(new frc::Spark(5));

  // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
  elevatorMotor->SetInverted(true);
}

void Elevator::InitDefaultCommand() {
#ifndef DISABLE_ELEVATOR_DEFAULTS
  SetDefaultCommand(new AdjustElevator());
#else
  std::cerr << "***** WARNING: No default elevator command configured!\n";
#endif  // DISABLE_ELEVATOR_DEFAULTS

#ifdef DISABLE_ELEVATOR_LIMIT_SWITCHES
  std::cerr << "***** WARNING: Elevator limit switches will be ignored!\n";
#endif

  // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

  // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Elevator::Periodic() {
  // Put code here to be run every loop
}

bool Elevator::atTop() {
#ifdef DISABLE_ELEVATOR_LIMIT_SWITCHES
  return false;
#else
  return elevatorFirmStopHigh->Get();
#endif
}

bool Elevator::atBottom() {
#ifdef DISABLE_ELEVATOR_LIMIT_SWITCHES
  return false;
#else
  return elevatorFirmStopLow->Get();
#endif
}

bool Elevator::atPositionOne() {
  return hallEffectLowElevator->Get();
}

bool Elevator::atPositionTwo() {
  return hallEffectHighElevator->Get();
}

void Elevator::moveUp() {
  elevatorMotor->Set(.65);
}

void Elevator::moveDown() {
  elevatorMotor->Set(-.5);
}

void Elevator::moveSlowlyUp() {
  elevatorMotor->Set(.65);
}

void Elevator::moveSlowlyDown() {
  elevatorMotor->Set(-.5);
}

void Elevator::stop() {
  elevatorMotor->Set(0);
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

// Put methods for controlling this subsystem
// here. Call these from Commands.
