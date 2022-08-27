#include "HoneyBlueRingMode.h"

#define S1C1 0xFFD700
#define S1C2 0x665700
#define S2C1 0x0057B8
#define S2C2 0x003066

extern const TProgmemRGBPalette16 S1_p FL_PROGMEM =
{
    S1C1,
    S1C1,
    S1C1,
    S1C1,

    S1C2,
    S1C2,
    S1C2,
    S1C2,

    S1C1,
    S1C1,
    S1C1,
    S1C1,
    
    S1C2,
    S1C2,
    S1C2,
    S1C2,
};

extern const TProgmemRGBPalette16 S2_p FL_PROGMEM =
{
    S2C1,
    S2C1,
    S2C1,
    S2C1,

    S2C2,
    S2C2,
    S2C2,
    S2C2,

    S2C1,
    S2C1,
    S2C1,
    S2C1,
    
    S2C2,
    S2C2,
    S2C2,
    S2C2,
};

CHoneyBlueRingMode::CHoneyBlueRingMode(const uint16_t numLeds)
: CBaseMode(numLeds), increment(1), blendType(LINEARBLEND), delay(15) {
    segments.push_back(CLEDSegment(0, numLeds * 0.25, S1_p));
    segments.push_back(CLEDSegment(numLeds * 0.25, numLeds * 0.75, S2_p));
    segments.push_back(CLEDSegment(numLeds * 0.75, numLeds, S1_p));
}

void CHoneyBlueRingMode::draw(CRGB *leds) {

    if (millis() - tMillis > 10) {
        tMillis = millis();
        startIndex = startIndex + 1;
    }
    
    float ci = startIndex;
    for(CLEDSegment s : segments) {
        for( uint16_t i = s.start; i < s.end; i++) {
            leds[i] = ColorFromPalette( s.palette, (uint8_t)ci, 255, blendType);
            ci+=increment;
        }
    }
}