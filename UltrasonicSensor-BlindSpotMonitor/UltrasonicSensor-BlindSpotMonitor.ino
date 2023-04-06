//Programmer: Tyler Mattson
//Date: 3.16.2023
//Program: Blind Spot Monitor
//Resource: https://bit.ly/3LuCv0C
/*
 * This program will determine distances approaching vehicles that are in your blind spot and it will also turn on a warning light.
 */


int trigPin = 7;
int echoPin = 6;
int LEDlampBlue = 9;
int LEDlampWhite = 10;
int LEDlampGreen = 11; 
int soundbuzzer = 3;
int sound  = 500;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin,  OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDlampBlue, OUTPUT);
  pinMode(LEDlampWhite,  OUTPUT);
  pinMode(LEDlampGreen, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}
void  loop() {
  long durationindigit, distanceincm;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  durationindigit = pulseIn(echoPin, HIGH);
  distanceincm = (durationindigit/5) / 29.1;
 
  if (distanceincm < 50) {
      digitalWrite(LEDlampGreen, HIGH);
}
  else {
      digitalWrite(LEDlampGreen,  LOW);
  }
  
  if (distanceincm < 20) {
    digitalWrite(LEDlampWhite,  HIGH);
}
  else {
    digitalWrite(LEDlampWhite,LOW);
  }
  if (distanceincm  < 5) {
    digitalWrite(LEDlampBlue, HIGH);
    sound = 1000;
}
  else  {
    digitalWrite(LEDlampBlue,LOW);
  }
 
  if (distanceincm > 5 ||  distanceincm <= 0){
    Serial.println("Outside the permissible range of distances");
    noTone(soundbuzzer);
  }
  else {
    Serial.print(distanceincm);
    Serial.println("  cm");
    tone(soundbuzzer, sound);
  }
  
  delay(300);
}
