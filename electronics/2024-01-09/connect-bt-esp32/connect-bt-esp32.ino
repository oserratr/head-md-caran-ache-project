#include "BluetoothSerial.h"
#include <SPI.h>
#include <MFRC522.h>

#define VIBRATOR_PIN 15

BluetoothSerial SerialBT;

#define RST_PIN 12
#define SS_PIN 23

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test");  // Bluetooth device name
  Serial.println("The device started, now you can pair it with Bluetooth!");

  pinMode(VIBRATOR_PIN, OUTPUT);

  while (!Serial); // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin(); // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522
  delay(4);// Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();// Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

  // Afficher l'ID du tag RFID
  Serial.print("Tag RFID ID: ");
  printDec(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }

  if (SerialBT.available()) {
    String bluetoothData = SerialBT.readStringUntil('\n');
    int index = bluetoothData.indexOf(':') + 1;
    String intensiteStr = bluetoothData.substring(index);
    int intensitevibration = intensiteStr.toInt();

    Serial.print("Bluetooth Data: ");
    Serial.println(bluetoothData);
    Serial.print("IntensiteVibration: ");
    Serial.println(intensitevibration);

    if (intensitevibration < 85) {
      digitalWrite(VIBRATOR_PIN, HIGH);
      delay(300);
      digitalWrite(VIBRATOR_PIN, LOW);
    } else if (85 < intensitevibration && intensitevibration <= 170) {
      digitalWrite(VIBRATOR_PIN, HIGH);
      delay(200);
      digitalWrite(VIBRATOR_PIN, LOW);
      delay(200);
      digitalWrite(VIBRATOR_PIN, HIGH);
      delay(200);
      digitalWrite(VIBRATOR_PIN, LOW);
    } else {
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

  // Lecture du tag RFID
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    Serial.println("Tag RFID détecté!");

    // Vous pouvez ajouter le traitement supplémentaire ici selon votre besoin.

    mfrc522.PICC_HaltA();
  }

  delay(600);
}

void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}
