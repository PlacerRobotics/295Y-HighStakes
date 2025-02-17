#include "globals.h"
#include "lemlib/api.hpp"

int selectedAuton = 1;

pros::Controller controller(pros::E_CONTROLLER_MASTER);
//Motors
pros::MotorGroup left_motors({-17, 10, 8}, pros::MotorGearset::blue);
pros::MotorGroup right_motors({12, 21, -1}, pros::MotorGearset::blue);
pros::Motor intake(11, pros::MotorGearset::blue);
pros::Motor ladyBrown(-20, pros::MotorGearset::red);
//Sensors
pros::Rotation ladyBrownRotation(8);
pros::Optical intakeColor1(7);
pros::Optical intakeColor2(9);
//Pneumatics
pros::ADIDigitalOut clamp('B');
pros::ADIDigitalOut sweeper('A');
//LemLib stuff

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_motors,
    &right_motors, //
    10, // track width
    lemlib::Omniwheel::NEW_325,
    360, // drivetrain rpm
    2 // horizontal drift
);
//Inertial Sensor
pros::Imu imu(9);
//Odom Sensors (Rotations)
pros::Rotation verticalTracking(1);
pros::Rotation horizontalTracking(3);
//Odom settings
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontalTracking, lemlib::Omniwheel::NEW_275_HALF, -5.75);
lemlib::TrackingWheel vertical_tracking_wheel(&verticalTracking, lemlib::Omniwheel::NEW_275_HALF, -5.75);
//Sensors
lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
    nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
    &horizontal_tracking_wheel, // horizontal tracking wheel 1
    nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
    &imu // inertial sensor
);
// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);
//Chassis setup
// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttle_curve(3, // joystick deadband out of 127
    10, // minimum output where drivetrain will move out of 127
    1.019 // expo curve gain
);
// input curve for steer input during driver control
lemlib::ExpoDriveCurve steer_curve(3, // joystick deadband out of 127
 10, // minimum output where drivetrain will move out of 127
 1.019 // expo curve gain
);
lemlib::Chassis chassis(drivetrain,
    lateral_controller,
    angular_controller,
    sensors,
    &throttle_curve, 
    &steer_curve
);