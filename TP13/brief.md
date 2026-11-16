Énoncé — « Mon héros »

On veut gérer le héros d’un petit jeu de rôle. Il a des points de vie (100 au maximum, il commence à 100), des pièces d’or (50 au départ), des potions (1 au départ), de l’expérience (0 au départ) et un niveau (1 au départ).

À chaque tour, le programme affiche l’état du héros et propose : combattre, boire une potion, acheter une potion ou quitter. La partie s’arrête si le joueur quitte ou si le héros meurt.

Étape 1 — Le menu (≈ 10 min). Écrire le main avec toutes les variables et le menu en boucle. Les choix n’affichent encore rien.

Étape 2 — Afficher le héros (≈ 5 min). Écrire une fonction qui affiche toutes les caractéristiques du héros. L’appeler à chaque tour.

Étape 3 — Boire une potion (≈ 10 min). Boire une potion rend 30 points de vie, sans dépasser 100, et retire une potion. S’il n’y en a plus, on affiche « Plus de potion ! ».

Étape 4 — Combattre (≈ 10 min). On demande les dégâts subis et on les retire des points de vie, qui ne descendent jamais sous 0. Le main doit savoir si le héros est mort pour arrêter la partie. S’il survit, il gagne 10 pièces.

Étape 5 — Acheter une potion (≈ 10 min). Une potion coûte 15 pièces. Si le héros n’a pas assez d’argent, l’achat est refusé. Le main affiche « Potion achetée » ou « Pas assez d’or ».

Étape 6 — L’expérience (≈ 15 min). Après chaque combat gagné, le héros gagne 40 xp. Tous les 100 xp, il monte d’un niveau et son xp repart de ce qui dépasse (140 xp, c’est un niveau de plus et 40 xp). Un gros gain peut faire monter de plusieurs niveaux d’un coup. Le main affiche « Niveau supérieur ! » quand ça arrive.