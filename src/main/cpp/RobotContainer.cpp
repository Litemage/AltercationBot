// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"
#include <frc2/command/RunCommand.h>
#include <cmath>


constexpr double thresh = 0.2;
constexpr double boostMult = 0.5;


RobotContainer::RobotContainer() : m_controller{0}, m_arm{0.2, 0.1}  {
  // Initialize all of your commands and subsystems here

  //set our default command (default commands basically run on start on the program)
  //setDefaultCommand() function is located in the subsystem class
  //take the parameters: (command, required ssubsystems) required subsystems can be in the form of an init list.
  m_drive.SetDefaultCommand(
    frc2::RunCommand(
      [this]{

        double leftY = Deadband(m_controller.GetRawAxis(static_cast<int>(frc::XboxController::Axis::kLeftY)), thresh); //left stick, forward/backward
        double rightX = Deadband(m_controller.GetRawAxis(static_cast<int>(frc::XboxController::Axis::kRightX)), thresh); //right stick, left/right
        bool leftStick = m_controller.GetRawButton((static_cast<int>(frc::XboxController::Button::kLeftStick))); //left stick, boost
        bool rightBumper = m_controller.GetRawButton((static_cast<int>(frc::XboxController::Button::kRightBumper))); // right bumper, intake
        bool leftBumper = m_controller.GetRawButton((static_cast<int>(frc::XboxController::Button::kLeftBumper))); // left bumper, reverse intake
        // TODO implement button for up and down arm
        bool upButton = false;
        bool downButton = false;

        if (rightBumper) {
          m_arm.EffectorIn();
        } else if (leftBumper) {
          m_arm.EffectorOut();
        } else {
          m_arm.EffectorStop();
        }

        if (upButton) {
          m_arm.ArmUp();
        } else if (downButton) {
          m_arm.ArmDown();
        } else {
          m_arm.ArmStop();
        }
      
      if (!leftStick) {
        leftY *= boostMult;
        rightX *= boostMult;
      }

        m_drive.ArcadeDrive(leftY, rightX);
        
        

  }, {&m_drive}));

  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

double RobotContainer::Deadband(double input, double threshold){
  if (std::abs(input) < threshold) {
    return 0;
  } else {
    return input;
  }
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return nullptr;
}
