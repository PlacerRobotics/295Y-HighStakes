#include "globals.h"
#include "lemlib/api.hpp"
#include <string>

void moveMotors(pros::Motor mtr, float pwr) {mtr.move_voltage(pwr*120);}
void moveMotors(std::vector<pros::Motor> mtrList, float pwr){
    for (int i=0; i < mtrList.size(); i++){
        mtrList[i].move_voltage(pwr*120);
    }
}
void setDrive(int leftPwr, int rightPwr){
    moveMotors({-17, 10, 8}, leftPwr);
    moveMotors({12, 21, -1}, rightPwr);
}

void speedyDrive(){
    left_motors.set_voltage_limit(15240);
    right_motors.set_voltage_limit(15240);
}

void setDriveSpeed(float voltage){
    left_motors.set_voltage_limit(voltage);
    right_motors.set_voltage_limit(voltage);
}

//robot turns to a specific heading
void rotateHeading(float theta, float timeout, int speedLimit, bool execution){
    chassis.turnToHeading(theta, timeout, {.maxSpeed = speedLimit}, execution);
}
//robot turns to a point on cartesian
void rotatePoint(float theta, float timeout){
    chassis.turnToHeading(theta, timeout);
}
//tares the current position of the robot
void setPose(float x, float y, float theta){
    chassis.setPose(x, y, theta);
}
//moves the robot to a specific point on the field, no heading
void translatePoint(float x, float y, bool dir, float timeout, bool async){
    chassis.moveToPoint(x, y, timeout, {.forwards = dir}, async);
}
//moves the robot to a specific point on the field, with heading
void translatePose(float x, float y, float heading, float timeout, bool dir, float rvalue){
    chassis.moveToPose(x, y, heading, timeout, {.forwards = dir, .lead = rvalue});
}
