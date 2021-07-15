
// Motor Management

// ALL MOTORS





void motorStop() {
  digitalWrite(ENABLE, LOW);
  digitalWrite(StepX, LOW);
  digitalWrite(StepY, LOW);
  digitalWrite(StepZ, LOW);
  digitalWrite(StepA, LOW);

}


void motorLeft() {
  digitalWrite(ENABLE, HIGH);
  digitalWrite(DirX, LOW);
  digitalWrite(DirY, LOW);
  digitalWrite(DirZ, LOW);
  digitalWrite(DirA, LOW);

  for (int x = 0; x < dur; x++) { // loop for 200 steps
    digitalWrite(StepX, HIGH);
    digitalWrite(StepY, HIGH);
    digitalWrite(StepZ, HIGH);
    digitalWrite(StepA, HIGH);
    delayMicroseconds(temp);
    digitalWrite(StepX, LOW);
    digitalWrite(StepY, LOW);
    digitalWrite(StepZ, LOW);
    digitalWrite(StepA, LOW);

    delayMicroseconds(temp);
  }

}

void motorRight() {
  digitalWrite(ENABLE, HIGH);

  digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise
  digitalWrite(DirY, HIGH);
  digitalWrite(DirZ, HIGH);
  digitalWrite(DirA, HIGH);

  for (int x = 0; x < dur; x++) { // loop for 200 steps

    digitalWrite(StepX, HIGH);
    digitalWrite(StepY, HIGH);
    digitalWrite(StepZ, HIGH);
    digitalWrite(StepA, HIGH);

    delayMicroseconds(temp);

    digitalWrite(StepX, LOW);
    digitalWrite(StepY, LOW);
    digitalWrite(StepZ, LOW);
    digitalWrite(StepA, LOW);

    delayMicroseconds(temp);
  }

}



//
//
//              X Motor
//
//

void motorXStop() {
  digitalWrite(ENABLE, LOW);

  digitalWrite(StepX, LOW);
}


void motorXLeft() {
  digitalWrite(ENABLE, HIGH);

  digitalWrite(DirX, LOW);

  for (int x = 0; x < dur; x++) { // loop for 200 steps
    digitalWrite(StepX, HIGH);
    delayMicroseconds(temp);
    digitalWrite(StepX, LOW);

    delayMicroseconds(temp);
  }

}

void motorXRight() {
  digitalWrite(ENABLE, HIGH);

  digitalWrite(DirX, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise

  for (int x = 0; x < dur; x++) { // loop for 200 steps
    digitalWrite(StepX, HIGH);
    delayMicroseconds(temp);
    digitalWrite(StepX, LOW);

    delayMicroseconds(temp);
  }

}


//
//
//              Y Motor
//
//

void motorYStop() {
  digitalWrite(ENABLE, LOW);

  digitalWrite(StepY, LOW);
}

void motorYLeft() {
  digitalWrite(ENABLE, HIGH);

  digitalWrite(DirY, LOW);

  for (int x = 0; x < dur; x++) { // loop for 200 steps
    digitalWrite(StepY, HIGH);
    delayMicroseconds(temp);
    digitalWrite(StepY, LOW);
    delayMicroseconds(temp);
  }

}

void motorYRight() {
  digitalWrite(ENABLE, HIGH);

  digitalWrite(DirY, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise

  for (int x = 0; x < dur; x++) { // loop for 200 steps
    digitalWrite(StepY, HIGH);
    delayMicroseconds(temp);
    digitalWrite(StepY, LOW);
    delayMicroseconds(temp);
  }

}



//
//
//              Z Motor
//
//

void motorZStop() {
  digitalWrite(ENABLE, LOW);

  digitalWrite(StepZ, LOW);
}

void motorZLeft() {
  digitalWrite(ENABLE, HIGH);

  digitalWrite(DirZ, LOW);

  for (int x = 0; x < dur; x++) { // loop for 200 steps
    digitalWrite(StepZ, HIGH);
    delayMicroseconds(temp);
    digitalWrite(StepZ, LOW);
    delayMicroseconds(temp);
  }

}

void motorZRight() {
  digitalWrite(ENABLE, HIGH);

  digitalWrite(DirZ, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise

  for (int x = 0; x < dur; x++) { // loop for 200 steps
    digitalWrite(StepZ, HIGH);
    delayMicroseconds(temp);
    digitalWrite(StepZ, LOW);
    delayMicroseconds(temp);
  }

}


//
//
//              A Motor
//
//

void motorAStop() {
  digitalWrite(ENABLE, LOW);

  digitalWrite(StepA, LOW);
}

void motorALeft() {
  digitalWrite(ENABLE, HIGH);

  digitalWrite(DirA, LOW);

  for (int x = 0; x < dur; x++) { // loop for 200 steps
    digitalWrite(StepA, HIGH);
    delayMicroseconds(temp);
    digitalWrite(StepA, LOW);
    delayMicroseconds(temp);
  }

}

void motorARight() {
  digitalWrite(ENABLE, HIGH);

  digitalWrite(DirA, HIGH); // set direction, HIGH for clockwise, LOW for anticlockwise

  for (int x = 0; x < dur; x++) { // loop for 200 steps
    digitalWrite(StepA, HIGH);
    delayMicroseconds(temp);
    digitalWrite(StepA, LOW);
    delayMicroseconds(temp);
  }

}
