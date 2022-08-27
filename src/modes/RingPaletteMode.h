#pragma once

#include <vector>
#include "BaseMode.h"

class CRingPaletteMode : public CBaseMode {

private:
    uint8_t startIndex = 0;
    const float increment;
    const TProgmemRGBPalette16& palette;
    const TBlendType blendType;
    const unsigned long delay;

    std::vector<CLEDSegment> segments;

public:
	CRingPaletteMode(const uint16_t numLeds, const TProgmemRGBPalette16& palette, const float increment);
    CRingPaletteMode(const uint16_t numLeds, const TProgmemRGBPalette16& palette, const float increment, const TBlendType blendType);
    CRingPaletteMode(const uint16_t numLeds, const TProgmemRGBPalette16& palette, const float increment, const TBlendType blendType, const unsigned long delay);
    virtual void draw(CRGB *leds);
};
