// Mixed Motors Management

void motorMixSwitch(int ledState0, int ledState1, int ledState2, int ledState3) {

//  readSwitch();


  if (ledState0 == 0) {

    digitalWrite(DirX, LOW);

  } else if (ledState0 == 1) {

    digitalWrite(DirX, HIGH);

  }


  if (ledState1 == 0) {

    digitalWrite(DirY, LOW);

  } else if (ledState1 == 1) {

    digitalWrite(DirY, HIGH);

  }

  if (ledState2 == 0) {

    digitalWrite(DirZ, LOW);

  } else if (ledState2 == 1) {

    digitalWrite(DirZ, HIGH);

  }

  if (ledState3 == 0) {

    digitalWrite(DirA, LOW);

  } else if (ledState3 == 1) {

    digitalWrite(DirA, HIGH);

  }


  for (int x = 0; x < dur; x++) { // loop for 200 steps
    digitalWrite(StepY, HIGH);
    digitalWrite(StepX, HIGH);
    digitalWrite(StepZ, HIGH);
    digitalWrite(StepA, HIGH);

    delayMicroseconds(temp);

    digitalWrite(StepY, LOW);
    digitalWrite(StepX, LOW);
    digitalWrite(StepZ, LOW);
    digitalWrite(StepA, LOW);

    delayMicroseconds(temp);
  }

}

// read sensor and debounce


void readSwitch() {

  JSONVar myObject;


  // switchValue01 = digitalRead(sw1);
  switchValue01 = digitalRead(sw1);
  switchValue02 = digitalRead(sw2);
  switchValue03 = digitalRead(sw3);
  switchValue04 = digitalRead(sw4);
  // switchValue04 = digitalRead(sw4);

  myObject["sw1"] = switchValue01;
  myObject["sw2"] = switchValue02;
  myObject["sw3"] = switchValue03;
  myObject["sw4"] = switchValue04;




  /* Serial.print(" sw1 = ");
    Serial.print(switchValue01);
    Serial.print(" sw2 = ");
    Serial.print(switchValue02);
    Serial.print(" sw3 = ");
    Serial.print(switchValue03);
    Serial.print(" sw4 = ");
    Serial.print(switchValue04);
  */



  // ------------------------------------------------------------------------------------------



  // If the switch changed, due to noise or pressing:
  if (switchValue01 != lastButtonState0) {
    // reset the debouncing timer
    lastDebounceTime0 = millis();
  }

  if ((millis() - lastDebounceTime0) > debounceDelay0) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (switchValue01 != buttonState0) {
      buttonState0 = switchValue01;

      // only toggle the LED if the new button state is LOW
      if (buttonState0 == LOW) {
        ledState0 = !ledState0;
      }
    }
  }


  myObject["ledState0"] = ledState0;


  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState0 = switchValue01;



  // ------------------------------------------------------------------------------------------


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

      // only toggle the LED if the new button state is LOW
      if (buttonState1 == LOW) {
        ledState1 = !ledState1;
      }
    }
  }

  myObject["ledState1"] = ledState1;


  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState1 = switchValue02;


  // ------------------------------------------------------------------------------------------


  // MOTOR 3


  // If the switch changed, due to noise or pressing:
  if (switchValue03 != lastButtonState2) {
    // reset the debouncing timer
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime2) > debounceDelay2) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (switchValue03 != buttonState2) {
      buttonState2 = switchValue03;

      // only toggle the LED if the new button state is LOW
      if (buttonState2 == LOW) {
        ledState2 = !ledState2;
      }
    }
  }

  myObject["ledState2"] = ledState2;


  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState2 = switchValue03;

  // ------------------------------------------------------------------------------------------


  // MOTOR 4


  // If the switch changed, due to noise or pressing:
  if (switchValue04 != lastButtonState3) {
    // reset the debouncing timer
    lastDebounceTime3 = millis();
  }

  if ((millis() - lastDebounceTime3) > debounceDelay3) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (switchValue04 != buttonState3) {
      buttonState3 = switchValue04;

      // only toggle the LED if the new button state is LOW
      if (buttonState3 == LOW) {
        ledState3 = !ledState3;
      }
    }
  }

  myObject["ledState3"] = ledState3;


  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState3 = switchValue04;

  // ------------------------------------------------------------------------------------------




  String jsonString = JSON.stringify(myObject);

//   Serial.println(myObject);

}
