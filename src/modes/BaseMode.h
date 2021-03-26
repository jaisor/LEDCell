#pragma once

#include <Arduino.h>
#include <FastLED.h>

class CBaseMode {

protected:
    unsigned long tMillis;
    const uint8_t numLeds;

public:
	CBaseMode(const uint8_t numLeds);
    virtual void draw(CRGB *leds) {};
};
