// CodeAlpha IoT Task 2: Sensor-Based Simulation
// Project: LDR-based automatic LED control
// Circuit: LDR voltage divider midpoint -> A0; LED anode -> D9 through 220 ohm resistor.

const int ldrPin = A0;
const int ledPin = 9;
const int threshold = 500; // Adjust after checking the LDR readings in simulation

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(ldrPin);
  Serial.print("Light sensor value: ");
  Serial.println(lightValue);

  // Typical divider: LDR to 5V, 10k resistor to GND.
  // With this arrangement, darker conditions usually give a lower reading.
  if (lightValue < threshold) {
    digitalWrite(ledPin, HIGH); // Dark: LED ON
  } else {
    digitalWrite(ledPin, LOW);  // Bright: LED OFF
  }

  delay(300);
}
