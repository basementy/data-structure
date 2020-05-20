#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listing.c"

void mainMenu() {
  int menuOption;

  do {
    system("@cls||clear");
    printf("Choose a option: \n\n");
    printf("1 - Search Student\n");
    printf("2 - Print List (Ascendant)\n");
    printf("3 - Print List (Descendant)\n");
    printf("4 - Delete Student\n");
    printf("0 - Quit\n\n");
    printf("Option: ");
    scanf("%d%*c", &menuOption);

    switch(menuOption) {
      case 1:
        searchStudent();
      break;
      case 2:
        printListAscendant();
      break;
      case 3:
        printListDescendant();
      break;
      case 4:
        searchAndDelete();
      break;
    }
	} while(menuOption != 0);
}

FILE *searchFile() {
  char filePath[50];

  system("@cls||clear");
  printf("Insert the file path: ");
  fgets(filePath, 50, stdin);
  filePath[strcspn(filePath, "\n")] = 0;

  FILE *file;
	file = fopen(filePath, "r");

  if (!file) {
		perror("List");
		exit(1);
	}

  return file;
}