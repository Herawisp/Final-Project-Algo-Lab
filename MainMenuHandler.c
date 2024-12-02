#include <stdio.h>
#include <stdlib.h>

#include "BooksHandler.c"
#include "ImageHandler.c"

void DisplayMainMenu() {
	int input;
	do {
		system("cls");
		DisplayTitle();
		printf("\n1. Admin\n");
		printf("2. User\n");
		printf("3. Exit\n");
		printf("Pilih opsi (1-3): ");
		scanf("%d", &input);
	} while (input < 1 || input > 3);
	
	switch (input) {
		case 1: PrintBooks();
		default:;
	}
}


void DisplayAdminMenu() {
	
}
