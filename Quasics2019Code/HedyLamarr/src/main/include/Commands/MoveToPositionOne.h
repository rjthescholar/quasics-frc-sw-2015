/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifdef ENABLE_OLD_ELEVATOR
#pragma once

#include <frc/commands/CommandGroup.h>

class MoveToPositionOne : public frc::CommandGroup {
 public:
  MoveToPositionOne();
};
#endif // ENABLE_OLD_ELEVATOR