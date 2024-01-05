#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

const char *ssid = "Helvetia";     // Nom du réseau Wi-Fi
const char *password = "Geneva-Lausanne-Bern-Zurich"; // Mot de passe du réseau Wi-Fi

WiFiServer server(80); // Port 80 pour le serveur


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

  // Démarrer le serveur
  server.begin();
  Serial.println("Serveur démarré");
}

void loop() {
  // Attendre qu'un client se connecte
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Attendre que le client envoie des données
  while (client.connected() && !client.available()) {
    delay(1);
  }

  // Lire les données du client
  String request = "";
  while (client.available()) {
    char c = client.read();
    request += c;
  }
  Serial.print("Données reçues du client : ");
  Serial.println(request);

  // Envoyer des données au client (réponse)
  String response = "Hello from ESP32!";
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/plain");
  client.println("Connection: close");
  client.println();
  client.println(response);
  Serial.print("Réponse envoyée au client : ");
  Serial.println(response);

  // Attendre un court instant avant de fermer la connexion
  delay(10);
  client.stop();
  Serial.println("Client déconnecté");
}
