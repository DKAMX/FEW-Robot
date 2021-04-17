/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Tankbase.h"

#include "commands/MannualTankbase.h"

Tankbase::Tankbase() : Subsystem("ExampleSubsystem") {}

void Tankbase::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new MannualTankbase());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Tankbase::Drive(double move, double turn) {
  basedrive.ArcadeDrive(move, turn);
}