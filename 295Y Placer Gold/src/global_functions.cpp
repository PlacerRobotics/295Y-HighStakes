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