/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

 private:
  //底盘配置 drive主动 slave从动
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX leftdrive {1};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX leftslave {2};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX rightdrive {3};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX rightslave {4};
  frc::DifferentialDrive basedrive {leftdrive, rightdrive};
  //传感器配置 niaccel内置加速度计 ctreimu陀螺仪
  frc::BuiltInAccelerometer niaccel;
  frc::ADXRS450_Gyro adigyro;
  ctre::phoenix::sensors::PigeonIMU ctreimu {30};
  //手柄配置 两个F310
  frc::Joystick f310a {0};
  frc::Joystick f310b {1};
  //上部结构 sucker吸盘 arm手臂
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX suckerjoint {5};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX armjoint {6};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX compressordrive {7};
  //frc::DoubleSolenoid
  //frc::Solenoid

  frc::Timer acceltime;
};