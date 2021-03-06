#ifndef StopShooter_H
#define StopShooter_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

// Stop the shooter apparatus

class StopShooter: public Command
{
public:
	StopShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
