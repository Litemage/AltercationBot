// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  //set our default command (default commands basically run on start on the program)
  //setDefaultCommand() function is located in the subsystem class
  //take the parameters: (command, required ssubsystems) required subsystems can be in the form of an init list.
  m_drive.SetDefaultCommand(
    frc2::RunCommand(
      [this]{

        // TODO Implement default command here
        // This is where all of the systems come together. Call DriveSubsystem::ArcadeDrive
        // from here, or functions from any other subsystem. This function will run periodically 
        // for each subsystem

  }, {&m_drive}));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

double RobotContainer::Deadband(double input, double threshold){
  // TODO implement deadband function
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
