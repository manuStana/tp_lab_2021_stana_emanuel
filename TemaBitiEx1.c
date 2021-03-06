#include <stdio.h>
#include <stdlib.h>

void main() {	
	short int* v = NULL;
	int n = 0;
	printf("n = ");
	scanf(" %d", &n);
	v = malloc(n * sizeof(short int));
	if (v != NULL)
		for (int i = 0; i < n; i++) {
			printf("v[%d] = ", i);
			scanf(" %hd", &v[i]);
		}

	for (int i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
}