#include <math.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUM_LEDS 16
#define BRIGHTNESS 25
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
    randomSeed(analogRead(0));
}
//strip.setPixelColor(n,strip.Color(r,g,b,w))
void loop() {
  for(int i=0; i<16; i++) {
    int x=cos((float)i*PI/8);
    int y=sin((float)i*PI/8);
    strip.setPixelColor(i,strip.Color(255*(x+1)/2,255*(y+1)/2,0,0));
    Serial.println(x);
  }
}
