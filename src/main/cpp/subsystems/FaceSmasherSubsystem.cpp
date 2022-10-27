// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/FaceSmasherSubsystem.h"
#include "Constants.h"
#include <chrono>

FaceSmasherSubsystem::FaceSmasherSubsystem() : m_armMotor{MotorAddr::armMotor}, m_armState{false}{}

// This method will be called once per scheduler run
void FaceSmasherSubsystem::Periodic() {}

void FaceSmasherSubsystem::FlopArm() {}

void FaceSmasherSubsystem::ArmUp() {
    m_armMotor.Set(ControlMode::PercentOutput, 0.2);
}

void FaceSmasherSubsystem::ArmDown() {
    m_armMotor.Set(ControlMode::PercentOutput, -0.2);
}

void FaceSmasherSubsystem::StopArm(){
    m_armMotor.Set(ControlMode::PercentOutput, 0);
}
