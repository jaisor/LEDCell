#include <Arduino.h>

#include <FastLED.h>

#define LED_PIN_BOARD     13
#define LED_PIN_STRIP     10
#define NUM_LEDS          50
#define BRIGHTNESS        250

#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 50

CRGBPalette16 currentPalette;
TBlendType currentBlending;

extern const TProgmemRGBPalette16 HoneyOrange_p FL_PROGMEM =
{
    0xff623b,
    0xff8400,
    0xffd321,
    0xff8400
};

void fillLEDsFromPaletteColors( uint8_t colorIndex)
{
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, BRIGHTNESS, currentBlending);
        colorIndex++;
    }
}

void setup() {
  delay( 1000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN_STRIP, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( BRIGHTNESS );

  currentPalette = HoneyOrange_p; //LavaColors_p;
  currentBlending = LINEARBLEND;

  pinMode(LED_PIN_BOARD, OUTPUT);
  digitalWrite(LED_PIN_BOARD, HIGH);
}

void loop() {
  static uint8_t startIndex = 0;
  static bool boardLedOn = false;

  // Blink board LED
  digitalWrite(13, boardLedOn ? HIGH : LOW);
  boardLedOn = !boardLedOn;

  startIndex++;
  fillLEDsFromPaletteColors(startIndex);

  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}