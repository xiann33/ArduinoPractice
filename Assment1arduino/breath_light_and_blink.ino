const int buttonPin = 2;
const int BLedPin = 9;
const int RLedPin = 10;
const int GLedPin = 11;
int buttonState = 0;

bool buttonPressed = false;
bool negativeDir = false;
unsigned long pressingTime = 0;
const int longPressInterval = 2000;

int currentMode = 0;
unsigned long blinkTimer = 0;
const int blinkInterval = 500;
bool blinkOn = true;

//0=white,1=red,2=blue,3=green,4=yellow...
int lightNum = 0;
int RLightColor = 0;
int GLightColor = 0;
int BLightColor = 0;

int RCurrentColor = 0;
int GCurrentColor = 0;
int BCurrentColor = 0;

const int fadeAmount = 2;
int fadeDirection = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT);
  pinMode(RLedPin,OUTPUT);
  pinMode(GLedPin,OUTPUT);
  pinMode(BLedPin,OUTPUT);
  Serial.begin(9600);
}

void loop(){
 // buttonState = digitalRead(buttonPin);

  //if(buttonState == LOW){
    //setRGBLEDColor(0,0,0);}
  //else{
    //setRGBLEDColor(255,255,255);}
  checkButton();
  updateLEDColor();
  setRGBLEDColor(RCurrentColor,GCurrentColor,BCurrentColor);
}

void setRGBLEDColor(int r,int g,int b){
  analogWrite(RLedPin,r);
  analogWrite(GLedPin,g);
  analogWrite(BLedPin,b);
}

void checkButton() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if(buttonState == LOW && !buttonPressed){
  pressingTime = millis();
  buttonPressed = true;
 }
 if(buttonState == HIGH && buttonPressed){
  unsigned long currentTime = millis();
  if(currentTime - pressingTime < longPressInterval){
    //short click
    //Serial.println("short click");
    changeLEDColor();

  }
  else{
    //long press
    //Serial.println("long press");
    changeMode();
  }
  buttonPressed = false;
 }

}

void changeLEDColor(){
  lightNum = lightNum + 1;
  if(lightNum >= 5)
  lightNum = 0;

 if(lightNum == 0){
  //white
  RLightColor = 0;
  GLightColor = 0;
  BLightColor = 0;
 }
 if(lightNum == 1){
  //red
  RLightColor = 0;
  GLightColor = 255;
  BLightColor = 255;
 }
 if(lightNum == 2){
  //green
  RLightColor = 255;
  GLightColor = 0;
  BLightColor = 255;
 }
 if(lightNum == 3){
  //blue
  RLightColor = 255;
  GLightColor = 255;
  BLightColor = 0;
 }
 if(lightNum == 4){
  //yellow
  RLightColor = 0;
  GLightColor = 0;
  BLightColor = 255;
 }
  RCurrentColor = RLightColor;
  GCurrentColor = GLightColor;
  BCurrentColor = BLightColor;
}

void changeMode(){
  currentMode = currentMode + 1;
  if(currentMode >= 3){
    currentMode = 0;
  }

  if(currentMode == 1){
    blinkTimer = 0;
    blinkOn = true;
  }

  //if(currentMode == 2){
    //fadeDirection = 1;
  //}
}

void updateLEDColor(){
  if(currentMode == 0){
    RCurrentColor = RLightColor;
    GCurrentColor = GLightColor;
    BCurrentColor = BLightColor;
  }
  else if(currentMode == 1){
    //Blink Mode
    unsigned long currentTime = millis();
    if(currentTime - blinkTimer > blinkInterval){
      blinkOn = !blinkOn;
      blinkTimer = currentTime;
    }
    if(blinkOn){
      RCurrentColor = RLightColor;
      GCurrentColor = GLightColor;
      BCurrentColor = BLightColor;
    }
    else{
      RCurrentColor = 255;
      GCurrentColor = 255;
      BCurrentColor = 255;
    }
  }
  else if(currentMode == 2){
    bool negativeDir = false;
    //Breathing Light Mode
    if(RLightColor == 0){
     RCurrentColor = RCurrentColor + fadeDirection * fadeAmount;
     if(RCurrentColor > (255 - RLightColor)||(RCurrentColor < 0)){
      negativeDir = true;
     }
     if(RCurrentColor < 0) RCurrentColor = 0;
     if(RCurrentColor > 255) RCurrentColor = 255;
    }
      
     if(GLightColor == 0){
     GCurrentColor = GCurrentColor + fadeDirection * fadeAmount;
     if(GCurrentColor > (255 - GLightColor)||(GCurrentColor < 0)){
      negativeDir = true;
     }
     if(GCurrentColor < 0) GCurrentColor = 0;
     if(GCurrentColor > 255) GCurrentColor = 255;
    }

    if(BLightColor == 0){
     BCurrentColor = BCurrentColor + fadeDirection * fadeAmount;
    if(BCurrentColor > (255 - BLightColor)||(BCurrentColor < 0)){
      negativeDir = true;
     }
     if(BCurrentColor < 0) BCurrentColor = 0;
     if(BCurrentColor > 255) BCurrentColor = 255;
    }

    if(negativeDir){  
      fadeDirection = -fadeDirection;    
    }AAAAA                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    //if(RCurrentColor > RLightColor || GCurrentColor > GLightColor || BCurrentColor > BLightColor){
      //fadeDirection = -fadeDirection;
    //}
    //else if(RCurrentColor < 0 || GCurrentColor < 0 || BCurrentColor < 0){
      //fadeDirection = -fadeDirection;
    //}
    delay(10);
  }
}

