/*

Exercice 2 : échanger deux variables

Écrire une fonction echanger qui échange les valeurs de deux entiers. 
Dans le main, avec x = 5 et y = 9, on doit obtenir x = 9 et y = 5 après 
l’appel.

*/

#include <stdio.h>

void echanger (int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(void) {
	int x = 5, y = 9;

	echanger(&x, &y);

	printf("x: %d et y: %d", x, y);

	return 0;
}