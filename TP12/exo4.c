/*

Exercice 4 : trier trois nombres

Écrire une fonction trier3 qui reçoit trois entiers et les remet dans 
l’ordre croissant, en réutilisant echanger. 
Avec a = 7, b = 2, c = 5, on doit obtenir a = 2, b = 5, c = 7.

*/

#include <stdio.h>

void echanger (int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void trier3 (int *a, int *b, int *c) {
	if (*a > *b) {
		echanger(a, b);
	}
	if (*b >*c) {
		echanger(b, c);
	}
	if (*a > *b) {
		echanger(a, b);
	}
}

int main(void) {
	int x = 7, y = 2, z=5;

	trier3(&x, &y, &z);

	printf("x: %d, y: %d et z: %d", x, y, z);

	return 0;
}