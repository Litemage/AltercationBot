// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

DriveSubsystem::DriveSubsystem() : m_left{1}, m_right{2} {
  // Implementation of subsystem constructor goes here.
}

void DriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void DriveSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void DriveSubsystem::ArcadeDrive(double vy, double vx){
  m_left.Set(ControlMode::PercentOutput, vy + vx);
  m_right.Set(ControlMode::PercentOutput, vy - vx);
}

void TankDrive(double pl, double pr, unsigned double scalar){
  // Guard  against invalid scalar
  if (scalar <= 0 || scalar > 1){
    pl = 1;
    pr = 1;
    std::cout << "Invalid scalar given to DriveSubsystem::TankDrive.\n";
  }
  // Multiply by scalar to limit speed
  pl *= scalar;
  pr *= scalar;

  // TODO implement tank drive
}