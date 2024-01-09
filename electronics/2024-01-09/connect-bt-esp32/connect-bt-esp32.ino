#include "BluetoothSerial.h"

#define VIBRATOR_PIN 15

BluetoothSerial SerialBT;


void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test");  // Bluetooth device name
  Serial.println("The device started, now you can pair it with Bluetooth!");

  pinMode(VIBRATOR_PIN, OUTPUT);
}

void loop() {
  /*digitalWrite(VIBRATOR_PIN, HIGH);
  delay(100);
  digitalWrite(VIBRATOR_PIN, LOW);
  delay(100);*/
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }

  if (SerialBT.available()) {
    // Lire la chaîne reçue via Bluetooth
    String bluetoothData = SerialBT.readStringUntil('\n');

    // Extraire l'intensité de vibration de la chaîne
    int index = bluetoothData.indexOf(':') + 1;
    String intensiteStr = bluetoothData.substring(index);
    int intensitevibration = intensiteStr.toInt();

    // Afficher les informations dans la console
    Serial.print("Bluetooth Data: ");
    Serial.println(bluetoothData);
    Serial.print("IntensiteVibration: ");
    Serial.println(intensitevibration);

    // Activer le moteur vibreur en fonction de l'intensité de vibration
    if (intensitevibration < 85) {
      // 1 vibration de 0.5 seconde
      digitalWrite(VIBRATOR_PIN, HIGH);
      delay(300);
      digitalWrite(VIBRATOR_PIN, LOW);

    } else if (85 < intensitevibration && intensitevibration <= 170) {
      // 2 vibrations avec un délai de 0.25 seconde entre les deux
      digitalWrite(VIBRATOR_PIN, HIGH);
      delay(200);
      digitalWrite(VIBRATOR_PIN, LOW);
      delay(200);
      digitalWrite(VIBRATOR_PIN, HIGH);
      delay(200);
      digitalWrite(VIBRATOR_PIN, LOW);
    } else {
      // 3 vibrations avec un délai de 0.25 seconde entre les trois
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
    }
  }

  delay(600);
}