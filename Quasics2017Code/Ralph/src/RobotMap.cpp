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
std::shared_ptr<Encoder> RobotMap::driveTrainLeftEncoder;
std::shared_ptr<SpeedController> RobotMap::driveTrainFrontLeft;
std::shared_ptr<SpeedController> RobotMap::driveTrainBackLeft;
std::shared_ptr<Encoder> RobotMap::driveTrainRightEncoder;
std::shared_ptr<SpeedController> RobotMap::driveTrainFrontRight;
std::shared_ptr<SpeedController> RobotMap::driveTrainBackRight;
std::shared_ptr<SpeedController> RobotMap::intakeMotor;
std::shared_ptr<Servo> RobotMap::gearServo;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

#define LEFT_ENCODER_A_CHANNEL	0
#define LEFT_ENCODER_B_CHANNEL	1
#define RIGHT_ENCODER_A_CHANNEL	2
#define RIGHT_ENCODER_B_CHANNEL	3

#define LEFT_FRONT_MOTOR_CHANNEL	0
#define LEFT_BACK_MOTOR_CHANNEL		1
#define RIGHT_FRONT_MOTOR_CHANNEL	2
#define RIGHT_BACK_MOTOR_CHANNEL	3
#define INTAKE_MOTOR_CHANNEL		4
#define GEAR_SERVO_CHANNEL			5

void RobotMap::init() {
    LiveWindow *lw = LiveWindow::GetInstance();

    // Drive train hardware set-up
    driveTrainLeftEncoder.reset(
    		new Encoder(LEFT_ENCODER_A_CHANNEL, LEFT_ENCODER_B_CHANNEL,
    					false, Encoder::k4X));
    driveTrainLeftEncoder->SetDistancePerPulse(inchesPerTick);
    driveTrainLeftEncoder->SetPIDSourceType(PIDSourceType::kRate);
    
    driveTrainRightEncoder.reset(
    		new Encoder(RIGHT_ENCODER_A_CHANNEL, RIGHT_ENCODER_B_CHANNEL,
    					true, Encoder::k4X));
    driveTrainRightEncoder->SetDistancePerPulse(inchesPerTick);
    driveTrainRightEncoder->SetPIDSourceType(PIDSourceType::kRate);
    lw->AddSensor("DriveTrain", "LeftEncoder", driveTrainLeftEncoder);
    lw->AddSensor("DriveTrain", "RightEncoder", driveTrainRightEncoder);

    driveTrainFrontLeft.reset(new Talon(LEFT_FRONT_MOTOR_CHANNEL));
    driveTrainBackLeft.reset(new Talon(LEFT_BACK_MOTOR_CHANNEL));
    driveTrainFrontRight.reset(new Talon(RIGHT_FRONT_MOTOR_CHANNEL));
    driveTrainBackRight.reset(new Talon(RIGHT_BACK_MOTOR_CHANNEL));
    lw->AddActuator("DriveTrain", "FrontLeft", std::static_pointer_cast<Talon>(driveTrainFrontLeft));
    lw->AddActuator("DriveTrain", "BackLeft", std::static_pointer_cast<Talon>(driveTrainBackLeft));
    lw->AddActuator("DriveTrain", "FrontRight", std::static_pointer_cast<Talon>(driveTrainFrontRight));
    lw->AddActuator("DriveTrain", "BackRight", std::static_pointer_cast<Talon>(driveTrainBackRight));
    
    // Intake hardware set-up
    intakeMotor.reset(new Talon(INTAKE_MOTOR_CHANNEL));
    lw->AddActuator("Intake", "Motor", std::static_pointer_cast<Talon>(intakeMotor));

    // Gear-handling hardware set-up
    gearServo.reset(new Servo(GEAR_SERVO_CHANNEL));

    // TODO: Fuel delivery hardware set-up
    // TODO: Climbing hardware set-up

}
