#include "HoneyOrangeMode.h"

#define HONEY_DARK_ORANGE 0x5c2b00
#define HONEY_ORANGE 0xff8400
#define HONEY_LIGHT_ORANGE 0xffaa00
#define HONEY_YELLOW 0xffcc00

extern const TProgmemRGBPalette16 HoneyOrange_p FL_PROGMEM =
{
    HONEY_DARK_ORANGE,
    HONEY_DARK_ORANGE,
    HONEY_DARK_ORANGE,
    HONEY_DARK_ORANGE,

    HONEY_ORANGE,
    HONEY_ORANGE,
    HONEY_ORANGE,
    HONEY_ORANGE,

    HONEY_LIGHT_ORANGE,
    HONEY_LIGHT_ORANGE,
    HONEY_LIGHT_ORANGE,
    HONEY_LIGHT_ORANGE,
    
    HONEY_YELLOW,
    HONEY_YELLOW,
    HONEY_YELLOW,
    HONEY_YELLOW,
};

CHoneyOrangeMode::CHoneyOrangeMode(const uint8_t numLeds)
: CPaletteMode(numLeds, HoneyOrange_p, 1) {
    
}
