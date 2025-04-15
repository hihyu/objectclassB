#include "LedToggle.h"

LedToggle::LedToggle(int pin) {
	_pin = pin;
	_state = false;
	//_delayTime = 0; 딜레이 추가
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
}

//LedToggle::LedToggle(int pin, unsigned long delayTime) { 딜레이 추가
//	_pin = pin;
//	_state = false;
//	_delayTime = delayTime;
//	pinMode(_pin, OUTPUT);
//	digitalWrite(_pin, LOW);
//}

void LedToggle::toggle() {
	
	//if(_delayTime > 0) { 딜레이 추가
	//	delay(_delayTime);
	//}
	
	_state = !_state;
	digitalWrite(_pin, _state ? HIGH : LOW);
}
