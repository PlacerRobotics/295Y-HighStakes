#include "main.h"
#include "lemlib/api.hpp"

extern pros::Controller controller;
//Variables
extern int selectedAuton;
//Motors
extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;
extern lemlib::Drivetrain drivetrain;
extern lemlib::Chassis chassis;
extern pros::Motor intake;
extern pros::Motor ladyBrown;
//Sensors
extern pros::Rotation verticalTracking;
extern pros::Rotation horizontalTracking;
extern pros::Imu imu;
extern pros::Rotation ladyBrownRotation;
extern pros::Optical intakeColor1;
extern pros::Optical intakeColor2;
//Pneumatics
extern pros::ADIDigitalOut clamp;
extern pros::ADIDigitalOut sweeper;
//LemLib
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
//Global Functions
void autons();
void driverControl();
void setDrive(int leftPwr, int rightPwr);
void speedyDrive();
void setDriveSpeed(float voltage);
void rotateHeading(float theta, float timeout, int speedLimit, bool execution);
void rotatePoint(float theta, float timeout);
void setPose(float x, float y, float theta);
void translatePoint(float x, float y, bool dir, float timeout, bool async);
void translatePose(float x, float y, float heading, float timeout, bool dir, float rvalue);
