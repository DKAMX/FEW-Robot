/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/PIDSubsystem.h>

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>

class PIDtest : public frc::PIDSubsystem {
 public:
  PIDtest();
  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;
  void InitDefaultCommand() override;
  void Reset();
  void SetHeading(double angle);

 private:
  ctre::phoenix::sensors::PigeonIMU gyro {30};
};
