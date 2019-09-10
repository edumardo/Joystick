#include "Arduino.h"
#include <Joystick.h>

const int serialDelay = 200;
int pinJoystickX = A0;
int pinJoystickY = A1;
int pinJoystickButton = 5;
int noActionLimit = 100;
Joystick joystick(pinJoystickX, pinJoystickY, pinJoystickButton, noActionLimit);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int YValue = joystick.getYValue();
    int XValue = joystick.getXValue();
    bool buttonValue = joystick.getbuttonValue();
    int lowLimit = joystick.getLowLimit();
    int highLimit = joystick.getHighLimit();
    String status = " | noActionLimit: " + (String)joystick.getNoActionLimit() + " | status: ";

    // Turn left
    if (XValue < lowLimit)
    {
        status += "turnLeft ";
    }

    // Turn right
    if (XValue > highLimit)
    {
        status += " turnRight ";
    }

    // Throttle (YValue decreases when push forward the Y axis).
    if (YValue < lowLimit)
    {
        status += " throttle ";
    }

    // Reverse (YValue increases when push back the Y axis).
    if (YValue > highLimit)
    {
        status += " reverse ";
    }

    // Idle
    if ((XValue > lowLimit) && (XValue < highLimit) && (YValue > lowLimit) && (YValue < highLimit))
    {
        status += " idle ";
    }

    // button (false when pushed)
    if (buttonValue != true)
    {
        status += " pushed";
    }

    Serial.println(joystick.toString() + status);
    delay(serialDelay);
}
