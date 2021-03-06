/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#ifdef ENABLE_OLD_ELEVATOR
#pragma once

#include <frc/commands/Command.h>

class ElevatorToPositionOne : public frc::Command {
 public:
  ElevatorToPositionOne();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  bool needs_to_switch = false;
  bool moving_down = false;
};
#endif // ENABLE_OLD_ELEVATOR