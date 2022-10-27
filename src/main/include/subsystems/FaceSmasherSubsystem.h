// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"

class FaceSmasherSubsystem : public frc2::SubsystemBase {
 public:
  FaceSmasherSubsystem(double armSpeed, double effectorSpeed);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Move the arm Up
  void ArmUp();

  // Move the arm Down
  void ArmDown();

  // Stop all the arm motors
  void ArmStop();

  // Transition the arm from up to down
  void FlopArm();

  // Effector close / intake
  void EffectorIn();

  // Effector open / eject
  void EffectorOut();

  // Stop effector
  void EffectorStop();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  double m_armSpeed;
  double m_effectorSpeed;
  TalonSRX m_armMotor;
  // Whatever end effector is on the robot that controls intake
  TalonSRX m_effectorMotor;
  // TODO implement
  // True = Arm up
  // false = Arm down
  bool m_armState;
};
