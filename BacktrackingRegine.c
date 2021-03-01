#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *v, k, n, results = 0;

void print() {
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j <= n + 1; j++) {
			if (i == 1 && j == 1)
				printf("  ");
			else
				if (i == 1)
					printf("%d ", j - 1);
				else
					if (j == 1)
						printf("%d ", i - 1);
				else
					if (i != 1 && j != 1) {
						if (j - 1 == v[i - 1])
							printf("R ");
						else
							printf("x ");
					}
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", v[i]);
	printf(" :  %d\n\n", results);
}
int solution(int k) {
	return k == n;
}
int valid(int k) {
	//nu sunt sigur daca este buna functia, dar din cate am vazut rezultatele erau corecte
	if (k > 1) {
		//verificare se repeta pe coloana
		if (abs(v[k] - v[k - 1]) <= 1)
			return 0;
	}
	for (int i = 1; i < k; i++)//verificare daca se repeta pe linie
		if (v[i] == v[k])
			return 0;


	int contor = 1;//verificare pe diagonala in stanga
	for (int i = k - 1; i > 0; i--) {
		if (v[i] == (v[k] - contor))
			return 0;
		contor++;
	}
	contor = k - 1;//verificare pe diagonala in dreapta
	for (int i = 1; i < k; i++) {
		if (v[i] == (v[k] + contor))
			return 0;
		contor--;
	}
	return 1;
}
void back(int k) {
	for (int i = 1; i <= n; i++) {
		v[k] = i;
		if (valid(k))
			if (solution(k)) {
				results++;
				print();
			}
			else back(k + 1);
	}
}
void main() {
	printf("n = ");
	scanf(" %d", &n);
	v = (int*)malloc(n * sizeof(int));
	back(1);
}