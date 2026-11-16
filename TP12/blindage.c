#include <stdio.h>

void blindage(int *a, int *b) {
	do {
		printf("Entrez a:");
		scanf("%d", a);

		printf("\n");

		printf("Entrez b:");
		scanf("%d", &*b);
	} while(0>*a || *a>*b);
}


int main(void) {
	int a, b;

	blindage(&a, &b);

	printf("a: %d et b: %d", a, b);

	return 0;
}