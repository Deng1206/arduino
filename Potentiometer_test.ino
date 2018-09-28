#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`

#include "images.h"

SSD1306Wire  display(0x3c, 21, 22);
int ledpin = 32;
int val = 0;

#define DEMO_DURATION 3000
typedef void (*Demo)(void);

int demoMode = 0;
int counter = 1;

void setup() {
  Serial.begin(9600);
  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

}

void drawFontFaceDemo() {
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_24);
    display.drawString(40, 15, String(analogRead(ledpin)));
}
Demo demos[] = {drawFontFaceDemo};

void loop() {
  display.clear();
  val = analogRead(ledpin);
  Serial.println(val);
  demos[demoMode]();
  display.display();
  delay(50);
}
