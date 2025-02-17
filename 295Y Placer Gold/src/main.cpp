#include "main.h"
#include "globals.h"
#include "pros/motors.h"
#include "lemlib/api.hpp"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}
void initialize() {
	pros::lcd::initialize(); // initialize brain screen
    while (true) { // infinite loop
        // print measurements from the vertical tracker
        pros::lcd::print(0, "Vertical Tracking Wheel: %i", verticalTracking.get_position());
        // print measurements from the horizontal wheel
        pros::lcd::print(1, "Horizontal Tracking Wheel: %i", horizontalTracking.get_position());
		pros::lcd::print(2, "Current Heading: %i", imu.get_heading());
		pros::lcd::print(4, "(%i", horizontalTracking.get_position(), ", %i", verticalTracking.get_position(), ")");
        pros::delay(10); // delay to save resources. DO NOT REMOVE
	}
}
void disabled() {}
void competition_initialize() {/*auton selector here*/}
void autonomous() {autons();}
void opcontrol() {driverControl();}