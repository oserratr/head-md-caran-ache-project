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
  SerialBT.begin("ESP32test2");  // Bluetooth device name
  Serial.println("The device started, now you can pair it with Bluetooth!");


  pinMode(VIBRATOR_PIN, OUTPUT);

  while (!Serial);                                 // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();                        // Init SPI bus
  mfrc522.PCD_Init();                 // Init MFRC522
  delay(4);                           // Optional delay. Some board do need more time after init to be ready, see Readme
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}


void loop() {
  lectureEnvoiRfid();

  vibrationBtEsp32();
  //delay(600);
}

void lectureEnvoiRfid() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called
  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  // Ajouter un print pour afficher l'ID du tag RFID lu
  Serial.print("RFID Tag ID: ");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();

  // Envoyer l'ID du tag RFID à la console de Processing via Bluetooth
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    SerialBT.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
    SerialBT.print(mfrc522.uid.uidByte[i], HEX);
  }
  SerialBT.println();  // Ajouter un saut de ligne pour séparer les données
  
}

void vibrationBtEsp32(){
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