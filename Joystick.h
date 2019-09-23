#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"

#define MINANALOGRANGE 0
#define MAXANALOGRANGE 1023

class Joystick
{
    private:
        const int m_minAnalogRange = 0;
        const int m_maxAnalogRange = 1023;
        int m_joystickLowLimit;
        int m_joystickHighLimit;
        uint8_t m_pinJoystickButton;
        uint8_t m_pinJoystickX;
        uint8_t m_pinJoystickY;
        int m_XValue;
        int m_YValue;
        int m_minRange;
        int m_maxRange;
        bool m_buttonValue;
        int m_noActionLimit;
        bool m_XAxisInverted;
        bool m_YAxisInverted;

    public:
        Joystick(uint8_t pinJoystickX, uint8_t pinJoystickY, uint8_t pinJoystickButton, int noActionLimit, int minRange, int maxRange);
        int getXValue();
        int getYValue();
        bool getbuttonValue();
        int getLowLimit();
        int getHighLimit();
        int getNoActionLimit();
        void invertXAxis();
        void invertYAxis();
        String toString();
        void toSerial();
};
#endif
