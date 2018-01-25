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

//set up variables
int red,green,blue,white;
//set first led and total leds
int first = 10;
int leds = 16;
int count = 0;
int rainbowmod=10;
int i=0;

void loop() {

  strip.setPixelColor(i, strip.Color(max(abs(count*rainbowmod%765-382)-127,0),max(255-abs(count*rainbowmod%765-255),0),max(255-abs(count*rainbowmod%765-510),0),0 ));
  delay(20);
  strip.show();
  count++;
  i++;
  i%=16;

}

