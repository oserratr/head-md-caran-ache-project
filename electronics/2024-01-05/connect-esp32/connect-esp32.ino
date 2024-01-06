#include <WiFi.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

const char *ssid = "Helvetia";     // Nom du réseau Wi-Fi
const char *password = "Geneva-Lausanne-Bern-Zurich"; // Mot de passe du réseau Wi-Fi

WiFiUDP udp;
unsigned int localPort = 80;  // Port sur lequel écouter les données

void setup() {
  Serial.begin(115200);

  // Connecter l'ESP32 au réseau Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion au WiFi en cours...");
  }
  Serial.println("Connecté au réseau WiFi");

  // Attacher le port local à l'UDP
  udp.begin(localPort);
  Serial.println("En attente de données...");
}

void loop() {
  char packetBuffer[255];
  int packetSize = udp.parsePacket();

  if (packetSize) {
    udp.read(packetBuffer, packetSize);
    packetBuffer[packetSize] = '\0';

    // Exemple : afficher les données reçues sur la console série
    Serial.print("Données reçues : ");
    Serial.println(packetBuffer);

    // Ajoutez votre logique ici pour traiter les données selon vos besoins
  }
}
