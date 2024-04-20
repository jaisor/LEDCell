#include <Arduino.h>
#include <FastLED.h>
#include <vector>

#include "modes/HoneyOrangeMode.h"
#include "modes/HoneyBlueRingMode.h"
#include "modes/PaletteMode.h"
#include "modes/RingPaletteMode.h"

//#define TEST_LED_STRIP

#define BRIGHTNESS        255   // 0-255
#define CHANGE_MODE_SEC   60    // Change mode every minute

#define LED_PIN_BOARD     13
#define LED_PIN_STRIP     10

#ifdef TEST_LED_STRIP
    #define NUM_LEDS      144
#else
    #define NUM_LEDS      61 
#endif

#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

std::vector<CBaseMode*> modes;

extern const TProgmemRGBPalette16 ESporta_p FL_PROGMEM =
{
    0x012427, 0x012427, 0x008996, 0x008996 ,
    0x09c4d6, 0x09c4d6, 0x09c4d6, 0xFFFFFF,
    0xFFFFFF, 0x09c4d6, 0x09c4d6, 0x09c4d6,
    0x008996, 0x008996, 0x012427, 0x012427
};

void setup() {
    delay( 1000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN_STRIP, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness( BRIGHTNESS );

    pinMode(LED_PIN_BOARD, OUTPUT);
    digitalWrite(LED_PIN_BOARD, HIGH);

    //modes.push_back(new CPaletteMode(NUM_LEDS, ESporta_p, 255 / NUM_LEDS));
    modes.push_back(new CPaletteMode(NUM_LEDS, LavaColors_p, 255 / NUM_LEDS));
    modes.push_back(new CHoneyOrangeMode(NUM_LEDS));
    modes.push_back(new CPaletteMode(NUM_LEDS, RainbowStripeColors_p, 1, LINEARBLEND, 25));
    modes.push_back(new CPaletteMode(NUM_LEDS, PartyColors_p, 1));
    modes.push_back(new CPaletteMode(NUM_LEDS, HeatColors_p, 255 / NUM_LEDS));
    modes.push_back(new CPaletteMode(NUM_LEDS, RainbowColors_p, 255 * 3 / NUM_LEDS ));
    modes.push_back(new CPaletteMode(NUM_LEDS, CloudColors_p, 1, LINEARBLEND, 50));
    modes.push_back(new CPaletteMode(NUM_LEDS, ForestColors_p, 255 / NUM_LEDS));
    modes.push_back(new CPaletteMode(NUM_LEDS, OceanColors_p, 255 * 2 / NUM_LEDS, LINEARBLEND, 100));
    modes.push_back(new CPaletteMode(NUM_LEDS, HeatColors_p, 255 / NUM_LEDS));
    
    modes.push_back(new CHoneyBlueRingMode(NUM_LEDS));
    
    //modes.push_back(new CRingPaletteMode(NUM_LEDS, ESporta_p, 255 / NUM_LEDS));
    modes.push_back(new CRingPaletteMode(NUM_LEDS, LavaColors_p, 255 / NUM_LEDS));
    modes.push_back(new CRingPaletteMode(NUM_LEDS, RainbowStripeColors_p, 1, LINEARBLEND, 25));
    modes.push_back(new CRingPaletteMode(NUM_LEDS, PartyColors_p, 1));
    modes.push_back(new CRingPaletteMode(NUM_LEDS, HeatColors_p, 255 / NUM_LEDS));
    modes.push_back(new CRingPaletteMode(NUM_LEDS, RainbowColors_p, 255 * 3 / NUM_LEDS ));
    modes.push_back(new CRingPaletteMode(NUM_LEDS, CloudColors_p, 1, LINEARBLEND, 50));
    modes.push_back(new CRingPaletteMode(NUM_LEDS, ForestColors_p, 255 / NUM_LEDS));
    modes.push_back(new CRingPaletteMode(NUM_LEDS, OceanColors_p, 255 * 2 / NUM_LEDS, LINEARBLEND, 100));
    modes.push_back(new CRingPaletteMode(NUM_LEDS, HeatColors_p, 255 / NUM_LEDS));
    
    
}

void loop() {
    static uint8_t currentMode = 0;
    static unsigned long tsMillis = millis();
    static unsigned long tsMillisLed = millis();
    static bool boardLedOn = false;

    if (millis() - tsMillisLed > 300) {
        tsMillisLed = millis();
        // Blink board LED
        digitalWrite(LED_PIN_BOARD, boardLedOn ? HIGH : LOW);
        boardLedOn = !boardLedOn;
    }
    

#ifdef TEST_LED_STRIP
    for( int i = 0; i < NUM_LEDS; i++) {
        if (i<61) {
            leds[i] = CRGB(0, 20, 0);
        } else if (i<61) {
            leds[i] = CRGB(20, 20, 0);
        } else if (i<122) {
            leds[i] = CRGB(20, 0, 0);
        } else {
            leds[i] = CRGB(0, 0, 20);
        } 
    }
    FastLED.show(50);
#else
    modes[currentMode]->draw(leds);
    FastLED.show(BRIGHTNESS);
#endif

  // Change modes every so often 
  if (millis() - tsMillis > CHANGE_MODE_SEC * 1000) {
    tsMillis = millis();
    currentMode++; 
    if (currentMode > modes.size()-1) {
      currentMode = 0;
    }
  }

  delay(10);
  yield();
}