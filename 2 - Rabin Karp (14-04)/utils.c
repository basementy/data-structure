#include <stdio.h>
#include <string.h>
#include "algorithm.c"

void clear() {
  system("@cls||clear");
}

void mainMenu(char text[], char pattern[]) {
  int option;


  do {
    clear();
    printf("Pattern: %s\n\n", pattern);
    printf("Choose a algorithm: \n");
    printf("1 - Rabin Karp\n");
    printf("2 - Brute Force\n");
    printf("3 - Quit\n\n");
    printf("Option: ");
    scanf("%d%*c", &option);

    switch(option) {
      case 1:
        rabinKarp(text, pattern);
      break;
      case 2:
        bruteForce(text, pattern);
      break;
    }
	} while(option != 3);
}

void startConfig() {
  char file[30];
  char text[5000];
  char pattern[30];

  printf("- Insert the file path: ");
  fgets(file, 30, stdin);
  file[strcspn(file, "\n")] = 0;

  clear();

  FILE *arq;
  arq = fopen(file, "r");

  if(arq == NULL){
		printf("Something happen, try again\n");
    system("pause");
    clear();
    startConfig();
  } else {
    while((fgets(text, sizeof(text), arq)) != NULL )
    fclose(arq);
  }

  printf("- Insert the pattern: ");
  fgets(pattern, 50, stdin);
  pattern[strcspn(pattern, "\n")] = 0;

  mainMenu(text, pattern);
}