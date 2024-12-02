#include <stdio.h>

int DisplayTitle() {
    FILE *file;
    char line[256];

    file = fopen("Images/Title.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
