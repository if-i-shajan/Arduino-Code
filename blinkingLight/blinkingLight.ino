/*
LED Pin	--> Connect To Arduino
Longer leg (+)	--> Digital Pin 8 (for example)
Shorter leg (–)	--> GND (through a 220Ω resistor if possible)
*/
int ledPin = 8;  // Connect LED to digital pin 8

void setup() {
  pinMode(ledPin, OUTPUT);  // Set pin as output
}

void loop() {
  digitalWrite(ledPin, HIGH);  // LED ON
  delay(1000);                 // Wait 1 second

  digitalWrite(ledPin, LOW);   // LED OFF
  delay(1000);                 // Wait 1 second
}
