// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef LIGHTING_H
#define LIGHTING_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Lighting: public frc::Subsystem {
public:
	Lighting();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

	//
	// Functions for manual configuration of lighting in Commands
	enum Alliance {
		eRed = 0, eBlue = 1, eDemo = 2
	};
	enum Mode {
		eIdle = 0, eTeleOp = 1, eAuto = 2, eError = 3, eTest = 4
	};

	void setAlliance(Alliance alliance);
	void setMode(Mode mode);

	//
	// Functions for automatic configuration of lighting in Commands
	// (e.g., in the AutomaticLightingCommand class).
	void updateState(bool force = false);

protected:
	/**
	 * Sends a command to the Arduino, indicating the lighting mode to
	 * be used.
	 *
	 * @param force if false, the command will only be sent if we think that
	 *              the lighting mode has changed from the last time that it
	 *              was sent out.
	 */
	void sendLightingCommand(bool force);

private:
	std::shared_ptr<SerialPort> serialPort_;
	Alliance alliance_ = eDemo;
	Mode mode_ = eIdle;
	const char* lastCommand_ = nullptr;

	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
};

#endif