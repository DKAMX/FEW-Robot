/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

void Robot::RobotInit() {
  //底盘设置slave跟随drive运动
  leftslave.Follow(leftdrive);
  rightslave.Follow(rightdrive);
  basedrive.SetSafetyEnabled(true);
  basedrive.SetExpiration(0.1);
  //摄像头设置 底盘 上部
  frc::CameraServer::GetInstance()->StartAutomaticCapture(0);
  frc::CameraServer::GetInstance()->StartAutomaticCapture(1);
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {
  //底盘预留手动驾驶 如遇致命自动问题可以删去"/*"和"*/"注释符 不再使用自动代码
  
  double rate = 1.0;
  basedrive.ArcadeDrive(-f310a.GetRawAxis(1) * rate, (f310a.GetRawAxis(3) - f310a.GetRawAxis(2)) * rate);
  
}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  //底盘驾驶模式 左遥感控制前后 左右扳机控制左右 rate设定功率
  double rate = 1.0;
  basedrive.ArcadeDrive(-f310a.GetRawAxis(1) * rate, (f310a.GetRawAxis(3) - f310a.GetRawAxis(2)) * rate);
  //上部结构控制

}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void AutoDriveDistance(double target) {
  double accel, ktime, distance, speed, distance, diffdrive;
  if (distance <= target) {
    basedrive.ArcadeDrive(1.0, 0.0);
    do {
      //basedrive.ArcadeDrive(1.0, 0.0);
      accel = niaccel.GetY() * 9.7949;
      speed = accel * ktime + speed;
      distance = speed * ktime + accel * ktime * ktime / 2 + distance;
      diffdrive = (target - distance);
      //basedrive.ArcadeDrive(1.0, 0.0);
      basedrive.ArcadeDrive(diffdrive, 0.0);
      frc::Wait(0.02);
    }while (distance <= target);
  } else {
    basemotor->ArcadeDrive(0.0, 0.0);
  }
}

void AutoTurnAngle(double angle) {
  while (gyro.GetFusedHeading() <= angle) {
    double diff = gyro.GetFusedHeading() + angle;
    double turn = diff * 0.0125;
    basedrive.ArcadeDrive(0.0, turn);
  }
  basedrive.ArcadeDrive(0.0, 0.0);
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif