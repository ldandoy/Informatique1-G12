#include <stdio.h>

void dire_bonjour(int count) {
	printf("Bonjour %d !\n", count);
}

int main(void) {
	int count = 5;
	dire_bonjour(1);
	dire_bonjour(2);
	dire_bonjour(3);
	printf("Initial count: %d", count);

	return 0;
}