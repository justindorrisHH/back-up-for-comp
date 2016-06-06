// grbw  neo-pixel modified by CW Coleman
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 16

#define BRIGHTNESS 75

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
int j = 15;  int i = 0; int count = 0;
int red = 100;  int green = 100;int blue = 100;

void loop() {
  // Some example procedures showing how to display to the pixels:

  strip.setPixelColor(i,red,green,blue );
  strip.setPixelColor(j,red,green,blue );
  strip.show();

    delay(100); // Delay for a period of time (in milliseconds).
    j--;
    i++;
    
    if (j < 0) j = 15;
    if (i > 16) i = 0;

    if (count > 16) {red = 255; green = 255; blue = 255;};//white
    if (count > 32) {red = 255; green = 0; blue = 0;};//red
    if (count > 64) {red = 0; green = 162; blue = 0;};//green
    if (count > 96) {red = 0; green = 0; blue = 162;};//blue
    if (count > 112) {red = 100; green = 100; blue = 0;};//yellow
    if (count > 128) {red = 255; green = 0; blue = 255;};//purple
    if (count > 144) {red = 102; green = 255; blue = 255;};//cyan
    if (count > 160) {red = 90; green = 255; blue = 0;count = 0;}//lime
    
    count++;
}



