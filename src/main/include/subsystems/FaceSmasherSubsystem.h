// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"

class FaceSmasherSubsystem : public frc2::SubsystemBase {
 public:
  FaceSmasherSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Move the arm Up
  void ArmUp();
  // Move the arm Down
  void ArmDown();

  // Transition the arm from up to down
  void FlopArm();

  // Stop all the arm motors
  void StopArm();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  TalonSRX m_armMotor;
  // TODO implemented
  // True = Arm up
  // false = Arm down
  bool m_armState;
};
