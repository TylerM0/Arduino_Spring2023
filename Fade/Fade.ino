//Programmer: Tyler Mattson
//Date: 3.14.2023
//Program: Fade
//Resource: https://arduinointro.com/projects/2-leds-alternate-fade-effect-using-the-for-loop



int ledPin11 = 11;  
int ledPin10 = 10;

void setup() {
  pinMode(ledPin11, OUTPUT);   
  pinMode(ledPin10, OUTPUT);   
}

void loop() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue = fadeValue+5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin11, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue = fadeValue-5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin11, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue = fadeValue+5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin10, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue = fadeValue-5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin10, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  
}
