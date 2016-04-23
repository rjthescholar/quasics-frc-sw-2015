// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveTrain: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<SpeedController> frontLeft;
	std::shared_ptr<SpeedController> backLeft;
	std::shared_ptr<SpeedController> frontRight;
	std::shared_ptr<SpeedController> backRight;
	std::shared_ptr<Encoder> leftEncoder;
	std::shared_ptr<Encoder> rightEncoder;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	DriveTrain();
	void InitDefaultCommand();

	//Motor Output
	void SetLeftPower	(double power);		// -1 - 1, Sets the power of the left side motors
	void SetRightPower	(double power); 	// -1 - 1, Sets the power of the right side motors
	void Stop ();							// Stop Moving


	//NavX
	//Data Types
	enum GyroAxis {
		kPitch, kYaw, kRoll, kYawContinuous
	};
	enum AccelerometerAxis {
		kX, kY, kZ
	};

	//Reading
	double GetNavXHeading 		(GyroAxis whichAxis);					// Reads the NavX gyroscopes
	double GetNavXAcceleration	(AccelerometerAxis whichAxis);			// Reads NavX Accelerometers
	double GetNavXDisplacement	(AccelerometerAxis whichAxis);			// Reads NavX Displacement

	//Reset
};

#endif
