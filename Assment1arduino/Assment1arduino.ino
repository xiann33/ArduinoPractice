/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

const int buttonPin = 2;      
const int RledPin = 3;
const int GledPin = 4;
const int BledPin = 5;

//variables will change
int buttonState = 0;
int ledcolor = 0;

bool ButtonPressed = false;
unsigned long previousMilllis = 0;
const long interval = 1000;
bool ledColorOrder = true;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);

  pinMode(buttonPin,INPUT);
}

// the loop function runs over and over again forever
void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && !ButtonPressed){
    ledcolor = ledcolor + 1;
    ButtonPressed = true;
    //delay(100);
  } 
  if(buttonState == HIGH && ButtonPressed){
    ButtonPressed = false;
  }
  if(ledcolor == 0){
    digitalWrite(RledPin,HIGH);
    digitalWrite(GledPin,HIGH);
    digitalWrite(BledPin,HIGH);
  }
  else if(ledcolor == 1){
    //red
    digitalWrite(RledPin,LOW);
    digitalWrite(GledPin,HIGH);
    digitalWrite(BledPin,HIGH);
  }
  else if(ledcolor == 2){
    //green
    digitalWrite(RledPin,HIGH);
    digitalWrite(GledPin,LOW);
    digitalWrite(BledPin,HIGH);
  }
  else if(ledcolor == 3){
    //blue
    digitalWrite(RledPin,HIGH);
    digitalWrite(GledPin,HIGH);
    digitalWrite(BledPin,LOW);
  }
  else if(ledcolor == 4){
    //
    digitalWrite(RledPin,LOW);
    digitalWrite(GledPin,LOW);
    digitalWrite(BledPin,HIGH);
  }
  else if(ledcolor == 5){
    //purple
    digitalWrite(RledPin,LOW);
    digitalWrite(GledPin,HIGH);
    digitalWrite(BledPin,LOW);
  }
  else if(ledcolor == 6){
    //cyan
    digitalWrite(RledPin,HIGH);
    digitalWrite(GledPin,LOW);
    digitalWrite(BledPin,LOW);
  }
  else if(ledcolor == 7){
    //white
    digitalWrite(RledPin,LOW);
    digitalWrite(GledPin,LOW);
    digitalWrite(BledPin,LOW);
  }
  else if(ledcolor == 8){
    ledcolor = 0;
  }
}
