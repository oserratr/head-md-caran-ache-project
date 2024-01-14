#define VIBRATOR_PIN 15

void setup() {
  pinMode(VIBRATOR_PIN, OUTPUT);
}

void loop() {

        digitalWrite(VIBRATOR_PIN, HIGH);
      delay(300);
      digitalWrite(VIBRATOR_PIN, LOW);


  delay(600);

  digitalWrite(VIBRATOR_PIN, HIGH);
  delay(200);
  digitalWrite(VIBRATOR_PIN, LOW);
  delay(200);
  digitalWrite(VIBRATOR_PIN, HIGH);
  delay(200);
  digitalWrite(VIBRATOR_PIN, LOW);

  delay(600);

  digitalWrite(VIBRATOR_PIN, HIGH);
  delay(100);
  digitalWrite(VIBRATOR_PIN, LOW);
  delay(100);
  digitalWrite(VIBRATOR_PIN, HIGH);
  delay(100);
  digitalWrite(VIBRATOR_PIN, LOW);
  delay(100);
  digitalWrite(VIBRATOR_PIN, HIGH);
  delay(100);
  digitalWrite(VIBRATOR_PIN, LOW);

  delay(1000);
}
