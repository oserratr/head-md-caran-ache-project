# Toutes les étapes pour contruire la chose

## Forme

- Modélisation 3D (Fusion 360)
    - Curseur, pion
    - Plateau de jeu

## Matériaux

- Bois (plateau + socle pion) :
    - CNC
    - Polir

- Plastique (parite haute du pion) :
    - Impression 3D
    - Thermoformage

## Electronique

- Raspberry pi/Ordinateur
    - Code
        - Control drawing machine
        - Bluetooth connexion de l'esp32
        - Détection des deplacements de l'objet
    - Inputs
        - Bluetooth souris
        - Esp32
    - Output
        - Axidraw
- Esp 32
    - Code
        - Intensité vibration
        - Detection de l'input (objet) utilisateur
        - Connexion bluethoot a la raspberry pi
    - Input
        - Rfid tag
        - Moteur de vibration
- Dimensions
    - Pion :
        - 64,7x22,8 mm esp32
        - 5.6mm x 49.2mm x 68.8mm Battery
        - 99 mm x 60 mm x 39 mm souris sans fils
        - 24 mm x 20 mm x 9.8 mm vibrateurs
        - 40 mm x 60 mm capteur rfid
        - 25mm tag rfid
    - Vers axidraw :
        - 85 mm x 56mm raspberry pi

- Cablage
???
- Puissance requise
    - Secteur PC
    - 3.7 v
