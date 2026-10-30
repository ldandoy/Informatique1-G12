#include <stdio.h>

int main(void) {
	int year = 0;
	int test;

	printf("Entrez une annee: ");
	scanf("%d", &year);

	test = ((year % 4 == 0) && ! (year%100 == 0)) || (year % 400 == 0);

	if (test) {
		printf("L'annee %d est bissextile", year);
	} else {
		printf("L'annee %d n'est pas bissextile", year);
	}

	return 0;
}