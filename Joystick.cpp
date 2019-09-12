#include "Joystick.h"

Joystick::Joystick(uint8_t pinJoystickX, uint8_t pinJoystickY, uint8_t pinJoystickButton, int noActionLimit, int minRange, int maxRange)
{
    m_pinJoystickX = pinJoystickX;
    m_pinJoystickY = pinJoystickY;
    m_pinJoystickButton = pinJoystickButton;

    pinMode(m_pinJoystickButton, INPUT_PULLUP);
    pinMode(m_pinJoystickX, INPUT);
    pinMode(m_pinJoystickY, INPUT);

    m_XValue = 0;
    m_YValue = 0;
    m_buttonValue = false;
    m_minRange = minRange;
    m_maxRange = maxRange;

    m_noActionLimit = (((maxRange + minRange) / 2 - noActionLimit) < minRange) ? 0 : noActionLimit; // out of range check
    m_joystickLowLimit = (maxRange + minRange) / 2 - m_noActionLimit;
    m_joystickHighLimit = (maxRange + minRange) / 2 + m_noActionLimit;
}

int Joystick::getXValue()
{
    m_XValue = map(analogRead(m_pinJoystickX), m_minAnalogRange, m_maxAnalogRange, m_minRange, m_maxRange);
    return m_XValue;
}

int Joystick::getYValue()
{
    m_YValue = map(analogRead(m_pinJoystickY), m_minAnalogRange, m_maxAnalogRange, m_minRange, m_maxRange);
    return m_YValue;
}

bool Joystick::getbuttonValue()
{
    m_buttonValue = digitalRead(m_pinJoystickButton);
    return m_buttonValue;
}

int Joystick::getLowLimit()
{
    return m_joystickLowLimit;
}

int Joystick::getHighLimit()
{
    return m_joystickHighLimit;
}

int Joystick::getNoActionLimit()
{
    return m_noActionLimit;
}

String Joystick::toString()
{
    String str = "";
    str = str + "[" + m_minRange + "][" + m_maxRange + "] | X: ("+ m_joystickLowLimit + ") " + m_XValue + " (" + m_joystickHighLimit + ") | ";
    str = str + "Y: ("+ m_joystickLowLimit + ") " + m_YValue + " (" + m_joystickHighLimit + ") | ";
    str = str + " button: " + m_buttonValue;
    return str;
}

void Joystick::toSerial()
{
    Serial.println(toString());
}
