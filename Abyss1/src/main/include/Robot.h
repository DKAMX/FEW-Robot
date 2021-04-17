/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
/*  class CustomPIDSource : public frc::PIDSource {
   public:
    explicit CustomPIDSource(ctre::phoenix::sensors::PigeonIMU& g) : imu(g) {}

    double PIDGet(double source) override {
       imu.GetFusedHeading(source);
    }

   private:
     ctre::phoenix::sensors::PigeonIMU& imu;
  };*/
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  ctre::phoenix::motorcontrol::can::WPI_TalonSRX leftfront {1};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX leftrear {2};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX rightfront {3};
  ctre::phoenix::motorcontrol::can::WPI_TalonSRX rightrear {4};
  ctre::phoenix::sensors::PigeonIMU gyro {30};
  frc::DifferentialDrive basedrive {leftfront, rightfront};
  frc::Joystick f310 {0};
  frc::Joystick g29 {2};
};
