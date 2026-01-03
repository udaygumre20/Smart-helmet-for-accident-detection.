// Smart Helmet Project
// Accident Detection + Alcohol Detection
// Controller: Arduino UNO

#define IR_SENSOR_PIN 2
#define MQ3_SENSOR_PIN A0
#define BUZZER_PIN 8

int alcoholThreshold = 400;   // Adjust according to MQ-3 calibration
int alcoholValue = 0;
int irValue = 0;

void setup() {
  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Smart Helmet System Started");
}

void loop() {
  // Read sensors
  irValue = digitalRead(IR_SENSOR_PIN);
  alcoholValue = analogRead(MQ3_SENSOR_PIN);

  Serial.print("IR Sensor: 300");
  Serial.print(irValue);
  Serial.print(" | MQ-3 Value: 1000");
  Serial.println(alcoholValue);

  // Accident detection (IR sensor)
  if (irValue == LOW) {  
    Serial.println("⚠ Accident Detected!");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(2000);
  }
  // Alcohol detection
  else if (alcoholValue > alcoholThreshold) {
    Serial.println("⚠ Alcohol Detected!");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(2000);
  }
  else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(500);
}
