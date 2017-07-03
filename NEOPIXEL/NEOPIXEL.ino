#include <Adafruit_NeoPixel.h>

#include <EEPROM.h>

int neopixel = 3;
Adafruit_NeoPixel ring(12, neopixel);
int colorCount = 0;
int pinCount = 0;

uint32_t colors[] = {
  ring.Color(255, 0, 0),
  ring.Color(170, 85, 0),
  ring.Color(85, 170, 0),
  ring.Color(0, 255, 0),
  ring.Color(0, 170, 85),
  ring.Color(0, 86, 170),
  ring.Color(0, 0, 255),
  ring.Color(85, 0, 170),
  ring.Color(170, 0, 85),
};

void setup() {
  // put your setup code here, to run once:
  ring.begin();
  ring.setBrightness(10);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
    ring.setPixelColor(0, ring.Color(255, 0, 0));
    ring.setPixelColor(1, ring.Color(170, 85, 0));
    ring.setPixelColor(2, ring.Color(85, 170, 0));
    ring.setPixelColor(3, ring.Color(0, 255, 0));
    ring.setPixelColor(4, ring.Color(0, 170, 85));
    ring.setPixelColor(5, ring.Color(0, 85, 170));
    ring.setPixelColor(6, ring.Color(0, 0, 255));
    ring.setPixelColor(7, ring.Color(85, 0, 170));
    ring.setPixelColor(8, ring.Color(170, 0, 85));
    ring.setPixelColor(9, ring.Color(255, 255, 255));
    ring.setPixelColor(10, ring.Color(0, 0, 0));
    ring.setPixelColor(11, ring.Color(255, 0, 255));
    ring.show();
  */
  /*for (int j = 0; j < 9; j++){
    for (int i = 0; i < 12; i++) {
    ring.setPixelColor(i, colors[j]);
    ring.show();
    delay(100);
    }
    } */

  if (colorCount < 9) {
    if (pinCount < 12) {
      delay(100);
      
      ring.setPixelColor(pinCount, colors[colorCount]);
      pinCount++;
      ring.setPixelColor(pinCount - 1, ring.Color(0, 0, 0));
      ring.show();
    } else if (pinCount = 12) {
      colorCount++;
      pinCount = 0;
    }
  } else if (colorCount = 9){
    colorCount = 0;
  }

  //ring.setPixelColor(pinCount, ring.Color(0, 0, 0));
  //ring.show();
  Serial.println(pinCount);
}
