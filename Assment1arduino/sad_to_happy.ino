const int buttonPin = 2;
const int RledPin = 3;
const int GledPin = 4;
const int BledPin = 5;

int mood = 0;
const int neutralMood = 10;
unsigned long previousMillis = 0;
int fadingDirection = 1;
int buttonState = 0;
bool ButtonPressed = false;
unsigned long touchedTimer = 0;
unsigned long reducedTimer = 0;
const long unTouchInterval = 5000;
const long reducedInterval = 1000;


void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT);
  pinMode(RledPin,OUTPUT);
  pinMode(GledPin,OUTPUT);
  pinMode(BledPin,OUTPUT);

  mood = neutralMood;
}

void loop() {
  showLEDState(mood);

  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH && !ButtonPressed){
    mood = mood + 1;
    if(mood >20)mood = 20;

    touchedTimer = millis();
    ButtonPressed = true;
  }
  if(buttonState == LOW && ButtonPressed){
    ButtonPressed = false;
  }

  unsigned long currentTimer = millis();
  if(currentTimer - touchedTimer > unTouchInterval){
    if(currentTimer - reducedTimer > reducedInterval){
      mood = mood - 1;
      if(mood < 0) mood = 0;
      reducedTimer = currentTimer;
    }
  }
}

void showLEDState(int state){
  // put your main code here, to run repeatedly:
  float brightnessInterval = 255 / 10.0;
  if(mood >= neutralMood){
    analogWrite(RledPin,255);
    analogWrite(GledPin,brightnessInterval * (mood - neutralMood));
    analogWrite(BledPin,255 - brightnessInterval * (mood - neutralMood));
  }
  else{
    analogWrite(RledPin,255 - brightnessInterval * (neutralMood - mood));
    analogWrite(GledPin,brightnessInterval * (neutralMood - mood));
    analogWrite(BledPin,255);
  }

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > 1000){
    mood = mood + fadingDirection;
    if(mood >= 20 || mood <= 0)
      fadingDirection = -fadingDirection;
    previousMillis = currentMillis;
  }

}

