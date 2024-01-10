void setup() {
  fullScreen(2);
  background(0);
  noStroke();

  int centerX1 = width / 4;
  int centerY1 = height / 4;

  int centerX2 = 3 * width / 4;
  int centerY2 = height / 4;

  int centerX3 = 3 * width / 4;
  int centerY3 = 3 * height / 4;

  int centerX4 = width / 4;
  int centerY4 = 3 * height / 4;

  int circleRadius = min(width, height) / 4; // Utilise la moitié de la plus petite dimension

  // Boucle pour remplir le premier cercle avec un dégradé radial du rouge au vert
  for (int r = circleRadius; r > 0; r--) {
    float gradientFactor = map(r, 0, circleRadius, 0, 1);
    color gradientColor = lerpColor(color(255), color(0), gradientFactor);
    fill(gradientColor);
    ellipse(centerX1, centerY1, 2 * r, 2 * r);
  }

  // Boucle pour remplir le deuxième cercle
  for (int r = circleRadius; r > 0; r--) {
    float gradientFactor = map(r, 0, circleRadius, 0, 1);
    color gradientColor = lerpColor(color(255), color(0), gradientFactor);
    fill(gradientColor);
    ellipse(centerX2, centerY2, 2 * r, 2 * r);
  }

  // Boucle pour remplir le troisième cercle
  for (int r = circleRadius; r > 0; r--) {
    float gradientFactor = map(r, 0, circleRadius, 0, 1);
    color gradientColor = lerpColor(color(255), color(0), gradientFactor);
    fill(gradientColor);
    ellipse(centerX3, centerY3, 2 * r, 2 * r);
  }

  // Boucle pour remplir le quatrième cercle
  for (int r = circleRadius; r > 0; r--) {
    float gradientFactor = map(r, 0, circleRadius, 0, 1);
    color gradientColor = lerpColor(color(255), color(0), gradientFactor);
    fill(gradientColor);
    ellipse(centerX4, centerY4, 2 * r, 2 * r);
  }
}
