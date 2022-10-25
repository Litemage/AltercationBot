// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ArcadeDrive.h"

ArcadeDriveSubsystem::ArcadeDriveSubsystem() : m_left{1}, m_right{2} {
  // Implementation of subsystem constructor goes here.
}

void ArcadeDriveSubsystem::Periodic() {
  // Implementation of subsystem periodic method goes here.
}

void ArcadeDriveSubsystem::SimulationPeriodic() {
  // Implementation of subsystem simulation periodic method goes here.
}

void ArcadeDriveSubsystem::ArcadeDrive(double vy, double vx){
  m_left.Set(ControlMode::PercentOutput, vy + vx);
  // TODO asses positive or negative
  m_right.Set(ControlMode::PercentOutput, vy + vx);
}
