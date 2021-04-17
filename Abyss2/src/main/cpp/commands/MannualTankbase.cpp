/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/MannualTankbase.h"

#include "Robot.h"

MannualTankbase::MannualTankbase() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::tankbase);
}

// Called just before this Command runs the first time
void MannualTankbase::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void MannualTankbase::Execute() {
  double rate = 0.5;
  auto& f310 = Robot::oi.GetJoystick();
  Robot::tankbase.Drive(-f310.GetRawAxis(1) * rate, (f310.GetRawAxis(3) - f310.GetRawAxis(2)) * rate);
}

// Make this return true when this Command no longer needs to run execute()
bool MannualTankbase::IsFinished() { return false; }

// Called once after isFinished returns true
void MannualTankbase::End() {
  Robot::tankbase.Drive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MannualTankbase::Interrupted() {}
