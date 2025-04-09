/*
LED Pin --> Connect To Arduino
Longer leg (+) --> Digital Pin 8
Shorter leg (–) --> GND (through a 220Ω resistor)

Servo Wire --> Arduino Pin
GND (Brown/Black) --> GND
VCC (Red) --> 5V
Signal (Orange) --> Pin 9
*/

#include <Servo.h>
#include <math.h>  // For sin()

Servo pendulum;

const int ledPin = 8;

float angle = 0.0;             // Angle in radians
float swingCenter = 90.0;      // Middle servo position
float swingRange = 80.0;       // Max swing from center (e.g. ±50°)
float angleStep = 0.05;        // How much angle increases each loop
int delayTime = 10;            // Delay for smooth swing

bool swingDone = false;        // To track when swing finishes

void setup() {
  pendulum.attach(9);           // Attach servo to pin 9
  pinMode(ledPin, OUTPUT);      // Set LED pin as output
}

void loop() {
  // Calculate smooth swing position using sine wave
  float servoAngle = swingCenter + swingRange * sin(angle);
  pendulum.write((int)servoAngle);
  delay(delayTime);

  angle += angleStep;

  // When one full swing is completed (2π radians)
  if (angle >= 2 * PI) {
    angle = 0; // Reset angle for next cycle

    // Blink LED once for 1 second (natural tick)
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}
