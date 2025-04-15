#ifndef LedToggle_h
#define LedToggle_h

#include "Arduino.h"

class LedToggle {
public:
	LedToggle(int pin);
	//LedToggle(int pin, unsigned long delayTime); 딜레이 추가
	void toggle();
	
private:
	int _pin;
	bool _state;
	//unsigned long _delayTime; 딜레이 추가
};

#endif
