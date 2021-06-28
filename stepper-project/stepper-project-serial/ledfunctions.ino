
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
