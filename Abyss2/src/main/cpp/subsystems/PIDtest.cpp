/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/PIDtest.h"

#include <frc/livewindow/LiveWindow.h>
#include <frc/smartdashboard/SmartDashboard.h>

PIDtest::PIDtest()
    : PIDSubsystem("PIDtest", 1.0, 0.0, 0.0) {
  // Use these to get going:
  // SetSetpoint() -  Sets where the PID controller should move the system
  //                  to
  // Enable() - Enables the PID controller.
}

double PIDtest::ReturnPIDInput() {
  // Return your input value for the PID loop
  // e.g. a sensor, like a potentiometer:
  // yourPot->SetAverageVoltage() / kYourMaxVoltage;
  return gyro.GetFusedHeading();
}

void PIDtest::UsePIDOutput(double output) {
  // Use output to drive your system, like a motor
  // e.g. yourMotor->Set(output);
}

void PIDtest::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void PIDtest::Reset() {
  gyro.SetFusedHeading(0);
}

void PIDtest::SetHeading(double angle) {
  gyro.SetFusedHeading(angle);
}