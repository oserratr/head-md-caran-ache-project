# Objectifs d'aujourd'hui par ordre de priorité

- Simplifier le projet au maximum en gardant les éléments principaux du propos
- Liste electronique device
- Travailler la forme de l'objet (pour ce soir)
- Continuer veille créative sur matériaux

## Simplifier le projet

### En l'état

- Utilisation de l'axidraw pour la partie drawing machine ? Peut être trop conséquent pour le prototype du projet
- Utilisation de filtres de couleurs pour reveler le dessin ? Peut-être mieux ? avec des lumières différentes et des encres de différentes couleures ? + utilisation d'une imprimante ? (pour éviter de faire mecanisme de dessin)
- Garder le concept de vibration pour revéler un dessin. Propos en lien avec les recherches : approche différente du dessin, decouverte sensorielle
- Garder le concept de : je choisi des inputs (à définir) au feeling (permet d'eviter la frustration, et le perfectionnisme dans la réalisation du dessin cf itnerview + experimentations) en donnant X paramètres prédéfinis qui genère un dessin (paysage : pourquoi? / Côté freestyle du dessin cf interview, pas de blocage sur  reproduction d'un environnement de façon empirique pour aller dans les détails : ce qui est souvent une pratique quand on comtemple des paysage pour les reproduire cf recherches sur internet)

### Solutions (a voir si faisable et plus simple)

- Idée 1 : 
    - Choix des input : 
        - Cartes élements de paysages : choix d'un seul input que la personne connait.
    - Vibrations : Trouver tout les points clés du dessin sur un plateau de jeu a reveler grâce a l'intensité de la vibration. Quand point trouvé : Feedback sonore et plus de vibration si utilisateur continue de bouger.
    - Reveler le paysage : Revele le point clé du paysage via un écran avec animations des tracé comme si la personne desinnait.
    - A la fin : récupération du dessin préalablement imprimé ou impression a la tout fin quand la personne a fini de trouver tout les points clés.

### Est-ce que les solutions sont plus simples et faisable ?

- Pour le choix des input : (a mon avis faisable) avec capteur rfid ou ncf ou capteur de couleur. Interpretation de l'id du tag par le programme. Fake IA avec choix random dans bibliothèque de plusieurs dessins deja fait + animation du drawing.
- Le joueur doit poser l'objet sur un endroit donné du plateau de jeu dans une orientation indiquée. Detournement d'une souris sans fil en guise de curseur pour situé l'objet sur le plateau de jeu et suivre ses déplacement. Exploration du plateau de jeu grâce a l'intensité des vibrations. Quand endroit clé trouvé : plus de vibrations + feedback sonore?. Endroit clé activé grace a puce ou capteur ?? **Est-ce que je peux definir les endroits clés directement avec le dessin ?**
- Viens la revelation de la partie du paysage avec l'animation du dessin sur l'écran. (a mon avis faisable)
- Impression envoyé par l'arduino du dessin lorsque tout les capteurs sont desactivés.


## Liste electronique / matériel

- Souris sans fils : https://www.amazon.fr/NOUVEAU-BLUESTORK-Souris-boutons-m%C3%A9tal/dp/B07MQK52ZD/ref=sr_1_9?crid=QT7YMVB5BMV8&keywords=souris+sans+fil&qid=1701787534&sprefix=souris+%2Caps%2C88&sr=8-9 
- Capteur de rfid **ou** capteur de couleur : capteur RFID deja dans arduino
- Raspberry pi ? (plus performant ?) ou Arduino nano 33 ble sense ? bluethoot ou wifi en fonction de imprimante : https://www.adafruit.com/product/3055 **ou** https://www.pi-shop.ch/arduino-nano-rp2040-connect 
- Vibration motor : https://www.adafruit.com/product/1201
- Controller vibration motor : https://www.adafruit.com/prosduct/2305
- Grand écran : Umprunter au lab media design
- Capteur de luminosité : a voir si compatible avec raspberry mais déja dans le kit arduino
- Un haut parleur : pour feeback sonore peut être suffisant celui arduino mais bruit clair mieux? 
- Imprimante portable wifi : https://ideen-platz.ch/products/thermodrucker?variant=47209533538591&currency=CHF&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&gclid=Cj0KCQiAsburBhCIARIsAExmsu6Te9gJFSxDUFjsrHqdM9sC8CGWwPP8NKFLgbDwHYmxwBt1tiveOvYaAgn5EALw_wcB


### Retour liste electronique (MAJ)

- Retour de l'axidraw 
- Souris bluethoot caché dans un objet mobile --
- Programme processing sur ordi (raspberry pi)--
- Detection des zones sensibles avec vibrations--
- Zones activé -> entraine une partie de dessin sur axidraw + desactive la zone + desactive les vibrations le temps du dessin
- Esp 32 et baterie pour alimenté vibreur dans objet--
- https://www.sparkfun.com/products/15663 --

**Shémas éléctrique et physique (pas remis au propre)**

![electrique shema](/electronics/2023-12-05/shema-physique-electrique-prototype.jpg)
