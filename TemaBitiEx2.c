#include <stdio.h>
#include <stdlib.h>

unsigned char setFlag(unsigned char f, int k) {
	return (f | (1 << k));
}

unsigned char unsetFlag(unsigned char f, int k) {
	return f & ~(1 << k);
}

unsigned char getFlag(unsigned char f, int k) {
	return 1 & (f >> k);
}

unsigned char set(unsigned char f) {
	int k = 0;
	short int aux = 0;
	while (k < 5) {
		if (k == 0)
			printf("READ (0 / 1): ");
		else if (k == 1)
			printf("WRITE (0 / 1): ");
		else if (k == 2)
			printf("DELETE (0 / 1): ");
		else if (k == 3)
			printf("RENAME (0 / 1): ");
		else if (k == 4)
			printf("COPY (0 / 1): ");
		scanf("%hd", &aux);
		while (aux != 1 && aux != 0) {
			scanf("%hd", &aux);
		}
		if (aux)
			f = setFlag(f, k);
		else
			f = unsetFlag(f, k);
		k++;
	}
}

void main() {
	unsigned char* perm;
	int n, aux = 0;
	printf("Citeste numarul de utilizatori: ");
	scanf("%d", &n);
	perm = malloc(n * sizeof(unsigned char));
	for (int i = 0; i < n; i++) {
		printf("\nUser %d : \n", i);
		perm[i] = set(perm[i]);
	}
	for (int i = 0; i < n; i++) {
		int j = 0;
		printf("User %d : ", i);
		printf("READ - ");
		if (getFlag(perm[i], j))
			printf("DA ; ");
		else
			printf("NU ; ");
		j++;
		printf("WRITE - ");
		if (getFlag(perm[i], j))
			printf("DA ; ");
		else
			printf("NU ; ");
		j++;
		printf("DELETE - ");
		if (getFlag(perm[i], j))
			printf("DA ; ");
		else
			printf("NU ; ");
		j++;
		printf("RENAME - ");
		if (getFlag(perm[i], j))
			printf("DA ; ");
		else
			printf("NU ; ");
		j++;
		printf("COPY - ");
		if (getFlag(perm[i], j))
			printf("DA ; ");
		else
			printf("NU ; ");
		printf("\n");
	}
}