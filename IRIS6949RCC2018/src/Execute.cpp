/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*Project name: IRIS
Version: Alpha
Author: DongHaokun*/
//This code is the execution.
#include "Config.h"
#include <iostream>
int station=1;
std::string gameData;
void Robot::RobotInit() {
	leftJaw.SetInverted(true);
	Base.SetExpiration(0.1);
	Arm.SetExpiration(0.1);
	Base.SetSafetyEnabled(true);
	Arm.SetSafetyEnabled(true);
	Claw.Set(frc::DoubleSolenoid::kForward);
	//Two USB camera to feedback the vision
	cs::UsbCamera camera1 = CameraServer::GetInstance()->StartAutomaticCapture("baseVision","/dev/video0");
	cs::UsbCamera camera2 = CameraServer::GetInstance()->StartAutomaticCapture("handVision","/dev/video1");
	camera1.SetResolution(320,240);
	camera2.SetResolution(320,240);
	camera1.SetFPS(15);
	camera2.SetFPS(15);
}

void Robot::AutonomousInit() {
	Base.SetSafetyEnabled(false);
	Arm.SetSafetyEnabled(false);
	Time.Reset();
	Time.Start();
}

void Robot::AutonomousPeriodic() {
	//Get specific messeage from the FMS.
		std::string gameData;
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		//Get robot position from the FMS.
		int station;
		station = DriverStation::GetInstance().GetLocation();
		//To judge and decide which way to go.
		if (gameData.length() > 0) {
				if (gameData[0] == 'L') {/*
					if (station == 1) {
						if (Time.Get() < 4) {
							Base.DriveCartesian(-0.6,0,0);
						} else if (Time.Get() >= 4 and Time.Get() < 5) {
							Base.DriveCartesian(0,1,0);
						} else if (Time.Get() >= 5.5 and Time.Get() < 6) {
							Base.DriveCartesian(0,0,0);
							Break.Set(true);
							Arm.Set(0.3);
						} else if (Time.Get() >= 6 and Time.Get() < 7) {
							Arm.Set(0);
							Break.Set(false);
							Jaw.Set(-1);
						} else {
							Base.StopMotor();
							Arm.StopMotor();
							Jaw.StopMotor();
							Break.Set(false);
						}
					} else if (station == 2) {
						if (Time.Get() < 1) {
							Base.DriveCartesian(-0.8,0,0);
						} else if (Time.Get() >= 1 and Time.Get() < 3) {
							Base.DriveCartesian(0,-0.5,0);
						} else if (Time.Get() >= 3 and Time.Get() < 6) {
							Base.DriveCartesian(-0.7,0,0);
						} else if (Time.Get() >= 6 and Time.Get() < 7) {
							Base.DriveCartesian(0,1,0);
						} else if (Time.Get() >= 7 and Time.Get() < 7.5) {
							Base.DriveCartesian(0,0,0);
							Break.Set(true);
							Arm.Set(0.3);
						} else if (Time.Get() >= 7.5 and Time.Get() < 8) {
							Arm.Set(0);
							Break.Set(false);
							Jaw.Set(-1);
						} else {
							Base.StopMotor();
							Arm.StopMotor();
							Jaw.StopMotor();
							Break.Set(false);
						}
					} else {
						if (Time.Get() < 0.8) {
							Base.DriveCartesian(-0.6,0,0);
						} else if (Time.Get() >= 0.8 and Time.Get() < 4) {
							Base.DriveCartesian(0,-0.5,0);
						} else if (Time.Get() >= 4 and Time.Get() < 7) {
							Base.DriveCartesian(-0.8,0,0);
						} else if (Time.Get() >= 7 and Time.Get() < 8) {
							Base.DriveCartesian(0,0.5,0);
						} else if (Time.Get() >= 8 and Time.Get() < 8.5) {
							Base.DriveCartesian(0,0,0);
							Break.Set(true);
			      			Arm.Set(0.3);
						} else if (Time.Get() >= 8.5 and Time.Get() < 9.5) {
							Arm.Set(0);
							Break.Set(false);
							Jaw.Set(-1);
						} else {
							Base.StopMotor();
							Arm.StopMotor();
							Jaw.StopMotor();
							Break.Set(false);
						}
					}
				} else {
					if (station == 1) {
						if (Time.Get() < 0.8) {
											Base.DriveCartesian(-0.6,0,0);
										} else if (Time.Get() >= 0.8 and Time.Get() < 4) {
											Base.DriveCartesian(0,0.5,0);
										} else if (Time.Get() >= 4 and Time.Get() < 7) {
											Base.DriveCartesian(-0.8,0,0);
										} else if (Time.Get() >= 7 and Time.Get() < 8) {
											Base.DriveCartesian(0,-0.5,0);
										} else if (Time.Get() >= 8 and Time.Get() < 8.5) {
											Base.DriveCartesian(0,0,0);
											Break.Set(true);
							      			Arm.Set(-0.3);
										} else if (Time.Get() >= 8.5 and Time.Get() < 9.5) {
											Arm.Set(0);
											Break.Set(false);
											Jaw.Set(-1);
										} else {
											Base.StopMotor();
											Arm.StopMotor();
											Jaw.StopMotor();
											Break.Set(false);
										}
					} else if (station == 2) {
						if (Time.Get() < 1) {
											Base.DriveCartesian(-0.8,0,0);
										} else if (Time.Get() >= 1 and Time.Get() < 3) {
											Base.DriveCartesian(0,0.5,0);
										} else if (Time.Get() >= 3 and Time.Get() < 6) {
											Base.DriveCartesian(-0.7,0,0);
										} else if (Time.Get() >= 6 and Time.Get() < 7) {
											Base.DriveCartesian(0,-1,0);
										} else if (Time.Get() >= 7 and Time.Get() < 7.5) {
											Base.DriveCartesian(0,0,0);
											Break.Set(true);
											Arm.Set(-0.3);
										} else if (Time.Get() >= 7.5 and Time.Get() < 8) {
											Arm.Set(0);
											Break.Set(false);
											Jaw.Set(-1);
										} else {
											Base.StopMotor();
											Arm.StopMotor();
											Jaw.StopMotor();
											Break.Set(false);
										}
					} else {
						if (Time.Get() < 4) {
											Base.DriveCartesian(-0.6,0,0);
										} else if (Time.Get() >= 4 and Time.Get() < 5) {
											Base.DriveCartesian(0,-1,0);
										} else if (Time.Get() >= 5.5 and Time.Get() < 6) {
											Base.DriveCartesian(0,0,0);
											Break.Set(true);
											Arm.Set(-0.3);
										} else if (Time.Get() >= 6 and Time.Get() < 7) {
											Arm.Set(0);
	                                        Break.Set(false);
											Jaw.Set(-1);
										} else {
											Base.StopMotor();
											Arm.StopMotor();
											Jaw.StopMotor();
											Break.Set(false);
										}
					}
				}
			*/} else {
				if (Gyro.GetAngle() < 90) {
					Base.DriveCartesian(0,0.5,0);
				} else if (Gyro.GetAngle() >= 90) {
					Base.StopMotor();
				}
			}
		}


void Robot::TeleopInit() {
	Base.SetSafetyEnabled(false);
	Arm.SetSafetyEnabled(false);
	Time.Reset();
}

void Robot::TeleopPeriodic() {
	//Base drive method. To move the robot.
	Base.DriveCartesian(F310A.GetRawAxis(4)*0.8, -F310A.GetRawAxis(1)*0.8, (F310A.GetRawAxis(3)-F310A.GetRawAxis(2))*0.5);
	//The Claw, Jaw and Ejector control method. To grab or drop the cube, launch to cube to the scale.
	if (F310B.GetRawButton(1)) { //Open
		Claw.Set(frc::DoubleSolenoid::kForward);
	} else if (F310B.GetRawButton(2)) { //Close
		Claw.Set(frc::DoubleSolenoid::kReverse);
	} else if (F310B.GetRawAxis(1) > 0.1) { //In
		Jaw.Set(1);
		Claw.Set(frc::DoubleSolenoid::kReverse);
	} else if (F310B.GetRawAxis(1) < -0.1) { //Out
		Jaw.Set(-1);
		Claw.Set(frc::DoubleSolenoid::kReverse);
	} else if (F310B.GetRawAxis(2) > 0.1) {
		Jaw.Set(-1);
		Ejector.Set(true);
	} else {
		Jaw.Set(0);
		Claw.Set(frc::DoubleSolenoid::kOff);
		Ejector.Set(false);
	}
	//The Arm control method. To rotate the arm smooth and safe.
	if (F310B.GetRawButton(3)) { //Arm reverse
		Break.Set(true);
		Arm.Set(-0.3);
	} else if (F310B.GetRawButton(4)) { //Arm forward
		Break.Set(true);
		Arm.Set(0.3);
	} else {
		Break.Set(false);
		Arm.Set(0);
	}
}

void Robot::DisabledInit() {
	Base.SetSafetyEnabled(true);
	Arm.SetSafetyEnabled(true);
	Gyro.Reset();
	Time.Reset();
	Claw.Set(frc::DoubleSolenoid::kOff);
	Ejector.Set(false);
}

void Robot::DisabledPeriodic() {}

void Robot::TestPeriodic() {}
START_ROBOT_CLASS(Robot)
