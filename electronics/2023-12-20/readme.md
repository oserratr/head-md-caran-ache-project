# Liens important documentation

- https://www.aranacorp.com/en/using-an-rfid-module-with-an-esp32/
- https://learn.sparkfun.com/tutorials/esp32-thing-plus-hookup-guide/hardware-overview


## Cablage

RFID to ESP 32 :
- MISO (Master In Slave Out): GPIO19
- MOSI (Master Out Slave In): GPIO18
- SCK : GPO5
- CS/SS : GPO23

- GRND : GRND
- 3.3v : 3V3

ESP32 to battery :
- Fil rouge : VBat
- Fil noir : GRND

Vibrator to ESP32 :
- SIG on whatever

- GRND : GRND
- VCC : VBat

## Etapes

- Configurer ESP32 pour bluethoot cf schema physique
- Connecter souris a pc ou rasp pi
- Configurer capteur rfid avec les différents tag + random fichiers vectoriels
- Test envoi axidraw avec rasp pi
- Test envoi axidraw avec rasp pi avec information du tag
- Code sur zone activation en fonction de position de souris
- configrer rythme des vibrations 


