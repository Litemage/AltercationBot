// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"
#include "Constants.h"
#include <iostream>

DriveSubsystem::DriveSubsystem() : m_left{MotorAddr::leftMotor}, m_right{MotorAddr::rightMotor} {
  // invert left motor
  m_left.SetInverted(InvertType::InvertMotorOutput);
}

void DriveSubsystem::Periodic() {
}

void DriveSubsystem::SimulationPeriodic() {
}

void DriveSubsystem::ArcadeDrive(double vy, double vx){
  m_left.Set(ControlMode::PercentOutput, (vy + vx));
  m_right.Set(ControlMode::PercentOutput, vy - vx);
}

void DriveSubsystem::TankDrive(double pl, double pr, double scalar){
  // Guard  against invalid scalar
  if (scalar <= 0 || scalar > 1){
    pl = 1;
    pr = 1;
    std::cout << "Invalid scalar given to DriveSubsystem::TankDrive.\n";
  }
  // Multiply by scalar to limit speed
  pl *= scalar;
  pr *= scalar;

  m_left.Set(ControlMode::PercentOutput, (pl));
  m_right.Set(ControlMode::PercentOutput, (pl));

}
