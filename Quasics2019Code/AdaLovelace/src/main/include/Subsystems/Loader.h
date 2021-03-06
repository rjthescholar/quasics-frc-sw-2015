// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef LOADER_H
#define LOADER_H
#include "frc/commands/Subsystem.h"
#include "frc/WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Loader: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<frc::SpeedController> frontLoader;
	std::shared_ptr<frc::SpeedController> backLoader;
	std::shared_ptr<frc::SpeedControllerGroup> loaderMotors;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	Loader();
	void InitDefaultCommand() override;
	void Periodic() override;
	void SetLoaderMotors(double speed);
	class TestAccess {
		friend class Loader;
		private:
		  Loader &loader;
		  TestAccess(Loader &loader) : loader(loader) {}
		public:
		  frc::Subsystem &getSubsystem() { return loader; }
		  frc::SpeedController &getFrontMotor() { return *loader.frontLoader; }
		  frc::SpeedController &getBackMotor() { return *loader.backLoader; }
	};
	TestAccess getTestAccess() { return TestAccess(*this); }
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS


};

#endif
