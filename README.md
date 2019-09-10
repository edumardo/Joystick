# Dual-axis XY Joystick library for Arduino
Just a simple arduino library for control dual axis joystick with no action limit.

## Install the library
Download this repository as a .zip file and from the Arduino IDE go to *Sketch -> Include library -> Add .ZIP Library*.

## Import
You can import the library in your code using the Arduino IDE going to *Sketch -> Include library -> Joystick*
or directly writing the include statement in your code:
```
#include "Joystick.h"
```

## No action limit
The library defines a threshold, called no action limit, where axis movement don't have effect. According with your joystick hardware, you will want to increase/reduce the value. Hence, there are a low and high limit when the movement of the joystick has no effect.
See below to initialize the property.

## Using the library
In *examples/testJoystickLibrary.ino* yo can see the library in action. 

First, initialize a *Joystick* object with the propper pins and a no action limit:

```
  int pinJoystickX = A0;
  int pinJoystickY = A1;
  int pinJoystickButton = 5;
  int noActionLimit = 100;
  Joystick joystick(pinJoystickX, pinJoystickY, pinJoystickButton, noActionLimit);
```

Then, get the outputs of the joystick:

```
    int YValue = joystick.getYValue();
    int XValue = joystick.getXValue();
    bool buttonValue = joystick.getbuttonValue();
```

Ultimatelty, do something, like control the direction:
```
    // Turn left
    if (XValue < lowLimit)
    {
        status += "turnLeft ";
    }
```

**NOTE:** with every invocation of the getters, you will read the joystick status.
