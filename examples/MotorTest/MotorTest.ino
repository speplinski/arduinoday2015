
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor1 = AFMS.getMotor(2);
Adafruit_DCMotor *myMotor2 = AFMS.getMotor(4);

void setup() {
  AFMS.begin();  
  
  myMotor1->setSpeed(255);
  myMotor1->run(FORWARD);
  // turn on motor
  myMotor2->setSpeed(255);
  myMotor2->run(FORWARD);
}

void loop() {
  uint8_t i;
  
 /*
  for (i=255; i!=0; i--) {
    myMotor->setSpeed(i);  
    delay(10);
  }

  Serial.print("tech");
  myMotor->run(RELEASE);
  delay(1000);
  */
}
