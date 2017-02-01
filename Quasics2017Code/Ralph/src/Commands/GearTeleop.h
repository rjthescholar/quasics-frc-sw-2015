#ifndef GearTeleop_H
#define GearTeleop_H

#include "WPILib.h"
#include "../Subsystems/Gear.h"

class GearTeleop : public Command {
public:
	GearTeleop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	bool previousValue;
};

#endif  // GearTeleop_H