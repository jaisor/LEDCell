#include <Arduino.h>

#include <FastLED.h>

#define LED_PIN_BOARD     13
#define LED_PIN_STRIP     10
#define NUM_LEDS          61
#define BRIGHTNESS        250

#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

#define HONEY_DARK_ORANGE 0x5c2b00
#define HONEY_ORANGE 0xff8400
#define HONEY_LIGHT_ORANGE 0xffaa00
#define HONEY_YELLOW 0xffcc00

CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 50

CRGBPalette16 currentPalette;
TBlendType currentBlending;



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