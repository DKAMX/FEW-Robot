/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>

class Tankbase : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX leftfront {1};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX leftrear {2};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX rightfront {3};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX rightrear {4};
  frc::DifferentialDrive basedrive {leftfront, rightfront};

 public:
  Tankbase();
  void InitDefaultCommand() override;
  void Drive(double left, double right);
};
