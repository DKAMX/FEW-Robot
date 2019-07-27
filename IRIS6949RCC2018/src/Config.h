/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*Project name: IRIS
Version: Alpha
Author: DongHaokun*/
#pragma once
#include <string>
#include <WPILib.h>

class Robot : public frc::IterativeRobot {
public:
	void RobotInit() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void TestPeriodic() override;

private: //These are robot's hardware and function.
	//4 Base Motor with Spark controller. Using the MecanumDrive.
	frc::Spark frontLeft{0};
	frc::Spark rearLeft{1};
	frc::Spark frontRight{2};
	frc::Spark rearRight{3};
	frc::MecanumDrive Base{frontLeft, rearLeft, frontRight, rearRight};

	//2 Motor with Spark controller. To grab or drop the cube.
	frc::Spark leftJaw{4};
	frc::Spark rightJaw{5};
	//frc::DifferentialDrive Jaw{leftJaw, rightJaw};
	frc::SpeedControllerGroup Jaw{leftJaw, rightJaw};
	//A double soleniod with compressor to control the claw open and close.
	frc::DoubleSolenoid Claw{0, 1};

	//Single motor to rotate the joint.
	frc::Spark Arm{6};
	//A solenoid with compressor to launch the cube to a higher place.
	frc::Solenoid Ejector{2};
	//frc::DoubleSolenoid Ejector{4,5};
	//A solenoid with compressor to lock the arm joint.
	frc::Solenoid Break{3};

	//IMU sensor to feedback the 3axis acceleration and 3axis angle.
	frc::BuiltInAccelerometer Gsensor;
	frc::ADXRS450_Gyro Gyro;

	//A Timer to record time.
	frc::Timer Time;

	//Use two Joysticks to control robot's movement and action.
	//Beware the USB port, they must be the same as the number below.
	//You can check out the port number at DriverStation.
	frc::Joystick F310A{0};
	frc::Joystick F310B{1};
	frc::Joystick LEX3D{2}; //Reserved
	frc::Joystick SAV8R{3}; //Reserved
};
