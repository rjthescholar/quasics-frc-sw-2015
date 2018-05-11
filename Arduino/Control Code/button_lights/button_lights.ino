// Based on https://www.arduino.cc/en/Tutorial/Debounce

int counter = 0;

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(14, PIN, NEO_GRB + NEO_KHZ800);


const int BUTTON_PIN = 2;
const int LED_PIN = 13;      // the number of the LED pin
#define INITIAL_LED_STATE   true

// Defines a simple class that will monitor a push-button, and can be used to
// decide when it's been pressed and released.  This is meant to allow the
// button to be used to move through a sequence of some sort (e.g., from one
// light pattern to another, to another, etc.).
class TransitionButton {
  private:
    const int buttonPin;
    const bool transitionOnPress;
    const unsigned long debounceDelayMsec;

    int lastButtonState = LOW;           // the previous (transient) reading from the input pin
    int buttonState = LOW;               // the last (stable) reading from the input pin
    unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
  
  public:
    /**
     * @param buttonPin         the pin being monitored for button presses
     * @param transitionOnPress if true, advance on button being pressed down; otherwise, on button release
     * @param debounceDelayMsec delay used to make sure that the button is in a stable state
     */
    TransitionButton(int buttonPin, bool transitionOnPress = true, unsigned long debounceDelayMsec = 50)
      : buttonPin(buttonPin), transitionOnPress(transitionOnPress), debounceDelayMsec(debounceDelayMsec)
    {
      pinMode(buttonPin, INPUT);
    }

    bool advancePosition() {
      const unsigned long now = millis();
      int reading = digitalRead(buttonPin);
      
      if (reading != lastButtonState) {
        lastDebounceTime = now;
        lastButtonState = reading;
      }
    
      if ((now - lastDebounceTime) > debounceDelayMsec) {
        // whatever the reading is at, it's been there for longer than the debounce
        // delay, so take it as the actual current state.
        if (reading != buttonState) {
          buttonState = reading;
    
          // We'll assume that we transition states on button down.
          return (buttonState == transitionOnPress);
        }
      }
    
      return false;
    }
};

//////////////////////////////////////////////////////////////////////////////
// The following sample program for the TransitionButton class uses it to move
// between 2 simple states (LED on and LED off).

TransitionButton button(BUTTON_PIN);



void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Starting up!\n");

  pinMode(LED_PIN, OUTPUT);

  // set initial LED state
  digitalWrite(LED_PIN, INITIAL_LED_STATE);

 strip.begin();
  strip.show();  
}

void x_loop() {
  static bool lit = INITIAL_LED_STATE;
  if (button.advancePosition()) {
    Serial.println("Advancing");
    lit = !lit;
    digitalWrite(LED_PIN, lit);
  }
}

void loop() {
  static bool lit = INITIAL_LED_STATE;
  if (button.advancePosition()) {
    Serial.println("Advancing...");
    counter = counter + 1;
    Serial.print("Counter == ");
    Serial.print(counter);
    Serial.println();
  }

  if (counter % 3 == 0){
    colorWipe(strip.Color(0, 0, 255), 17);
    colorWipe(strip.Color(0, 0, 0), 17);
  }
  else if (counter % 3 == 1){
    colorWipe(strip.Color(255, 0, 0), 17);
    colorWipe(strip.Color(0, 0, 0), 17);
  }
  else if (counter % 3 == 2){
    colorWipe(strip.Color(0, 255, 0), 17);
    colorWipe(strip.Color(0, 0, 0), 17);
  }

}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

