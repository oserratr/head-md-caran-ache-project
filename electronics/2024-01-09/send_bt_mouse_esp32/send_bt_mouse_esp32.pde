import processing.serial.*;

Serial serial;
String rfidID = "";

void setup() {
  println(Serial.list());
  String portName = "COM9";
  serial = new Serial(this, portName, 115200);
  size(2245, 3178);

  // dégradé de nuance de gris
  //backgroundGradient();
  //background(169);
  //background(0);
  //background(249);
  //background(255);
  
  
  background(255);  // Fond blanc

  // Couleurs des rectangles
  color[] colors = {color(255), color(249), color(0), color(169)};

  // Largeur et hauteur des rectangles
  int rectWidth = width / colors.length;
  int rectHeight = height;

  // Dessiner les rectangles côte à côte
  for (int i = 0; i < colors.length; i++) {
    fill(colors[i]);
    rect(i * rectWidth, 0, rectWidth, rectHeight);
  }

  
}

void draw() {
// Lire les données du port série Bluetooth
  while (serial.available() > 0) {
    String data = serial.readStringUntil('\n');
    if (data != null) {
      // Afficher les données du tag RFID dans la console Processing
      println("ID du Tag RFID : " + data);
      
      // Stocker l'ID du tag RFID dans la variable globale
      rfidID = data.trim();
    }
  }
  
  println(rfidID);
  
  // Obtenez la couleur de la position de la souris
  int currentColor = get(mouseX, mouseY);

  // Obtenez les composants R, G, B de la couleur
  float r = red(currentColor);
  float g = green(currentColor);
  float b = blue(currentColor);

  // Calculer l'intensité de vibration basée sur la composante R
  int intensitevibration = int(r);

  // Envoyer la couleur et la position de la souris via la liaison série
  serial.write("Couleur : " + r + ", " + g + ", " + b + "\tPosition : " + mouseX + ", " + mouseY + "\n");

  // Envoyer l'intensité de vibration via la liaison série
  serial.write("IntensiteVibration : " + intensitevibration + "\n");

  // Attendez 1000 millisecondes (1 seconde)
  delay(600);
}

void backgroundGradient() {
  // Définir les couleurs du dégradé
  int startColor = color(255);  // Blanc
  int endColor = color(0);     // Noir

  // Dessiner le dégradé
  for (int y = 0; y < height; y++) {
    // Calculer l'interpolation linéaire de la couleur en fonction de la position y
    float inter = map(y, 0, height, 0, 1);
    int c = lerpColor(startColor, endColor, inter);

    // Dessiner la ligne horizontale avec la couleur calculée
    stroke(c);
    line(0, y, width, y);
  }
}
