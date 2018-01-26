


#ifndef AUTO_FMS_H
#define AUTO_FMS_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "iostream"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutoFMS: public frc::Command {
public:
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	AutoFMS();
	std::string gameData;

	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
private:

};

#endif
