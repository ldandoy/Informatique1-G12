#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void menu() {
	printf("Que voulez-vous faire ?\n");
	printf("1 - Combattre\n");
	printf("2 - Boire une potion\n");
	printf("3 - Acheter une potion\n");
	printf("0 - Quitter\n");
}

void show_hero(int life, int gold, int nb_potion,int xp, int level) {
	printf("Votre héro\n");
	printf("Point de vie: %d\n", life);
	printf("Or: %d\n", gold);
	printf("Nb de potion: %d\n", nb_potion);
	printf("XP: %d\n", xp);
	printf("Level: %d\n\n", level);
}

void drink(int *life, int *nb_potion) {
	if (*life < 100) {
		if (*nb_potion > 0) {
			if (*life>=70) {
				*life = 100;
			} else {
				*life = *life + 30;
			}
			*nb_potion = *nb_potion -1;
		} else {
			printf("Plus de potion !\n");
		}
	} else {
		printf("Pas besoin !\n");
	}
}

int buy_potion(int *nb_potion, int *gold) {
	int success = 0;

	if (*gold > 15) {
		*gold = *gold - 15;
		*nb_potion = *nb_potion + 1;
		success = 1;
	}

	return success;
}

int fight(int *life, int *xp, int *level, int *gold) {
	int toss = (rand() % (20 - 0 + 1)) + 0;
	int end = 0, degat = 0;
	printf("toss: %d\n", toss);

	if (toss > 10) {
		degat = (rand() % (30 - 15 + 1)) + 15;
		printf("L'ennemi vous inflige %d degats\n", degat);
		*life = *life - degat;
		*gold = *gold + 10;
	} else {
		printf("Il ne vous a pas touché\n");
	}

	if (*life >= 0) {
		*xp = *xp + 40;
		end = 1;
	}

	return end;
}

int main(void) {
	system("clear");
	SetConsoleOutputCP(CP_UTF8);
	int choix = -1;
	int life = 100, gold=50, nb_potion=1, xp=0, level=1;
	int end;
	srand((unsigned int)time(NULL));

	do {
		show_hero(life, gold, nb_potion, xp, level);

		menu();
		scanf("%d", &choix);

		switch(choix) {
			case 0:
				printf("Quitter\n");
				break;
			case 1:
				printf("Combattre\n");
				end = fight(&life, &xp, &level, &gold);

				if (end == 0) {
					printf("Votre héro est mort !\n");
					choix = 0;
				} else {
					if (xp > 100) {
						xp = xp - 100;
						level = level + 1;
						printf("Niveau supérieur !\n");
					}
				}
				break;
			case 2:
				printf("Boire une potion\n");
				drink(&life, &nb_potion);
				break;
			case 3:
				printf("Acheter une potion\n");
				if(buy_potion(&nb_potion, &gold) == 1) {
					printf("Potion achetée\n");
				} else {
					printf("Pas assez d’or\n");
				}
				break;
			default:
				printf("Mauvaise option !\n");
				break; 
		}

		getchar();
		getchar();
		system("clear");
	} while(choix != 0);

	return 0;
}