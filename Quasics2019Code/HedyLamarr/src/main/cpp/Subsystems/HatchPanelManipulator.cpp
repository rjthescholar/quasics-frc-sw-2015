// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/HatchPanelManipulator.h"
#include "Commands/SetHatch.h"
#include <iostream>
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

HatchPanelManipulator::HatchPanelManipulator() : frc::Subsystem("HatchPanelManipulator") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    hatchMotor.reset(new frc::Servo(10));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void HatchPanelManipulator::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    SetDefaultCommand(new SetHatch());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void HatchPanelManipulator::Periodic() {
    // Put code here to be run every loop
    //  std::cerr << "   -> Position: " << hatchMotor->GetAngle() << std::endl;
}

void HatchPanelManipulator::Stop() {
    int pos = hatchMotor->GetAngle();
    hatchMotor->SetAngle(pos);
    // std::cerr << "Stopping at " << pos << std::endl;
}

void HatchPanelManipulator::MoveUp(){
    int max = hatchMotor->GetMaxAngle();
    hatchMotor->SetAngle(max);
    // std::cerr << "Moving to maximum " << max << std::endl;
}

void HatchPanelManipulator::MoveDown(){
    int min = hatchMotor->GetMinAngle();
    hatchMotor->SetAngle(min);
    // std::cerr << "Moving to minimum " << min << std::endl;
}

void HatchPanelManipulator::SetHatchAngle(int pos){
    hatchMotor->SetAngle(pos);
}

void HatchPanelManipulator::SetHatchPosition(int pos){
    hatchMotor->SetPosition(pos);
}

int HatchPanelManipulator::GetHatchAngle(){
    int Angle = hatchMotor->GetAngle();
    return Angle;
}

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.
