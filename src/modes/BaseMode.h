#pragma once

#include <Arduino.h>
#include <FastLED.h>

class CLEDSegment {

public:
    const uint16_t start, end;
    const TProgmemRGBPalette16& palette;

	CLEDSegment(const uint16_t start, const uint16_t end, const TProgmemRGBPalette16& palette)
    : start(start), end(end), palette(palette) {};
};


class CBaseMode {

protected:
    unsigned long tMillis;
    const uint16_t numLeds;

public:
	CBaseMode(const uint16_t numLeds);
    virtual void draw(CRGB *leds) {};
};
