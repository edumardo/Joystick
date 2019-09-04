#include "Arduino.h"
#include <Joystick.h>

const int serialDelay = 200;
Joystick joystick(A0, A1, 5, 100);

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	int XValue = joystick.readXValue();
	int YValue = joystick.readYValue();
	bool buttonValue = joystick.readButtonValue();
	int lowLimit = joystick.getLowLimit();
	int highLimit = joystick.getHighLimit();
	String status = " | status: ";

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

	Serial.println(joystick.toString() + status);
	delay(serialDelay);
}
