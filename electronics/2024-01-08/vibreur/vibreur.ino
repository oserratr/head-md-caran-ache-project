const int pinMoteurVibration = 15;  // Remplacez le numéro de broche selon votre configuration

void setup() {
  pinMode(pinMoteurVibration, OUTPUT);
}

void loop() {
  // Activer le moteur de vibration avec une intensité variable
  for (int i = 0; i <= 255; i++) {
    activerVibration(i);
    delay(10);  // Ajoutez une petite pause pour rendre le changement d'intensité perceptible
  }

  // Attendre avant de désactiver le moteur
  delay(2000);

  // Désactiver le moteur de vibration
  activerVibration(0);

  // Attendre avant la prochaine activation
  delay(2000);
}

void activerVibration(int intensite) {
  analogWrite(pinMoteurVibration, intensite);  // Utiliser PWM pour ajuster l'intensité
}
