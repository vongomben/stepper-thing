
// Functions.

void on() {

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led0, HIGH);
}

void off() {

  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led0, LOW);


}

void onoff(int t) {

  Serial.println("LED 1");
  for (int x = 0; x < light; x++) {
    analogWrite(led1, x);
    delay(t);
  }

  for (int x = light; x > 0; x--) {
    analogWrite(led1, x);
    delay(t);
  }

  digitalWrite(led1, LOW);

  Serial.println("LED 2");

  for (int x = 0; x < light; x++) {
    analogWrite(led2, x);
    delay(t);
  }


  for (int x = light; x > 0; x--) {
    analogWrite(led2, x);
    delay(t);
  }

  digitalWrite(led2, LOW);

  Serial.println("LED 3");

  for (int x = 0; x < light; x++) {
    analogWrite(led3, x);
    delay(t);
  }

  for (int x = light; x > 0; x--) {
    analogWrite(led3, x);
    delay(t);
  }

  digitalWrite(led3, LOW);

  Serial.println("LED 4");


  for (int x = 0; x < light; x++) {
    analogWrite(led0, x);
    delay(t);
  }


  for (int x = light; x > 0; x--) {
    analogWrite(led0, x);
    delay(t);
  }
  digitalWrite(led0, LOW);

}

// Mixed Motors Management

void motorMixSwitch(int ledState0, int ledState1) {

//readSwitch();

  if (ledState1 == 0) {

    digitalWrite(DirY, LOW);

  } else if (ledState1 == 1) {

    digitalWrite(DirY, HIGH);

  }


  if (ledState0 == 0) {

    digitalWrite(DirX, LOW);

  } else if (ledState0 == 1) {

    digitalWrite(DirX, HIGH);

  }

  for (int x = 0; x < dur; x++) { // loop for 200 steps
    digitalWrite(StepY, HIGH);
    digitalWrite(StepX, HIGH);

    delayMicroseconds(temp);
    digitalWrite(StepY, LOW);
    digitalWrite(StepX, LOW);

    delayMicroseconds(temp);
  }

}





// X Motor Management

void motorXStop() {
  digitalWrite(StepX, LOW);
}

void motorYStop() {
  digitalWrite(StepY, LOW);
}


void readSwitch() {
 // switchValue01 = digitalRead(sw1);
  switchValue02 = digitalRead(sw2);
  switchValue03 = digitalRead(sw3);
 // switchValue04 = digitalRead(sw4);

 // Serial.print(" sw1 = ");
 // Serial.print(switchValue01);
 // Serial.print(" sw2 = ");
 // Serial.print(switchValue02);
 // Serial.print(" sw3 = ");
 // Serial.print(switchValue03);
 // Serial.print(" sw4 = ");
//  Serial.print(switchValue04);

  // If the switch changed, due to noise or pressing:
  if (switchValue03 != lastButtonState0) {
    // reset the debouncing timer
    lastDebounceTime0 = millis();
  }

  if ((millis() - lastDebounceTime0) > debounceDelay0) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (switchValue03 != buttonState0) {
      buttonState0 = switchValue03;

      // only toggle the LED if the new button state is HIGH
      if (buttonState0 == LOW) {
        ledState0 = !ledState0;
      }
    }
  }
  Serial.print(" ledState0 ");

  Serial.print(ledState0);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState0 = switchValue03;

  // MOTOR 2


  // If the switch changed, due to noise or pressing:
  if (switchValue02 != lastButtonState1) {
    // reset the debouncing timer
    lastDebounceTime1 = millis();
  }

  if ((millis() - lastDebounceTime1) > debounceDelay1) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (switchValue02 != buttonState1) {
      buttonState1 = switchValue02;

      // only toggle the LED if the new button state is HIGH
      if (buttonState1 == LOW) {
        ledState1 = !ledState1;
      }
    }
  }
  Serial.print(" ledState1 ");

  Serial.println(ledState1);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState1 = switchValue02;



}


/*
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'q') {
      //    motorYLeft();
      motorXLeft();

    }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'w') {
      //  motorYRight();
      motorXRight();

      //  delay(dur); // delay for 1 second
    }
    if (incomingByte == 'e') {
      //  motorYStop();
      motorYStop();
    }

    if (incomingByte == 'r') {
      //  motorYStop();
      motorYSwicth(ledState1);
    }


    if (incomingByte == 'O') {
      on();
    }

    if (incomingByte == 'I') {

      onoff(15);

    }

    if (incomingByte == 'U') {

      off();

    }

    if (incomingByte == 'T') {

      on();

    }



  }
  */
