#include <WiFi.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

const char *ssid = "Helvetia";     // Nom du réseau Wi-Fi
const char *password = "Geneva-Lausanne-Bern-Zurich"; // Mot de passe du réseau Wi-Fi

WebSocketsServer webSocket = WebSocketsServer(81); // Utilisez le port 81 pour les WebSockets

const int motorPin = 15;  // Broche à laquelle le moteur vibreur est connecté

void parseMouseData(String data) {
  DynamicJsonDocument jsonDocument(256);
  deserializeJson(jsonDocument, data);

  int mouseX = jsonDocument["x"];
  int mouseY = jsonDocument["y"];

  Serial.print("Position de la souris - X: ");
  Serial.print(mouseX);
  Serial.print(", Y: ");
  Serial.println(mouseY);

  // Traitement de la couleur RGB
  if (jsonDocument.containsKey("color")) {
    int redValue = jsonDocument["color"]["r"];
    int greenValue = jsonDocument["color"]["g"];
    int blueValue = jsonDocument["color"]["b"];

    // Calculer la valeur moyenne des composants RGB
    int averageColor = (redValue + greenValue + blueValue) / 3;

    // Ajuster l'intensité de vibration en fonction de la valeur moyenne de couleur
    int vibrationIntensity = map(averageColor, 0, 255, 0, 255);

    // Activer le moteur vibreur avec l'intensité calculée
    analogWrite(motorPin, vibrationIntensity);

    // Affichage sur le moniteur série (facultatif)
    Serial.print("Couleur RGB - R: ");
    Serial.print(redValue);
    Serial.print(", G: ");
    Serial.print(greenValue);
    Serial.print(", B: ");
    Serial.println(blueValue);
  }
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
  switch (type) {
    case WStype_TEXT:
      String data = (char *)payload;
      parseMouseData(data);
      break;
  }
}

void setup() {
  Serial.begin(115200);
  delay(10);

  // Connecter l'ESP32 au réseau Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion au WiFi en cours...");
  }
  Serial.println("Connecté au réseau WiFi");

  // Démarrer le serveur WebSockets
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
  Serial.println("Serveur WebSockets démarré");

  // Configurer la broche du moteur vibreur en sortie
  pinMode(motorPin, OUTPUT);
}

void loop() {
  webSocket.loop();
  // Autres opérations si nécessaires
}
