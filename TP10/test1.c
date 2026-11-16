#include <stdio.h>

int main(void) {
	int a = 20;
	int *p = &a;
	(*p)++;
	printf("a=%d", a);

	return 0;
}
