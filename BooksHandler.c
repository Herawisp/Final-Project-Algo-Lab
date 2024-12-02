#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
	char Title[101];
	char Author[101];
	char Genre[101];
	int Year;
	int ID;
	int Stock;	
};

struct Book data[100];
int book_amount = 0;

void ReadBookFile() {
	FILE *file = fopen("BookList.txt", "r");
	if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; 

        char *title = strtok(line, "|");
        char *author = strtok(NULL, "|");
        char *yearStr = strtok(NULL, "|");
        char *idStr = strtok(NULL, "|");
        char *stockStr = strtok(NULL, "|");

        if (title && author && yearStr && idStr && stockStr) {
            strcpy(data[book_amount].Title, title);
            strcpy(data[book_amount].Author, author);
            data[book_amount].Year = atoi(yearStr);  
            data[book_amount].ID = atoi(idStr);     
            data[book_amount].Stock = atoi(stockStr);
            book_amount++;
        }
    }
}

void PrintBooks() {
	printf("%-3s | %-40s | %-30s| %-10s | %-4s | %-8s | %-5s\n", "No.", "Nama", "Author", "Genre", "Year", "ID", "Stock");
	for (int i = 0; i < book_amount; i++) {
		printf("%-3d | %-40.40s | %-30.30s| %-10s | %-4d | %-8d | %-5d\n", i + 1, data[i].Title, data[i].Author, data[i].Genre, data[i].Year, data[i].ID, data[i].Stock);
	}
}

void PreviousPage() {
	
}

void NextPage() {
	
}

void SortByTitle(int ascending) {
	
}

void SortByGenre() {
	
}

void AddBook() {
}

void RemoveBook() {
	
}

void FindBook() {
	
}

void SortBook() {
	
}
