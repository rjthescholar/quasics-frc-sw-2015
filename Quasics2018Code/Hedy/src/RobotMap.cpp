// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating auto-generated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

#include "EncoderVariables.h"

#include <DigitalInput.h>
#include <Encoder.h>
#include <PWMVictorSPX.h>
#include <Spark.h>
#include <SpeedController.h>
#include <SpeedControllerGroup.h>

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<frc::SpeedController> RobotMap::climberLinearSlideLinearSlideMotor;
std::shared_ptr<frc::SpeedController> RobotMap::climberWinchWinchMotor;
std::shared_ptr<frc::Encoder> RobotMap::driveBaseLeftEncoder;
std::shared_ptr<frc::Encoder> RobotMap::driveBaseRightEncoder;
std::shared_ptr<frc::SpeedController> RobotMap::driveBaseLeftFrontMotor;
std::shared_ptr<frc::SpeedController> RobotMap::driveBaseLeftRearMotor;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::driveBaseLeftMotors;
std::shared_ptr<frc::SpeedController> RobotMap::driveBaseRightFrontMotor;
std::shared_ptr<frc::SpeedController> RobotMap::driveBaseRightRearMotor;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::driveBaseRightMotors;
std::shared_ptr<frc::SpeedController> RobotMap::cubeManipulationleftShoulderMotor;
std::shared_ptr<frc::SpeedController> RobotMap::cubeManipulationrightShoulderMotor;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::cubeManipulationShoulderMotors;
std::shared_ptr<frc::SpeedController> RobotMap::cubeIntakeLeftIntakeMotor;
std::shared_ptr<frc::SpeedController> RobotMap::cubeIntakeRightIntakeMotor;
std::shared_ptr<frc::SpeedControllerGroup> RobotMap::cubeIntakeIntakeMotors;
std::shared_ptr<frc::DigitalInput> RobotMap::cubeIntakeLimitSwitch;
std::shared_ptr<frc::ADXRS450_Gyro> RobotMap::gyroADXRSAnalogGyro1;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

// These are "helper functions", intended to work around some problems in the code
// that Robot Builder currently generates.  (It's still generating code like it
// did for 2017 and earlier, but things are different in 2018.)
template <class Widget>
inline void setNameAndSubsystem(Widget& w, const char* const subsystem, const char* const name) {
	w.SetSubsystem(subsystem);
	w.SetName(name);
}

template <class Controller>
inline std::shared_ptr<Controller> createMotor(int port, const char* const subsystem, const char* const name) {
	std::shared_ptr<Controller> const motor(new Controller(port));
	setNameAndSubsystem(*motor, subsystem, name);
	return motor;
}
inline std::shared_ptr<frc::SpeedControllerGroup> createSpeedControllerGroup(frc::SpeedController& motor1, frc::SpeedController& motor2, const char* const subsystem, const char* const name) {
	std::shared_ptr<frc::SpeedControllerGroup> speedControllerGroup(new frc::SpeedControllerGroup(motor1, motor2));
	setNameAndSubsystem(*speedControllerGroup, subsystem, name);
	return speedControllerGroup;
}
inline std::shared_ptr<frc::Encoder> createEncoder(
		int channelA, int channelB,
		bool reverseDirection, double distancePerPulse,
		frc::PIDSourceType sourceType,
		const char* const subsystem, const char* const name)
{
	std::shared_ptr<frc::Encoder> encoder(new frc::Encoder(channelA, channelB, reverseDirection));
	encoder->SetDistancePerPulse(distancePerPulse);
	encoder->SetPIDSourceType(sourceType);
	setNameAndSubsystem(*encoder, subsystem, name);
	return encoder;
}

// #define USE_ROBOT_BUILDER_INIT

