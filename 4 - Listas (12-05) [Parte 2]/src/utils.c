#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "listing.c"

void mainMenu(list studentList) {
  int menuOption;

  do {
    system("@cls||clear");
    printf("\nChoose a option: \n\n");
    printf("1 - Search Student\n");
    printf("0 - Quit\n\n");
    printf("Option: ");
    scanf("%d%*c", &menuOption);

    switch(menuOption) {
      case 1:
        searchStudent(studentList);
      break;
    }
	} while(menuOption != 0);
}

FILE *searchFile() {
  char filePath[50];

  printf("\nInsert the file path: ");
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