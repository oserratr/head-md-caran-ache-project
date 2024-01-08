#include <WiFi.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>

const char *ssid = "Helvetia";     // Nom du réseau Wi-Fi
const char *password = "Geneva-Lausanne-Bern-Zurich"; // Mot de passe du réseau Wi-Fi

WebSocketsServer webSocket = WebSocketsServer(81); // Utilisez le port 81 pour les WebSockets

void parseMouseData(String data) {
  // Exemple : supposons que les données sont au format JSON
  // et ressemblent à {"x": 123, "y": 456}
  DynamicJsonDocument jsonDocument(256);
  deserializeJson(jsonDocument, data);

  int mouseX = jsonDocument["x"];
  int mouseY = jsonDocument["y"];

  // Traitez les coordonnées de la souris (par exemple, affichez-les)
  Serial.print("Position de la souris - X: ");
  Serial.print(mouseX);
  Serial.print(", Y: ");
  Serial.println(mouseY);
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
  switch (type) {
    case WStype_TEXT:
      // Les données sont reçues au format texte
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
}

void loop() {
  webSocket.loop();
  // Autres opérations si nécessaires
}
