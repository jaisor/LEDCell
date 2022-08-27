#pragma once

#include <vector>
#include "BaseMode.h"

class CHoneyBlueRingMode : public CBaseMode {

private:
    uint8_t startIndex = 0;
    const float increment;
    const TBlendType blendType;
    const unsigned long delay;
    std::vector<CLEDSegment> segments;

public:
	CHoneyBlueRingMode(const uint16_t numLeds);
    virtual void draw(CRGB *leds);
};
