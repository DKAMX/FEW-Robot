/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoTankbase/AutoTurningLeft90.h"

#include "Robot.h"

AutoTurningLeft90::AutoTurningLeft90() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::tankbase);
  Requires(&Robot::pidtest);
}

// Called just before this Command runs the first time
void AutoTurningLeft90::Initialize() {
  Robot::pidtest.Reset();
}

// Called repeatedly when this Command is scheduled to run
void AutoTurningLeft90::Execute() {
  double angle = 90;
  while (Robot::pidtest.ReturnPIDInput() <= angle) {
    double diff = Robot::pidtest.ReturnPIDInput() - angle;
    double turn = diff * 0.0125;
    Robot::tankbase.Drive(0.0, turn);
  }
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurningLeft90::IsFinished() { return false; }

// Called once after isFinished returns true
void AutoTurningLeft90::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurningLeft90::Interrupted() {}
