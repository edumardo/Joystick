# Dual-axis XY Joystick library for Arduino
Just a simple arduino library for control dual axis joystick. Main features:
- You can map outputs into a custom range through the constructor.
- You can define a threshold to control where axis movement don´t have effect.
- You can invert the axis values (in my hardware Y-axis decreases when I push forward the joystick).

## Install the library & Import
Download this repository as a .zip file and from the Arduino IDE go to *Sketch -> Include library -> Add .ZIP Library*.

You can import the library in your code using the Arduino IDE going to *Sketch -> Include library -> Joystick*
or directly writing the include statement in your code:
```
#include "Joystick.h"
```
## Features
#### Mapping outputs
A standar analog read is [0,1023]. In the constructor you set your preferences: [0,255], [-127,127], etc.
#### No action limit
The library defines a threshold, called no action limit, where you can control that axis movement don't have effect. According with your joystick hardware, you will want to increase/reduce the value. Hence, there are a low and high limit when the movement of the joystick has no effect.
#### Inverting axis
Some hardware, like I have, Y-axis decreases when I push forward. So you can control this issue inverting range values. With every invocation you reverse the axis.

## Using the library
In [examples/testJoystickLibrary.ino](examples/testJoystickLibrary.ino) yo can see the library in action. 

First, initialize a *Joystick* object with the proper pins,no action limit and map range:

```
    int pinJoystickX = A0;
    int pinJoystickY = A1;
    int pinJoystickButton = 5;
    int noActionLimit = 25;
    int minRange = 0;
    int maxRange = 255;
    Joystick joystick(pinJoystickX, pinJoystickY, pinJoystickButton, noActionLimit, minRange, maxRange);
```

Invert the axis if your hardware needs it:
```
    joystick.invertYAxis();
```

Then, get the outputs of the joystick and the defined thresholds:
```
    int XValue = joystick.getXValue();              // [minRange, maxRange]
    int YValue = joystick.getYValue();              // [minRange, maxRange]
    bool buttonValue = joystick.getbuttonValue();
    int lowLimit = joystick.getLowLimit();          // maxRange - noActionLimit
    int highLimit = joystick.getHighLimit();        // maxRange + noActionLimit
```

Ultimatelty, do something, like control the direction with threshold:
```
    // Turn left
    if (XValue < lowLimit)
    {
        status += "turnLeft ";
    }
```

**NOTE:** with every invocation of the getters, you will read the joystick status.
