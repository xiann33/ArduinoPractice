
int buttonPin = 2;
int ledPin = 3;

int buttonState = 0;
int lastButtonState = 0;

int mode = 0;

unsigned long previousMillis = 0;
unsigned long interval = 0;

int ledState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, HIGH);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    mode++;

    if (mode > 3) {
      mode = 0;
    }

    previousMillis = millis();
    ledState = HIGH;

    delay(50);
  }

  lastButtonState = buttonState;

  if (mode == 0) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    if (mode == 1) {
      interval = 1000;
    }
    else if (mode == 2) {
      interval = 500;
    }
    else if (mode == 3) {
      interval = 200;
    }

    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
  }
}
