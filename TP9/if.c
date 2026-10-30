#include <stdio.h>

int main (void) {
	float moyenne;
	printf("Quelle est votre moyenne: ");
	scanf("%f", moyenne);

	if (!(moyenne < 0) || !(moyenne > 20)) {
		printf("Mauvaise moyenne");
	} else if (moyenne < 10) {
		printf("Pas de mention");
	} else if (moyenne < 12) {
		printf("Assez bien");
	} else if (moyenne < 14) {
		printf("Bien");
	} else if (moyenne < 16) {
		printf("Très bien");
	} else {
		printf("Excellent !");
	}

	return 0;
}