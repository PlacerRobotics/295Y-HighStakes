#include "globals.h"
#include "lemlib/api.hpp"

void driverControl(){
    speedyDrive();
    while (true){
        float leftYAnalog = controller.get_analog(ANALOG_LEFT_Y);
        float rightXAnalog = controller.get_analog(ANALOG_RIGHT_X);
        leftYAnalog = (leftYAnalog<0 ? -1:1) * pow(leftYAnalog, 2) / 127;
        rightXAnalog = (rightXAnalog<0 ? -1:1) * pow(rightXAnalog, 2) / 127;
        double leftPower = (leftYAnalog + rightXAnalog)*100/127;
        double rightPower = (leftYAnalog - rightXAnalog)*100/127;
        setDrive(leftPower, rightPower);
        
        pros::delay(20);
    }
}