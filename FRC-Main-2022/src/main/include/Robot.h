/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/smartdashboard/SendableChooser.h>

#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/drive/MecanumDrive.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <ADIS16470_IMU.h>
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  //void AutonomousInit() override;
  //void AutonomousPeriodic() override;
  //void TeleopInit() override;
  void TeleopPeriodic() override;
  //void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_autoChooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
  frc::ADIS16470_IMU m_imu{};
  frc::SendableChooser<std::string> m_yawChooser;
  const std::string kYawDefault = "Z-Axis";
  const std::string kYawXAxis = "X-Axis";
  const std::string kYawYAxis = "Y-Axis";
  std::string m_yawSelected;
  bool m_runCal = false;
  bool m_configCal = false;
  bool m_reset = false;
  bool m_setYawAxis = false;
  uint16_t m_decRate = 4;
  bool m_setDecRate = false;
  frc::ADIS16470_IMU::IMUAxis m_yawActiveAxis = frc::ADIS16470_IMU::IMUAxis::kZ;
  static constexpr int kFrontLeftChannel = 2;
  static constexpr int kRearLeftChannel = 3;
  static constexpr int kFrontRightChannel = 0;
  static constexpr int kRearRightChannel = 1;

  static constexpr int kJoystickChannel = 0;

  frc::PWMSparkMax m_frontLeft{kFrontLeftChannel};
  frc::PWMSparkMax m_rearLeft{kRearLeftChannel};
  frc::PWMSparkMax m_frontRight{kFrontRightChannel};
  frc::PWMSparkMax m_rearRight{kRearRightChannel};
  frc::MecanumDrive m_robotDrive{m_frontLeft, m_rearLeft, m_frontRight,
                                 m_rearRight};

  frc::Joystick m_stick{kJoystickChannel};
};
