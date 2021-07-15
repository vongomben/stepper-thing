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

// read sensor and debounce


void readSwitch() {

  switchValue01 = digitalRead(sw1);
  switchValue02 = digitalRead(sw2);
  switchValue03 = digitalRead(sw3);
  switchValue04 = digitalRead(sw4);
  
  Serial.print(" sw1 = ");
  Serial.print(switchValue01);
  Serial.print(" sw2 = ");
  Serial.print(switchValue02);
  Serial.print(" sw3 = ");
  Serial.print(switchValue03);
  Serial.print(" sw4 = ");
  Serial.print(switchValue04);

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
      if (buttonState0 == HIGH) {
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
      if (buttonState1 == HIGH) {
        ledState1 = !ledState1;
      }
    }
  }
  Serial.print(" ledState1 ");

  Serial.println(ledState1);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState1 = switchValue02;

}
