// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

#include <SmartDashboard/SmartDashboard.h>

#include "Commands/MoveInSquare.h"
#include "Commands/Arman.h"
#include "Commands/MoveForTime.h"
#include "Commands/PointTurnForAngle.h"
#include "Commands/GearTeleop.h"
#include "Commands/GearAuto.h"
#include "Commands/MoveForDistance.h"
#include "RobotVariables.h"
#include "Commands/TankDrive.h"
#include "Commands/AuxiliaryCommands.h"
#include "Commands/ClimberAuto.h"

#define simpleInterface
OI::OI() {
    // Process operator interface input here.
    auxStick.reset(new Joystick(AuxStickPort));
    driveStick.reset(new Joystick(DriverStickPort));
    
#ifndef simpleInterface
#else
    SmartDashboard::PutData("Tank Drive", new TankDrive());
    SmartDashboard::PutData("Auxillary Commands", new AuxiliaryCommands());

    SmartDashboard::PutData("Climber Forwards", new ClimberAuto(-1));
    SmartDashboard::PutData("Climber Backwards", new ClimberAuto(1));
    SmartDashboard::PutData("Climber Stop", new ClimberAuto(0));

    SmartDashboard::PutData("Gear door open", new GearAuto (true));
    SmartDashboard::PutData("Gear door closed", new GearAuto (false));
#endif
}

std::shared_ptr<Joystick> OI::getDriveStick() {
   return driveStick;
}

std::shared_ptr<Joystick> OI::getAuxStick() {
   return auxStick;
}
