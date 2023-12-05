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
- Le joueur doit poser l'objet sur un endroit donné du plateau de jeu dans une orientation indiquée. Detournement d'une souris sans fil en guise de curseur pour situé l'objet sur le plateau de jeu et suivre ses déplacement. Exploration du plateau de jeu grâce a l'intensité des vibrations. Quand endroit clé trouvé : plus de vibrations + feedback sonore. Endroit clé activé grace a puce ou capteur ?? **Est-ce que je peux definir les endroits clés directement avec le dessin ?**
- Viens la revelation de la partie du paysage avec l'animation du dessin sur l'écran. (a mon avis faisable)
- Impression envoyé par l'arduino du dessin lorsque tout les capteurs sont desactivés.


## Liste electronique / matériel

- Souris sans fils
- Capteur de rfid **ou** capteur de couleur
- Raspberry pi ? (plus performant ?)
- Arduino nano 33 ble sense pour vibrations ? ou vibrator motor ?
- Petit écran
- Capteur de luminosité
- un haut parleur
- Imprimante

## Forme de l'objet

### Sketch


### 3D