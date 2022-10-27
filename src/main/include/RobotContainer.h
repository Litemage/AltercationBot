// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>

#include "subsystems/DriveSubsystem.h"
#include "subsystems/FaceSmasherSubsystem.h"

#include <frc/XboxController.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
  // The robot's subsystems and commands are defined here...
  // Controller for robot
  frc::XboxController m_controller;
  DriveSubsystem m_drive;
  // The arm subsystem
  FaceSmasherSubsystem m_arm;

  // Returns zero if input is abs(threshold) away from zero. 
  // Otherwise, returns input Useful for controller deadband
  // input - the number to compare to threshold
  // threshold - the minimum distance away from zero to allow return input (inclusive)
  double Deadband(double input, double threshold);

  void ConfigureButtonBindings();

};
