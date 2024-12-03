#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BooksHandler.c"
#include "ImageHandler.c"
#include "UserInfoHandler.c"
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
		case 2: DisplayUserAccount();
		default:;
	}
}

/*----------------------------------------------------------------------------------------------------------*/

void DisplayBookList() {
	system("cls");
	PrintBooks();
	printf("\n1). Previous page\n");
	printf("2). Next page\n");
	printf("3). Sort by title (Ascending)\n");
	printf("4). Sort by title (Descending)\n");
	printf("5). Sort by genre\n");
	printf("6). Search book\n");
}

void HandleBookInput(int input) {
	switch (input) {
		case 1: PreviousPage(); break;
		case 2: NextPage(); break;
		case 3: SortByTitle(1); break;
		case 4: SortByTitle(0); break;
		case 5: SortByGenre(); break;
	}
}

/*----------------------------------------------------------------------------------------------------------*/

void DisplayUserMenu() {
	int input;
	do {
		DisplayBookList();
		printf("\n7). Beli Buku\n");
		printf("8). Pinjam Buku\n");
		printf("9). Kembalikan Buku\n");
		scanf("%d", &input);	
	} while (input < 1 || input > 9);
	
	if (input >= 1 && input <= 5) {
		HandleBookInput(input);
	} else {
		switch (input) {
			case 7: DisplayBuyBookMenu(); break;
			case 8: DisplayBorrowBookMenu(); break;
			case 9: DisplayReturnBookMenu(); break;
		}
	}
}

void DisplayBuyBookMenu() {
	int input;
	do {
		DisplayBookList();
		printf("7). Keranjang\n");
	} while (input < 1 || input > 7);
	
	if (input >= 1 && input <= 5) {
		HandleBookInput(input);
	} else {
		switch (input) {
			case 7: DisplayBuyBookMenu(); break;
		}
	}
}

void DisplayBorrowBookMenu() {
	
}

void DisplayReturnBookMenu() {
	
}

/*----------------------------------------------------------------------------------------------------------*/

void DisplayAdminMenu() {
	int input;
	do {
		system("cls");
		PrintBooks();
		printf("\n1). Tambahkan Buku\n");
		printf("2). Hapus Buku\n");
		printf("Pilih opsi (1-2): ");
		scanf("%d", &input);
	} while (input < 1 || input > 2);
	
	switch (input) {
		case 1: DisplayAdminMenu();
		default:;
	}
}


void DisplayAddBook() {
	
}

void SignupUser(){
	
}

void SinginUser(){
	
}


void main() {
	ReadBookFile();
	DisplayMainMenu();
}
