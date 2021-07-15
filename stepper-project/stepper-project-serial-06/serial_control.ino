void SerialControl(){
  
    if (Serial.available() > 0) {

    //motorStop();
    
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();



 if (incomingByte == 'l') {

      enableON();

    }

     if (incomingByte == 'p') {

      enableOFF();

    }



    if (incomingByte == 'q') {

      motorXLeft();

    }

    if (incomingByte == 'w') {

      motorXRight();

    }

    if (incomingByte == 'e') {

      motorXStop();
    }

    if (incomingByte == 'a') {

      motorYLeft();

    }
    if (incomingByte == 's') {

      motorYRight();

    }
    if (incomingByte == 'd') {

      motorYStop();
    }

    if (incomingByte == 'r') {

      motorZLeft();

    }
    if (incomingByte == 't') {

      motorZRight();

    }
    if (incomingByte == 'y') {

      motorZStop();
    }

    if (incomingByte == 'f') {

      motorALeft();

    }
    if (incomingByte == 'g') {

      motorARight();

    }
    if (incomingByte == 'h') {

      motorAStop();
    }

    if (incomingByte == 'v') {

      motorLeft();

    }
    if (incomingByte == 'b') {

      motorRight();

    }
    if (incomingByte == 'n') {

      motorStop();
    }



    if (incomingByte == 'r') {


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

      on1();

    }
    if (incomingByte == 'G') {

      off1();

    }


    if (incomingByte == 'Y') {

      on2();

    }
    if (incomingByte == 'H') {

      off2();

    }

    if (incomingByte == 'B') {

      on3();

    }
    if (incomingByte == 'N') {

      off3();

    }
    if (incomingByte == 'M') {

      on4();

    }
    if (incomingByte == 'L') {

      off4();

    }

  }

  
  
  }
