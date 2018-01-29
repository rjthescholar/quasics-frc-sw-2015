// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<frc::SpeedController> RobotMap::driveBaseFrontLeftMotor;
std::shared_ptr<frc::SpeedController> RobotMap::driveBaseRearLeftMotor;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::driveBaseLeftDriveMotors;
std::shared_ptr<frc::SpeedController> RobotMap::driveBaseFrontRightMotor;
std::shared_ptr<frc::SpeedController> RobotMap::driveBaseRearRightMotor;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::driveBaseRightDriveMotors;
std::shared_ptr<frc::DifferentialDrive> RobotMap::driveBaseDifferentialDrive;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

inline Jaguar* createMotor(int port, const char* const subsystem, const char* const name) {
	Jaguar* const motor = new Jaguar(port);
	motor->SetSubsystem(subsystem);
	motor->SetName(name);
	return motor;
}

void RobotMap::init() {
#if 1
    driveBaseFrontLeftMotor.reset(createMotor(1, "DriveBase", "frontLeftMotor"));
    driveBaseRearLeftMotor.reset(createMotor(1, "DriveBase", "frontLeftMotor"));
    driveBaseFrontRightMotor.reset(createMotor(1, "DriveBase", "frontLeftMotor"));
    driveBaseRearRightMotor.reset(createMotor(1, "DriveBase", "frontLeftMotor"));

    driveBaseLeftDriveMotors = std::make_shared<frc::SpeedControllerGroup>(*driveBaseFrontLeftMotor, *driveBaseRearLeftMotor);
    driveBaseLeftDriveMotors->SetSubsystem("DriveBase");
    driveBaseLeftDriveMotors->SetName("LeftDriveMotors");

    driveBaseRightDriveMotors = std::make_shared<frc::SpeedControllerGroup>(*driveBaseFrontRightMotor, *driveBaseRearRightMotor);
    driveBaseRightDriveMotors->SetSubsystem("DriveBase");
    driveBaseRightDriveMotors->SetName("RightDriveMotors");

    driveBaseDifferentialDrive.reset(new frc::DifferentialDrive(*driveBaseLeftDriveMotors, *driveBaseRightDriveMotors));
    driveBaseDifferentialDrive->SetSubsystem("DriveBase");
    driveBaseDifferentialDrive->SetName("Differential Drive 1");
    driveBaseDifferentialDrive->SetSafetyEnabled(true);
	driveBaseDifferentialDrive->SetExpiration(0.1);
	driveBaseDifferentialDrive->SetMaxOutput(1.0);

#else
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    driveBaseFrontLeftMotor.reset(new frc::Jaguar(1));
    lw->AddActuator("DriveBase", "FrontLeftMotor", std::static_pointer_cast<frc::Jaguar>(driveBaseFrontLeftMotor));
    
    driveBaseRearLeftMotor.reset(new frc::Jaguar(3));
    lw->AddActuator("DriveBase", "RearLeftMotor", std::static_pointer_cast<frc::Jaguar>(driveBaseRearLeftMotor));
    
    driveBaseLeftDriveMotors = std::make_shared<frc::SpeedControllerGroup>(*driveBaseFrontLeftMotor, *driveBaseRearLeftMotor  );
    lw->AddActuator("DriveBase", "LeftDriveMotors", driveBaseLeftDriveMotors);
    
    driveBaseFrontRightMotor.reset(new frc::Jaguar(0));
    lw->AddActuator("DriveBase", "FrontRightMotor", std::static_pointer_cast<frc::Jaguar>(driveBaseFrontRightMotor));
    
    driveBaseRearRightMotor.reset(new frc::Jaguar(2));
    lw->AddActuator("DriveBase", "RearRightMotor", std::static_pointer_cast<frc::Jaguar>(driveBaseRearRightMotor));
    
    driveBaseRightDriveMotors = std::make_shared<frc::SpeedControllerGroup>(*driveBaseFrontRightMotor, *driveBaseRearRightMotor  );
    lw->AddActuator("DriveBase", "RightDriveMotors", driveBaseRightDriveMotors);
    
    driveBaseDifferentialDrive.reset(new frc::DifferentialDrive(*driveBaseLeftDriveMotors, *driveBaseRightDriveMotors));
    lw->AddActuator("DriveBase", "Differential Drive", driveBaseDifferentialDrive);
    driveBaseDifferentialDrive->SetSafetyEnabled(true);
        driveBaseDifferentialDrive->SetExpiration(0.1);
        driveBaseDifferentialDrive->SetMaxOutput(1.0);



    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
#endif

}