void RobotMap::init() {
// #define USE_ROBOT_BUILDER_INIT
#if !defined(USE_ROBOT_BUILDER_INIT)
	// NOTE: This code needs to be kept in sync with the stuff in the "#else" clause, below.
	// This version works around some out-dated code produced by Robot Builder 2018, but if
	// we ever make updates in RobotBuilder and re-export the C++ code, it will be out of
	// sync with those changes, and will have to be updated manually.
	//
	// (On the other hand, this version of the code won't produce warnings when compiled,
	// which means that it's easier to see what's *really* wrong when the compiler finds
	// something funky.)

	//
	// Drive base setup
	driveBaseLeftEncoder = createEncoder(
			0, 1, true, DRIVE_TRAIN_INCHES_PER_TICK,
			frc::PIDSourceType::kRate, "DriveBase", "Left Encoder");
	driveBaseRightEncoder = createEncoder(
			2, 3, false, DRIVE_TRAIN_INCHES_PER_TICK,
			frc::PIDSourceType::kRate, "DriveBase", "Right Encoder");

	driveBaseRightFrontMotor = createMotor<frc::PWMVictorSPX>(0, "Drive Base", "rightFrontMotor");
	driveBaseRightRearMotor = createMotor<frc::PWMVictorSPX>(1, "Drive Base", "rightRearMotor");
    driveBaseLeftFrontMotor = createMotor<frc::PWMVictorSPX>(2, "Drive Base", "leftFrontMotor");
    driveBaseLeftRearMotor = createMotor<frc::PWMVictorSPX>(3, "Drive Base", "leftRearMotor");

    driveBaseLeftMotors = createSpeedControllerGroup(
    		*driveBaseLeftFrontMotor, *driveBaseLeftRearMotor,
			"DriveBase", "LeftDriveMotors");
    driveBaseRightMotors = createSpeedControllerGroup(
    		*driveBaseRightFrontMotor, *driveBaseRightRearMotor,
			"DriveBase", "RightDriveMotors");

    //
    // Cube manipulation setup
    cubeManipulationleftShoulderMotor = createMotor<frc::Spark>(4, "CubeManipulation", "leftShoulderMotor");
    cubeManipulationrightShoulderMotor = createMotor<frc::Spark>(5, "CubeManipulation", "rightShoulderMotor");

    cubeManipulationShoulderMotors = createSpeedControllerGroup(
    		*cubeManipulationleftShoulderMotor, *cubeManipulationrightShoulderMotor,
			"CubeManipulation", "ShoulderMotors");

    //
    // Cube intake setup
    cubeIntakeLeftIntakeMotor = createMotor<frc::Spark>(6, "CubeIntake", "leftIntakeMotor");
    cubeIntakeRightIntakeMotor = createMotor<frc::Spark>(7, "CubeIntake", "rightIntakeMotor");

    cubeIntakeIntakeMotors = createSpeedControllerGroup(
    		*cubeIntakeLeftIntakeMotor, *cubeIntakeRightIntakeMotor,
			"CubeIntake", "IntakeMotors");

    cubeIntakeLimitSwitch.reset(new frc::DigitalInput(4));
    setNameAndSubsystem(*cubeIntakeLimitSwitch, "CubeIntake", "Limit Switch");

    //
    // Climber setup
    climberWinchWinchMotor = createMotor<frc::PWMVictorSPX>(8, "Climber", "Winch Motor");
    climberLinearSlideLinearSlideMotor = createMotor<frc::PWMVictorSPX>(9, "Climber", "Scissor Lift  Motor");

    //
    // Gyro set-up
    gyroADXRSAnalogGyro1.reset(new ADXRS450_Gyro());
    // gyroADXRSAnalogGyro1->SetSensitivity(0.007);
    setNameAndSubsystem(*gyroADXRSAnalogGyro1, "GyroADXRS", "AnalogGyro 1");

#else
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    climberLinearSlideLinearSlideMotor.reset(new frc::Spark(9));
    lw->AddActuator("ClimberLinearSlide", "Linear Slide Motor", std::static_pointer_cast<frc::Spark>(climberLinearSlideLinearSlideMotor));
    
    climberWinchWinchMotor.reset(new frc::Spark(8));
    lw->AddActuator("ClimberWinch", "Winch Motor", std::static_pointer_cast<frc::Spark>(climberWinchWinchMotor));
    
    driveBaseLeftEncoder.reset(new frc::Encoder(0, 1, true, frc::Encoder::k4X));
    lw->AddSensor("DriveBase", "Left Encoder", driveBaseLeftEncoder);
    driveBaseLeftEncoder->SetDistancePerPulse(0.05235987755);
    driveBaseLeftEncoder->SetPIDSourceType(frc::PIDSourceType::kRate);
    driveBaseRightEncoder.reset(new frc::Encoder(2, 3, false, frc::Encoder::k4X));
    lw->AddSensor("DriveBase", "Right Encoder", driveBaseRightEncoder);
    driveBaseRightEncoder->SetDistancePerPulse(0.05235987755);
    driveBaseRightEncoder->SetPIDSourceType(frc::PIDSourceType::kRate);
    driveBaseLeftFrontMotor.reset(new frc::PWMVictorSPX(2));
    lw->AddActuator("DriveBase", "Left Front Motor", std::static_pointer_cast<frc::PWMVictorSPX>(driveBaseLeftFrontMotor));
    
    driveBaseLeftRearMotor.reset(new frc::PWMVictorSPX(3));
    lw->AddActuator("DriveBase", "Left Rear Motor", std::static_pointer_cast<frc::PWMVictorSPX>(driveBaseLeftRearMotor));
    
    driveBaseLeftMotors = std::make_shared<frc::SpeedControllerGroup>(*driveBaseLeftFrontMotor, *driveBaseLeftRearMotor  );
    lw->AddActuator("DriveBase", "Left Motors", driveBaseLeftMotors);
    
    driveBaseRightFrontMotor.reset(new frc::PWMVictorSPX(0));
    lw->AddActuator("DriveBase", "Right Front Motor", std::static_pointer_cast<frc::PWMVictorSPX>(driveBaseRightFrontMotor));
    
    driveBaseRightRearMotor.reset(new frc::PWMVictorSPX(1));
    lw->AddActuator("DriveBase", "Right Rear Motor", std::static_pointer_cast<frc::PWMVictorSPX>(driveBaseRightRearMotor));
    
    driveBaseRightMotors = std::make_shared<frc::SpeedControllerGroup>(*driveBaseRightFrontMotor, *driveBaseRightRearMotor  );
    lw->AddActuator("DriveBase", "Right Motors", driveBaseRightMotors);
    
    cubeManipulationleftShoulderMotor.reset(new frc::Spark(4));
    lw->AddActuator("CubeManipulation", "leftShoulderMotor", std::static_pointer_cast<frc::Spark>(cubeManipulationleftShoulderMotor));
    
    cubeManipulationrightShoulderMotor.reset(new frc::Spark(5));
    lw->AddActuator("CubeManipulation", "rightShoulderMotor", std::static_pointer_cast<frc::Spark>(cubeManipulationrightShoulderMotor));
    
    cubeManipulationShoulderMotors = std::make_shared<frc::SpeedControllerGroup>(*cubeManipulationleftShoulderMotor, *cubeManipulationrightShoulderMotor  );
    lw->AddActuator("CubeManipulation", "ShoulderMotors", cubeManipulationShoulderMotors);
    
    cubeIntakeLeftIntakeMotor.reset(new frc::Spark(6));
    lw->AddActuator("CubeIntake", "Left Intake Motor", std::static_pointer_cast<frc::Spark>(cubeIntakeLeftIntakeMotor));
    
    cubeIntakeRightIntakeMotor.reset(new frc::Spark(7));
    lw->AddActuator("CubeIntake", "Right Intake Motor", std::static_pointer_cast<frc::Spark>(cubeIntakeRightIntakeMotor));
    
    cubeIntakeIntakeMotors = std::make_shared<frc::SpeedControllerGroup>(*cubeIntakeLeftIntakeMotor, *cubeIntakeRightIntakeMotor  );
    lw->AddActuator("CubeIntake", "IntakeMotors", cubeIntakeIntakeMotors);
    
    cubeIntakeLimitSwitch.reset(new frc::DigitalInput(4));
    lw->AddSensor("CubeIntake", "Limit Switch", cubeIntakeLimitSwitch);
    
    gyroADXRSAnalogGyro1.reset(new frc::ADXRS450_Gyro());
    lw->AddSensor("GyroADXRS", "AnalogGyro 1", gyroADXRSAnalogGyro1);
    // gyroADXRSAnalogGyro1->SetSensitivity(0.007);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
#endif

    // NOTE: This *should* be done by the Robot Builder code (and duplicated in the
    // manual init above).  However, it looks like there's a bug in Robot Builder.
    // (Shocking, I know.... :-)
    cubeIntakeRightIntakeMotor->SetInverted(true);
    cubeManipulationrightShoulderMotor->SetInverted(true);
}
