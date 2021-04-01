#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encryptDecrypt(char* mess) {
	char* pass = (char*)malloc(sizeof(char)), c = 0;
	int i = 0;
	// citirea parolei de criptare/decriptare
	printf(" Introdu parola : ");
	while (c != '\n') {
		c = getc(stdin);
		pass = (char*)realloc(pass, i + 1);
		pass[i] = c;
		i++;
	}
	pass[i] = NULL;
	// criptarea/decriptarea mesajului
	int len = strlen(mess) - 1, l = strlen(pass) - 1;
	for (int i = 0; i < len; i++) {
		//mess[i] = ((int)mess[i] ^ (int)pass[i % l]); // nu functioneaza pe toate cazurile
		mess[i] = ~mess[i] ^ pass[i % l];
	}
	return mess;
}

void printInHexa(char* mess) {
	// afisarea caracterelor mesajului in hexa
	printf("\n ");
	for (int i = 0; i < strlen(mess); i++) {
		printf("%x ", mess[i]);
	}
	printf("\n");
}

void main() {
	//citirea mesajului
	printf(" Citeste mesajul pe care vrei sa il criptezi : ");
	char* mess = (char*)malloc(sizeof(char)), c = 0;
	int i = 0;
	while (c != '\n') {
		c = getc(stdin);
		mess = (char*)realloc(mess, i + 1);
		mess[i] = c;
		i++;
	}
	mess[i] = NULL;

	// criptarea/decriptarea mesajului
	printf("\n Mesajul in hexa inainte de criptare: ");
	printInHexa(mess);
	strncpy(mess, encryptDecrypt(mess), strlen(mess)); // criptarea mesajului
	printf("\n Mesajul in hexa criptat: ");
	printInHexa(mess);

	strncpy(mess, encryptDecrypt(mess), strlen(mess)); // decriptarea mesajului
	printf("\n Mesajul in hexa decriptat: ");
	printInHexa(mess);
	printf("\n Mesajul text dupa decriptare: %s", mess);
}