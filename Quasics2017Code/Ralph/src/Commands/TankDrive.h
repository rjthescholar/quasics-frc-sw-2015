#ifndef TankDrive_H
#define TankDrive_H

#include "../Robot.h"

class TankDrive : public Command {
public:
	TankDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TankDrive_H