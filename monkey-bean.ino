#include <Adafruit_NeoPixel.h>

#define PIN            1
#define NUMPIXELS      2

bool motionDetected = false;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  // Enable low-g motion events to be detected
  Bean.enableMotionEvent(HIGH_G_EVENT);
  
  // Make sure accelerometer is in normal power mode
  if (Bean.getAccelerometerPowerMode() != VALUE_NORMAL_MODE) {
    // Set accelerometer power mode to normal
    Bean.setAccelerometerPowerMode(VALUE_NORMAL_MODE);
  }

  pixels.begin(); // This initializes the NeoPixel library.
  pixels.show(); // Initialize all pixels to 'off'

}

void loop() {
  if (Bean.checkMotionEvent(HIGH_G_EVENT) && !motionDetected) {
    motionDetected = true;
  } else if (!Bean.checkMotionEvent(HIGH_G_EVENT) && !motionDetected) {
    Bean.sleep(500);
  }
  
  if (motionDetected) {
    setGreen(0);
    setGreen(1);
    pixels.show();
    Bean.sleep(2000);
    setOff(0);
    setOff(1);
    pixels.show();
    motionDetected = false;
  }
}


void setRed(uint16_t pin) {
  pixels.setPixelColor(pin, pixels.Color(255, 0, 0));
}

void setGreen(uint16_t pin) {
  pixels.setPixelColor(pin, pixels.Color(0, 255, 0));
}

void setBlue(uint16_t pin) {
  pixels.setPixelColor(pin, pixels.Color(0, 0, 255));
}

void setWhite(uint16_t pin) {
  pixels.setPixelColor(pin, pixels.Color(255, 255, 255));
}

void setOff(uint16_t pin) {
  pixels.setPixelColor(pin, pixels.Color(0, 0, 0));
}

