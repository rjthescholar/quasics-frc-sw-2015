/*
 * Gear.h
 *
 *  Created on: Jan 27, 2017
 *      Author: axf105
 */

#ifndef SRC_SUBSYSTEMS_GEAR_H_
#define SRC_SUBSYSTEMS_GEAR_H_

#include <WPILib.h>

// CODE_REVIEW(mjh): Document what this class actually does.
class Gear : public Subsystem {
private:
	// CODE_REVIEW(mjh): These constants should probably be "const static",
	// rather than just "const".
	const float openValue = .5;
	const float closeValue = .8;
	const float kickerIn = .1;
	const float kickerOut = .9;

	std::shared_ptr<Servo> gearServo;
	std::shared_ptr<Servo> gearServoKicker;
	bool doorOpen;
	bool kickerExtended;

public:
	Gear();
	virtual ~Gear();

	void Set(bool isOpen);
	void SetKicker(bool isExtended);

	// CODE_REVIEW(mjh): These methods should be declared as "const".
	bool Get();
	bool GetKicker();
	double GetPosition();

};

#endif
