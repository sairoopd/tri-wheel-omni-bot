// ****************************************************
// Libraries
// ****************************************************
#include "Arduino.h"

// ****************************************************
// Motor Controller Ports
// ****************************************************
#define pwmA 3
#define dirA 2

#define pwmB 5
#define dirB 9

#define pwmC 6
#define dirC 10

// ****************************************************
// Motor Controllers
// ****************************************************
typedef struct {
  int pulse;
  bool direction;
} MotorValues;

MotorValues motorA;
MotorValues motorB;
MotorValues motorC;

// Globals
double sideStep = 0.60; // Limiting factor to ensure direct side to side movement
double side =0.50;

// ****************************************************
// Stops the motors
// RETURNS: none
// ****************************************************
void allStop() {
 analogWrite(pwmA, 0);
 analogWrite(pwmB, 0);
 analogWrite(pwmC, 0);
}

// ****************************************************
// Sets the PWM motor values
// RETURNS: none
// ****************************************************
void commandMotors() {
 analogWrite(pwmA, motorA.pulse);
 analogWrite(pwmB, motorB.pulse);
 analogWrite(pwmC, motorC.pulse);
}

// ****************************************************
// Forward motor movement
// RETURNS: none
// ****************************************************
void forwardMovement(int a) {  
  // Set motor directions
  digitalWrite(dirA, HIGH); digitalWrite(dirB, HIGH); digitalWrite(dirC, LOW);
  
  // Ramp up the appropriate motors
  for (int i = 0; i < a; i++)
  { motorA.pulse = 0; motorB.pulse = 625; motorC.pulse = 625; commandMotors(); delay(25); }  
  allStop();
}

// ****************************************************
// Backward motor movement
// RETURNS: none
// ****************************************************
void backwardMovement(int a) {  
  // Set motor directions
  digitalWrite(dirA, HIGH); digitalWrite(dirB, LOW); digitalWrite(dirC, HIGH);
  
  // Ramp up the appropriate motors
  for (int i = 0; i < a; i++)
  { motorA.pulse = 0; motorB.pulse =625 ; motorC.pulse = 625; commandMotors(); delay(25); }
  allStop();
}

// ****************************************************
// Right motor movement
// RETURNS: none
// ****************************************************
void rightMovement (int a) {  
  // Set motor directions
  digitalWrite(dirA, LOW); digitalWrite(dirB, HIGH); digitalWrite(dirC, HIGH);
  
  // Ramp up the appropriate motors
  for (int i = 0; i < a; i++)
  { motorA.pulse = 100; motorB.pulse = 60 ; motorC.pulse = 60; commandMotors(); delay(25); }
  allStop();
}

// ****************************************************
// Left motor movement
// RETURNS: none
// ****************************************************
void leftMovement (int a) {  
  // Set motor directions
  digitalWrite(dirA, HIGH); digitalWrite(dirB, LOW); digitalWrite(dirC, LOW);
  
  // Ramp up the appropriate motors
  for (int i = 0; i < a; i++)
  { motorA.pulse = 625; motorB.pulse = int (625 * sideStep); motorC.pulse = int (625 * sideStep); commandMotors(); delay(25); }
  allStop();
}

// ****************************************************
// Spin Clowise motor movement
// RETURNS: none
// ****************************************************
void spinClockwise(int a) {  
  // Set motor directions
  digitalWrite(dirA, HIGH); digitalWrite(dirB, HIGH); digitalWrite(dirC, HIGH);
  
  // Ramp up the appropriate motors
  for (int i = 0; i < a; i++)
  { motorA.pulse = 625; motorB.pulse = 625; motorC.pulse = 625; commandMotors(); delay(25); }
  allStop();
}

// ****************************************************
// Spin Counter Clockwise motor movement
// RETURNS: none
// ****************************************************
void spinCounterClockwise (int a) {
  // Set motor directions
  digitalWrite(dirA, LOW); digitalWrite(dirB, LOW); digitalWrite(dirC, LOW);
  
  // Ramp up the appropriate motors
  for (int i = 0; i < a; i++)
  { motorA.pulse = 625; motorB.pulse = 625; motorC.pulse = 625; commandMotors(); delay(25); }
  allStop();
}

// ****************************************************
// Initial setup function, called once
// RETURNS: none
// ****************************************************
void setup() {
  
  // Debug Serial
  Serial.begin(115200);   

  // Set motor controller communication pins as outputs
  pinMode(dirA, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(dirB, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(dirC, OUTPUT);
  pinMode(pwmC, OUTPUT);
  
  // Command all motors to stop
  allStop();
}

// ****************************************************
// Main program loop
// RETURNS: none
// ****************************************************
void loop() {
 // forwardMovement(100);
  //delay(1000);
  //backwardMovement(100);
  //delay(1000);
  rightMovement(50);
  //delay(1000);
  //leftMovement(200);
  //delay(1000);
  //spinClockwise(200);
  //delay(1000);
 // spinCounterClockwise(200);
}
