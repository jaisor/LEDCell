#pragma once

#include "BaseMode.h"

class CPaletteMode : public CBaseMode {

private:
    uint8_t startIndex = 0;
    const uint8_t increment;
    const TProgmemRGBPalette16& palette;
    const TBlendType blendType;
    const unsigned long delay;

public:
	CPaletteMode(const uint8_t numLeds, const TProgmemRGBPalette16& palette, const uint8_t increment);
    CPaletteMode(const uint8_t numLeds, const TProgmemRGBPalette16& palette, const uint8_t increment, const TBlendType blendType);
    CPaletteMode(const uint8_t numLeds, const TProgmemRGBPalette16& palette, const uint8_t increment, const TBlendType blendType, const unsigned long delay);
    virtual void draw(CRGB *leds);
};
