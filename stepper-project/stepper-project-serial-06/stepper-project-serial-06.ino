// TODO

// https://github.com/GreyGnome/EnableInterrupt/wiki/Usage#pin--port-bestiary
// move to pin 10-15;


// CNC Shield Stepper  Control Demo
// Superb Tech
// www.youtube.com/superbtech


#include <Arduino_JSON.h>

// These constants won't change. They're used to give names to the pins used:
const int analogInPin0 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin1 = A1;  // Analog input pin that the potentiometer is attached to

int sensorValue0 = 0;
int sensorValue1 = 0;

const int step1 = 256;
const int step2 = 341;
const int step3 = 682;
const int step4 = 1023;

const int sw1 = 10;//7;
const int sw2 = 11;//9;
const int sw3 = 9; //10;
const int sw4 = 7; // 11;

int switchValue01 = 0;
int switchValue02 = 0;
int switchValue03 = 0;
int switchValue04 = 0;



const int led0 =  2;//6;
const int led1 = 4;
const int led2 = 5; //2;
const int led3 = 6; //5;

const int StepX = 52;
const int DirX = 34;

const int StepY = 50;
const int DirY = 40;

const int StepZ = 46;
const int DirZ = 36;

const int StepA = 48;
const int DirA = 38;

const int ENABLE = 15;

int Dir = 0;
/*const int StepY = 3;
  const int DirY = 6;
  const int StepZ = 4;
  const int DirZ = 7;
*/
int incomingByte;      // a variable to read incoming serial data into

//int numberOfSteps = 200;
//int pulseWidthMicros = 20;  // microseconds
//int millisbetweenSteps = 250; // milliseconds - or try 1000 for slower steps
int state = 1;
int temp = 800; // the higher, the slower 800
int dur = 100; // the higher, the longer20
//int t = 2000;

int light = 255;


// Variables will change:
int ledState0 = HIGH;         // the current state of the output pin
int buttonState0;             // the current reading from the input pin
int lastButtonState0 = LOW;   // the previous reading from the input pin

int ledState1 = HIGH;         // the current state of the output pin
int buttonState1;             // the current reading from the input pin
int lastButtonState1 = LOW;   // the previous reading from the input pin

int ledState2 = HIGH;         // the current state of the output pin
int buttonState2;             // the current reading from the input pin
int lastButtonState2 = LOW;   // the previous reading from the input pin

int ledState3 = HIGH;         // the current state of the output pin
int buttonState3;             // the current reading from the input pin
int lastButtonState3 = LOW;   // the previous reading from the input pin


// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime0 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay0 = 50;    // the debounce time; increase if the output flickers

unsigned long lastDebounceTime1 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay1 = 50;    // the debounce time; increase if the output flickers

unsigned long lastDebounceTime2 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay2 = 50;    // the debounce time; increase if the output flickers

unsigned long lastDebounceTime3 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay3 = 50;    // the debounce time; increase if the output flickers


void potRead() {

  sensorValue0 = analogRead(analogInPin0);
  sensorValue1 = analogRead(analogInPin1);

}


void enableON() {

  digitalWrite(ENABLE, HIGH);

}

void enableOFF() {

  digitalWrite(ENABLE, LOW);

}




void setup() {
  Serial.begin(9600);
  //digitalWrite(button, HIGH);
  //pinMode(button, INPUT);


  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(ENABLE, OUTPUT);
  enableON();
  //  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  pinMode(sw4, INPUT_PULLUP);


  pinMode(DirX, OUTPUT);
  pinMode(StepX, OUTPUT);

  pinMode(DirY, OUTPUT);
  pinMode(StepY, OUTPUT);

  pinMode(DirZ, OUTPUT);
  pinMode(StepZ, OUTPUT);

  pinMode(DirA, OUTPUT);
  pinMode(StepA, OUTPUT);



  /* pinMode(StepY, OUTPUT);
    pinMode(DirY, OUTPUT);
    pinMode(StepZ, OUTPUT);
    pinMode( DirZ, OUTPUT);
  */


}

void loop() {

  potRead();
  readSwitch();

  //  motorMixSwitch(ledState0, ledState1, ledState2, ledState3);

  SerialControl();

  // ------------------------------------------------------
  // PORT 0

  while (sensorValue0 < step1  ) {
    //Serial.println(" 1 ");
    //Serial.println(sensorValue0);

    potRead();
    readSwitch();
    motorStop();
  }

  while ((sensorValue0 >= step1) && (sensorValue0 < step2  )) {

     Serial.println(" 2 ");
    //Serial.println(sensorValue0);

    potRead();
    readSwitch();
    //motorMixSwitch(ledState0, ledState1, ledState2, ledState3, 4800);
    SerialControl();
  }
  while ((sensorValue0 >= step2) && (sensorValue0 < step3)) {
    //Serial.println(" 3 ");
    //Serial.println(sensorValue0);
    enableON();
    potRead();
    readSwitch();
    motorMixSwitch(ledState0, ledState1, ledState2, ledState3, 2400);

  }

  while (sensorValue0 >= step3) {
    // Serial.println(" 4 ");
    //Serial.println(sensorValue0);
    potRead();
    readSwitch();
    motorMixSwitch(ledState0, ledState1, ledState2, ledState3, 1600);

  }




  Serial.println();
  delay(2);


}
