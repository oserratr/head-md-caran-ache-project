int totalPoints = 100; // Nombre de points à utiliser
int[] order;
PVector[] points;

void setup() {
  size(600, 600);
  PImage img = loadImage("test.jpg"); // Remplacez "votre_image.jpg" par le chemin de votre propre image
  img.resize(width, height);
  
  // Initialisation des points aléatoires
  points = new PVector[totalPoints];
  for (int i = 0; i < totalPoints; i++) {
    points[i] = new PVector(random(width), random(height));
  }
  
  // Initialisation de l'ordre des points avec l'algorithme du plus proche voisin
  order = new int[totalPoints];
  boolean[] taken = new boolean[totalPoints];
  order[0] = 0;
  taken[0] = true;
  for (int i = 1; i < totalPoints; i++) {
    int nextIndex = findNearest(points[order[i-1]], taken);
    order[i] = nextIndex;
    taken[nextIndex] = true;
  }
}

void draw() {
  background(255);
  stroke(0);
  strokeWeight(2);
  noFill();
  
  // Dessine le chemin
  beginShape();
  for (int i = 0; i < totalPoints; i++) {
    int index = order[i];
    vertex(points[index].x, points[index].y);
  }
  endShape();
  
  // Dessine les points
  fill(0);
  for (PVector point : points) {
    ellipse(point.x, point.y, 8, 8);
  }
  
  noLoop(); // Arrête le dessin après une itération
}

int findNearest(PVector v, boolean[] taken) {
  int nearestIndex = -1;
  float record = Float.MAX_VALUE;
  for (int i = 0; i < totalPoints; i++) {
    if (!taken[i]) {
      float d = dist(v.x, v.y, points[i].x, points[i].y);
      if (d < record) {
        record = d;
        nearestIndex = i;
      }
    }
  }
  return nearestIndex;
}
