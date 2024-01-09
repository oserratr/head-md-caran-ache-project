#define VIBRATOR_PIN 15

void setup() {
  pinMode(VIBRATOR_PIN, OUTPUT);
}

void loop() {
  // Activer le moteur vibreur pendant 0.5 seconde
  digitalWrite(VIBRATOR_PIN, HIGH);
  delay(100);

  // Désactiver le moteur vibreur pendant 0.5 seconde
  digitalWrite(VIBRATOR_PIN, LOW);
  delay(100);
}
