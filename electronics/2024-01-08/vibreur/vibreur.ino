const int pinMoteurVibration = 15;  // Remplacez le numéro de broche selon votre configuration
const int intensiteMin = 0;
const int intensiteMax = 255;

void setup() {
  pinMode(pinMoteurVibration, OUTPUT);
}

void loop() {
  // Lire l'intensité de vibration (peut être ajustée en fonction de la situation réelle)
  int intensiteVibration = map(analogRead(pinMoteurVibration), 0, 1023, intensiteMin, intensiteMax);

  // Activer les vibrations avec l'intensité lue
  activerVibration(intensiteVibration);

  // Attendre avant la prochaine itération
  delay(100);
}

void activerVibration(int intensite) {
  analogWrite(pinMoteurVibration, intensite);
}
