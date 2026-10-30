**Énoncé général** : on veut écrire un programme qui gère un compte bancaire. L’utilisateur peut consulter son solde, déposer et retirer de l’argent. Le solde part à 0 €.

**Étape 1** : Écrire une fonction afficherMenu() qui affiche le menu.

**Étape 2** : Écrire une fonction afficherSolde(float solde) qui affiche le solde avec 2 chiffres après la virgule.

**Étape 3** : Écrire une fonction deposer(float solde, float montant) qui renvoie le nouveau solde. Si le montant est négatif ou nul, elle affiche « Montant invalide » et renvoie le solde inchangé.

**Étape 4** : Écrire une fonction retirer(float solde, float montant). Elle refuse un montant négatif ou nul (« Montant invalide ») et un montant supérieur au solde (« Solde insuffisant »). Sinon, elle renvoie le nouveau solde.

**Étape 5** : Écrire le main : afficher le menu en boucle, lire le choix, appeler la bonne fonction, et s’arrêter quand l’utilisateur tape 0.
