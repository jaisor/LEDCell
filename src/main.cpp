#include <Arduino.h>
#include <FastLED.h>
#include <vector>

#include "modes/HoneyOrangeMode.h"
#include "modes/PaletteMode.h"

#define BRIGHTNESS        255  // 0-255
#define CHANGE_MODE_SEC   60

#define LED_PIN_BOARD     13
#define LED_PIN_STRIP     10
#define NUM_LEDS          61

#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

std::vector<CBaseMode*> modes;

void setup() {
  delay( 1000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN_STRIP, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( BRIGHTNESS );

  pinMode(LED_PIN_BOARD, OUTPUT);
  digitalWrite(LED_PIN_BOARD, HIGH);

  modes.push_back(new CHoneyOrangeMode(NUM_LEDS));
  modes.push_back(new CPaletteMode(NUM_LEDS, RainbowStripeColors_p, 1, NOBLEND, 25));
  modes.push_back(new CPaletteMode(NUM_LEDS, PartyColors_p, 1));
  modes.push_back(new CPaletteMode(NUM_LEDS, HeatColors_p, 255 / NUM_LEDS));
  modes.push_back(new CPaletteMode(NUM_LEDS, RainbowColors_p, 255 * 3 / NUM_LEDS ));
  modes.push_back(new CPaletteMode(NUM_LEDS, CloudColors_p, 1, NOBLEND, 50));
  modes.push_back(new CPaletteMode(NUM_LEDS, ForestColors_p, 255 / NUM_LEDS));
  modes.push_back(new CPaletteMode(NUM_LEDS, OceanColors_p, 255 * 2 / NUM_LEDS, NOBLEND, 100));
  modes.push_back(new CPaletteMode(NUM_LEDS, HeatColors_p, 255 / NUM_LEDS));
}

void loop() {
  static uint8_t currentMode = 0;
  static unsigned long tsMillis = millis();
  static bool boardLedOn = false;

  // Blink board LED
  digitalWrite(13, boardLedOn ? HIGH : LOW);
  boardLedOn = !boardLedOn;

  modes[currentMode]->draw(leds);

  FastLED.show(BRIGHTNESS);
  FastLED.delay(10);

  // Change modes every so often 
  if (millis() - tsMillis > CHANGE_MODE_SEC * 1000) {
    tsMillis = millis();
    currentMode++; 
    if (currentMode > modes.size()-1) {
      currentMode = 0;
    }
  }
}