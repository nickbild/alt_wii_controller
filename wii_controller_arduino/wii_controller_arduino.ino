#include <Servo.h>

Servo button2;
Servo buttonUp;

int dir = 2;
int step = 3;

int left = 4;
int right = 5;
int item = 6;
int gas = 7;

int stepper_pos = 0;

void setup() {
  pinMode(dir, OUTPUT);
  pinMode(step, OUTPUT);

  pinMode(left, INPUT_PULLUP);
  pinMode(right, INPUT_PULLUP);
  pinMode(gas, INPUT_PULLUP);
  pinMode(item, INPUT_PULLUP);

  button2.attach(11);
  buttonUp.attach(10);
}

void loop() {
  // Left and right turns (servo).

  if (digitalRead(left) == HIGH && digitalRead(right) == HIGH && stepper_pos != 0) {
    if (stepper_pos == -90) {
      digitalWrite(dir, 0);
    } else if (stepper_pos == 90) {
      digitalWrite(dir, 1);
    }
    
    for (int i=0; i< 30; i++) {
      digitalWrite(step, 1);
      delay(5);
      digitalWrite(step, 0);
      delay(5);
    }

    stepper_pos = 0;
  }
  
  if (digitalRead(left) == LOW && stepper_pos == 0) {
    digitalWrite(dir, 1);
    
    for (int i=0; i< 30; i++) {
      digitalWrite(step, 1);
      delay(5);
      digitalWrite(step, 0);
      delay(5);
    }

    stepper_pos = -90;
  }

  if (digitalRead(right) == LOW && stepper_pos == 0) {
    digitalWrite(dir, 0);
    
    for (int i=0; i< 30; i++) {
      digitalWrite(step, 1);
      delay(5);
      digitalWrite(step, 0);
      delay(5);
    }

    stepper_pos = 90;
  }

  // Gas and use item (servos).

  if (digitalRead(gas) == LOW) {
    button2.write(108);
  } else {
    button2.write(90);
  }

  if (digitalRead(item) == LOW) {
    buttonUp.write(70);
  } else {
    buttonUp.write(90);
  }

}
