#include "PaletteMode.h"

CPaletteMode::CPaletteMode(const uint8_t numLeds, const TProgmemRGBPalette16& palette, const uint8_t increment)
: CBaseMode(numLeds), palette(palette), increment(increment), blendType(LINEARBLEND), delay(15) {
}

CPaletteMode::CPaletteMode(const uint8_t numLeds, const TProgmemRGBPalette16& palette, const uint8_t increment, const TBlendType blendType)
: CBaseMode(numLeds), palette(palette), increment(increment), blendType(blendType), delay(15) {
}

CPaletteMode::CPaletteMode(const uint8_t numLeds, const TProgmemRGBPalette16& palette, const uint8_t increment, const TBlendType blendType, const unsigned long delay)
: CBaseMode(numLeds), palette(palette), increment(increment), blendType(blendType), delay(delay) {
}

void CPaletteMode::draw(CRGB *leds) {

    if (millis() - tMillis > delay) {
        tMillis = millis();
        startIndex = startIndex + 1;
    }

    uint8_t ci = startIndex;
    for( int i = 0; i < numLeds; i++) {
        leds[i] = ColorFromPalette( palette, ci, 255, blendType);
        ci+=increment;
    }
}