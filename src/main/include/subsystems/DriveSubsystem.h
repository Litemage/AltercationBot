// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>


class DriveSubsystem : public frc2::SubsystemBase {
 public:
  DriveSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  /**
   * Will be called periodically whenever the CommandScheduler runs during
   * simulation.
   */
  void SimulationPeriodic() override;

// Drive robot arcade-style
//vy = velocity forward
//vx = velocity right
void ArcadeDrive(double vy, double vx);

// Drive robot Tank-Style
// pl - Left percent power for left motor
// pr - Right percent power for left motor
// scale - controls max percent output, by default is 1 (0 < scale <= 1)
void TankDrive(double pl, double pr, double scalar = 1);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  TalonSRX m_left;
  TalonSRX m_right;
};
