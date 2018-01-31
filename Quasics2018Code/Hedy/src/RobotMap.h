// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "WPILib.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<frc::SpeedController> climberWinchMotor;
	static std::shared_ptr<frc::SpeedController> climberScissorLiftMotor;
	static std::shared_ptr<frc::Encoder> driveBaseLeftEncoder;
	static std::shared_ptr<frc::Encoder> driveBaseRightEncoder;
	static std::shared_ptr<frc::SpeedController> driveBaseleftRearMotor;
	static std::shared_ptr<frc::SpeedController> driveBaseleftFrontMotor;
	static std::shared_ptr<frc::SpeedControllerGroup> driveBaseLeftMotors;
	static std::shared_ptr<frc::SpeedController> driveBaserightFrontMotor;
	static std::shared_ptr<frc::SpeedController> driveBaserightRearMotor;
	static std::shared_ptr<frc::SpeedControllerGroup> driveBaseRightMotors;
	static std::shared_ptr<frc::DigitalInput> cubeManipulationLimitSwitch;
	static std::shared_ptr<frc::SpeedController> cubeManipulationleftShoulderMotor;
	static std::shared_ptr<frc::SpeedController> cubeManipulationrightShoulderMotor;
	static std::shared_ptr<frc::SpeedControllerGroup> cubeManipulationShoulderMotors;
	static std::shared_ptr<frc::SpeedController> cubeManipulationleftIntakeMotor;
	static std::shared_ptr<frc::SpeedController> cubeManipulationrightIntakeMotor;
	static std::shared_ptr<frc::SpeedControllerGroup> cubeManipulationIntakeMotors;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

	static void init();
};
#endif
