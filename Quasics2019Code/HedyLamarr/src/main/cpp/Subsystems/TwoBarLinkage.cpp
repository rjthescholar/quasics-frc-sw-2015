  // RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Subsystems/TwoBarLinkage.h"
#include "Commands/LinkageControl.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

TwoBarLinkage::TwoBarLinkage() : frc::Subsystem("TwoBarLinkage") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    rightLinkageMotor.reset(new frc::Spark(7));
    leftLinkageMotor.reset(new frc::Spark(8));

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    rightLinkageMotor->SetInverted(true);
}

void TwoBarLinkage::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    SetDefaultCommand(new LinkageControl());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void TwoBarLinkage::Periodic() {
    // Put code here to be run every loop

}

void TwoBarLinkage::LinkageUp() {
    rightLinkageMotor->Set(.45);
    leftLinkageMotor->Set(.45);
}

void TwoBarLinkage::LinkageDown() {
    rightLinkageMotor->Set(-.45);
    leftLinkageMotor->Set(-.45);
}

void TwoBarLinkage::Stop(){
    rightLinkageMotor->Set(0);
    leftLinkageMotor->Set(0);
}

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CMDPIDGETTERS


// Put methods for controlling this subsystem
// here. Call these from Commands.
