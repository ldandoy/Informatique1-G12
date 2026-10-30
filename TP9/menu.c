#include <stdio.h>

int menu()
{
	int choix = 0;
	printf("Que voulez vous faire ?");
	printf("1 - Manger");
	printf("2 - Rêver");
	printf("0 - Quitter");
	scanf("%d", &choix);

	return choix;
}

int main(void)
{
	int choix = menu();

	if (choix == 1) {
		printf("Vous commander une salade !");
	} elseif(choix == 2) {
		printf("Vous vous en dormez et vous retrouvez au pays des merveilles !");
	} else {
		printf("Au revoir !");
	}

	return 0;
}