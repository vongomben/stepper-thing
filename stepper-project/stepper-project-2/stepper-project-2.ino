// TODO

// https://github.com/GreyGnome/EnableInterrupt/wiki/Usage#pin--port-bestiary
// move to pin 10-15;


// CNC Shield Stepper  Control Demo
// Superb Tech
// www.youtube.com/superbtech

// These constants won't change. They're used to give names to the pins used:
const int analogInPin0 = A0;  // Analog input pin that the potentiometer is attached to
const int analogInPin1 = A1;  // Analog input pin that the potentiometer is attached to

int sensorValue0 = 0;
int sensorValue1 = 0;

const int step1 = 256;
const int step2 = 341;
const int step3 = 682;
const int step4 = 1023;

const int sw1 = 8;
const int sw2 = 9;
const int sw3 = 10;
const int sw4 = 11;

int switchValue01 = 0;
int switchValue02 = 0;
int switchValue03 = 0;
int switchValue04 = 0;



const int led0 = 6;
const int led1 = 4;
const int led2 = 2;
const int led3 = 5;

const int StepX = 52;
const int DirX = 34;

const int StepY = 50;
const int DirY = 40;

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
int temp = 800; // the higher, the slower
int dur = 20; // the higher, the longer
//int t = 2000;

int light = 255;


// Variables will change:
int ledState0 = HIGH;         // the current state of the output pin
int buttonState0;             // the current reading from the input pin
int lastButtonState0 = LOW;   // the previous reading from the input pin

int ledState1 = HIGH;         // the current state of the output pin
int buttonState1;             // the current reading from the input pin
int lastButtonState1 = LOW;   // the previous reading from the input pin


// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime0 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay0 = 50;    // the debounce time; increase if the output flickers
unsigned long lastDebounceTime1 = 0;  // the last time the output pin was toggled
unsigned long debounceDelay1 = 50;    // the debounce time; increase if the output flickers

void setup() {
  Serial.begin(9600);
  //digitalWrite(button, HIGH);
  //pinMode(button, INPUT);


  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  //  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  //  pinMode(sw4, INPUT_PULLUP);

  pinMode(DirX, OUTPUT);
  pinMode(StepX, OUTPUT);

  pinMode(DirY, OUTPUT);
  pinMode(StepY, OUTPUT);
  /* pinMode(StepY, OUTPUT);
    pinMode(DirY, OUTPUT);
    pinMode(StepZ, OUTPUT);
    pinMode( DirZ, OUTPUT);
  */


}

void loop() {
  // these two pots are used to change things dynamically, but are to be taken away in the future

  sensorValue0 = analogRead(analogInPin0);
  sensorValue1 = analogRead(analogInPin1);

  /*
    Serial.print(" POT 0 --> ");
    Serial.print(sensorValue0);
    Serial.print(" POT 1 --> ");
    Serial.print(sensorValue1);
    Serial.println();
  */


  // ------------------------------------------------------
  // PORT 0

  while (sensorValue0 < step2  ) {
    Serial.print(" STOP ");


    // read and update the switch's behaviour
    readSwitch();

    // stop motor X
    motorXStop();

    // update Pot value
    sensorValue0 = analogRead(analogInPin0);

    // turn off the LEDs
    analogWrite(led2, 0);


    // stop motor Y
    motorYStop();

    // update Pot value
    sensorValue1 = analogRead(analogInPin1);

    // turn off the LEDs
    analogWrite(led1, 0);


  }


  while (sensorValue0 >= step2) {
    Serial.print(" MOVE");
    readSwitch();

    sensorValue0 = analogRead(analogInPin0);
    int light0 = map(sensorValue0, step2, 1023, 0 , 255);
    analogWrite(led2, light0);

    sensorValue1 = analogRead(analogInPin1);

    //int dur = 200; // the higher, the longer

    temp = 800; // the higher, the slower 2400, 3600, 4200

    sensorValue1 = analogRead(analogInPin1);

    int light1 = map(sensorValue1, step2, 1023, 0 , 255);
    analogWrite(led1, light1);

    // control both motors
    motorMixSwitch(ledState0, ledState1);


  }

  
  // trying to implement a serial control over the device. 
  // this hasn't been updated to the motorMixSwitch function
  
  Serial.println();
  //delay(2);


}
