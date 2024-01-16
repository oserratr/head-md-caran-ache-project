# Questions autours du projets (en vrac)

- Est-ce que l'objet se déplace tout seul ?
- Il faut reduire les inputs et redefinir outup
- Il faut redefinir le user journey (une fois que tout ça défini)
- Trouver des formes différentes
- Trouver des matériaux / regarder ce qui se fait (peut aussi être contraignant pour le forme)
- Colaboration ? entre machine et joueurs ? ou entre plusieurs joueurs?
- Definir dimensions du canva ?
- Est-ce que on change l'input avec quelque chose que l'utilisateur dessine ? Est-ce que la machine laisse une trace par-dessus l'input de l'utilisateur ?
- Laisse quel type de trace (texture? dessins sans contours? autre?) ? 

# Pistes de réponses

- Certainement mieux si l'objet se déplace tout seul car réduit les input, permet de ne pas faire trop d'interactions, garder des interactions simples // mauvaise idée techniquement
- Laisse une trace : 
    INPUT : 
    - Anneaux ou dessin (3 ou 4 pièces ?) : definisse ce qui vas être dessiner + trajet/parcours de l'objet
    - Poser main sur objet (ressentir vibrations)
    OUTPUT (TROP?):
    - Feedback sonore (activation objet)
    - Trace, dessin par la drawing machine
    - Vibrations ? (techniques de dessins)
- Mise a jour User Journey

![nouvelle user journey](/process/2023-12-04/user%20journey.jpg)

- Pistes de formes possibles :
    - idée forme de champignon

- Recherche de matériaux :
    - Materiel semi-transparent PP : permettrait d'entre-voir les mouvements de la machine 

    ![inspiration materiaux 1](/process/2023-12-04/Assemblage%20image%20materiaux%201.jpg)

# Retours sur la réalisabilité du projet

- Pour la partie dessiner en temps réel : utilisation de l'axidraw car trop compliqué de faire drawing machine dans l'objet
- Pour le questionnement sur le déplacement ou non de l'objet : il vaut mieux que ce soit l'utilisateur qui déplace l'objet car trop compliqué de juste faire déplacer tout seul l'objet.
- Pour la partie sur detection d'anneaux (ou peut importe - juste input) : questionnement sur si possible qu'un seul capteur rfid lise plusieurs input en même temps, questionnement sur si possible de faire d'autres output ? 
    - Première alternative : dessiner des couleurs sur le canva qui sont detecter par l'objet. Mais --> perte du jeu de chaud-froid dans la conception du dessin.
    - Faire expérimentations sur le capteur rfid de l'arduino
- Pas abordé coté generatif du projet
- **Idées importantes : coté jeu du chaud froid avec retours sensoriels, et coté generatif**
- Voir si possible de lancer un programme depuis arduino sur l'axidraw
- Capteur de lumière pour savoir si l'objet est posé sur le plateau ou non 
- Mettre des capteurs pour savoir quelles zones sont actives dans la découverte du dessin
- Detournement d'une souris pour savoir sa trajectoire

## Questions suite a débrief

- Est-ce que obligatoire de garder les anneaux ? voir avec la forme de l'objet
- Est-ce que l'axidraw continue de dessiner si l'utilisateur se déplace pendant que la machine dessine ?
    - Possibilité : Continue de dessiner, mais pas de vibrations pendant le temps du dessin
- Indications visuels sur comment positionner l'objet par apport a la feuille : orientation, endroit
- Comment est géneré le dessin ? via une api d'une ia ? ou est-ce que design predefinis ?
- Est-ce que combinaison des différents output ? ou tout séparer ?
- Définir combien d'output ou donne a l'objet ?
- Quel type de fichier envoyé a l'axidraw ? (certainement vectoriel)
- Création d'un plateau de jeu ? 
- Sortie physique du dessin ?