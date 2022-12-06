#include <Stepper.h>

const int stepsPerRevolution = 2048 ;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(12);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution/4);
  delay(500);

}