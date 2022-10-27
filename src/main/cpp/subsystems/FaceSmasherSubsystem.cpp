// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/FaceSmasherSubsystem.h"
#include "Constants.h"
#include <chrono>

FaceSmasherSubsystem::FaceSmasherSubsystem(double armSpeed, double effectorSpeed) : m_armMotor{MotorAddr::armMotor}, m_effectorMotor{MotorAddr::effectorMotor}, m_armState{false}{
    m_armSpeed = armSpeed;
    m_effectorSpeed = effectorSpeed;
}

// This method will be called once per scheduler run
void FaceSmasherSubsystem::Periodic() {}

void FaceSmasherSubsystem::FlopArm() {}

/* ------------------------------- Arm control ------------------------------ */

void FaceSmasherSubsystem::ArmUp() {
    m_armMotor.Set(ControlMode::PercentOutput, m_armSpeed);
}

void FaceSmasherSubsystem::ArmDown() {
    // TODO inverted?
    m_armMotor.Set(ControlMode::PercentOutput, -1 * m_armSpeed);
}

void FaceSmasherSubsystem::ArmStop(){
    m_armMotor.Set(ControlMode::PercentOutput, 0);
}

/* ---------------------------- Effector control ---------------------------- */

void FaceSmasherSubsystem::EffectorIn() {
    // TODO need to be inverted?
    m_effectorMotor.Set(ControlMode::PercentOutput, -1 * m_effectorSpeed);
}

void FaceSmasherSubsystem::EffectorOut() {
    m_effectorMotor.Set(ControlMode::PercentOutput, m_effectorSpeed);
}

void FaceSmasherSubsystem::EffectorStop(){
    m_effectorMotor.Set(ControlMode::PercentOutput, 0);
}
