/*

Exercice 3 : une fonction qui « renvoie » deux résultats

Écrire une fonction divisionEuclidienne qui reçoit deux entiers a et b et 
fournit à la fois le quotient et le reste. 
Un return ne peut renvoyer qu’une seule valeur, il faut donc trouver une 
autre solution.

*/
#include <stdio.h>

void divisionEuclidienne(int a, int b, int *quotient, int *reste) {
	*quotient = a/b;
	*reste = a%b;
}

int main(void) {
	int a=7, b=3, quotient, reste;

	divisionEuclidienne(a, b, &quotient, &reste);

	printf("%d/%d = %d avec un reste de %d\n", a, b, quotient, reste);

	return 0;
}
