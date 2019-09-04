#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"

class Joystick
{
	private:
		const int m_joystickRange = 512;
		int m_joystickLowLimit;
		int m_joystickHighLimit;
		uint8_t m_pinJoystickButton;
		uint8_t m_pinJoystickX;
		uint8_t m_pinJoystickY;
		int m_XValue;
		int m_YValue;
		bool m_buttonValue;
		int m_noActionLimit;

	public:
		Joystick(uint8_t pinJoystickX, uint8_t pinJoystickY, uint8_t pinJoystickButton, int noActionLimit);
		int getXValue();
		int getYValue();
		int readXValue();
		int readYValue();
		bool readButtonValue();
		bool getbuttonValue();
		int getLowLimit();
		int getHighLimit();
		String toString();
		void toSerial();
};
#endif
