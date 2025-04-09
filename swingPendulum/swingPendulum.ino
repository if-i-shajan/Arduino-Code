#include <Servo.h>
#include <math.h>  // Needed for sin()

Servo pendulum;

float angle = 0;         // Angle in radians (for sine)
float swingCenter = 90;  // Middle point of swing
float swingRange = 50;   // How wide the swing is
int delayTime = 10;      // Controls speed

void setup() {
  pendulum.attach(9);
}

void loop() {
  // Calculate smooth pendulum angle using sine wave
  float servoAngle = swingCenter + swingRange * sin(angle);

  pendulum.write((int)servoAngle);  // Move servo
  delay(delayTime);                 // Control swing speed

  angle += 0.05;  // Step through the sine wave
  if (angle > 2 * PI) {
    angle = 0;  // Reset after full cycle
  }
}