// Exercice 3 : Afficher un menu en boucle, jusqu’à ce que 
// l’utilisateur choisisse de quitter :

#include <stdio.h>

int main(void) {
	int choix = -1;
	do {
		printf("Que voulez-vous faire ?\n");
		printf("1- Saluer\n");
		printf("0- Quitter\n");
		scanf("%d", &choix);
	} while(choix != 0);

	printf("Au revoir !\n");

	return 0;
}