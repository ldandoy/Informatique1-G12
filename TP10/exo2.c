// Exercice 2 : Demander un entier n à l’utilisateur, 
// puis afficher tous les nombres pairs de 0 à n.

#include <stdio.h>

int main(void) {
	int n;
	printf("Entrez un nombre: ");
	scanf("%d", &n);

	for (int i=0; i<=n; i++) {
		if (i%2==0) {
			printf("%d\n", i);
		}
	}

	return 0;
}