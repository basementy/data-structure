#include <stdio.h>
#include <string.h>

#define alphabet 256
#define prime 29

void bruteForce(char text[], char pattern[]) {
  system("@cls||clear");

  printf("Brute Force Algorithm\n\n");

  int matches;
  int textLength = strlen(text);
  int patternLength = strlen(pattern);

  for (int i = 0; i <= textLength - patternLength; i++) {
    int j;

    // Para o atual index da janela, cheque se existe match
    for (j = 0; j < patternLength; j++)
      if (text[i + j] != pattern[j]) // Se não existir match, incremente a janela
        break;

    // Se o tamanho total da janela com matches for igual ao do pattern, então mostre o index
    if (j == patternLength) {
      matches++;
      printf("Pattern found at index %d \n", i);
    }
  }

  // Caso não exista matches
  if (matches == 0)
    printf("Pattern not found\n");

  getchar();
};

void rabinKarp(char text[], char pattern[]) {
  system("@cls||clear");

  printf("Rabin Karp Algorithm\n\n");

  int i, j;
  int hash = 1;
  int matches;
  int patternHash = 0;
  int textHash = 0;
  int patternLength = strlen(pattern);
  int textLength = strlen(text);

  // Calcula o hash
  for (i = 0; i < patternLength - 1; i++)
    hash = (hash * alphabet) % prime;

  // Calcula o hash do pattern e da primeira janela
  for (i = 0; i < patternLength; i++) {
    patternHash = (alphabet * patternHash + pattern[i]) % prime;
    textHash = (alphabet * textHash + text[i]) % prime;
  }

  for (i = 0; i <= textLength - patternLength; i++) {
    // Caso aconteça de match entre hash's, analise cada posição
    if (patternHash == textHash) {
      for (j = 0; j < patternLength; j++) { 
        if (text[i + j] != pattern[j])
          break;
      }

      // Se o tamanho total de matches for igual ao do pattern, então mostre o index
      if (j == patternLength) {
        matches++;
        printf("Pattern found at index %d \n", i);
      }
    }

    // Calcula o hash da proxima janela removendo o ultimo index utilizado e adicionado um novo
    if (i < textLength - patternLength) {
      textHash = (alphabet * (textHash - text[i] * hash) + text[i + patternLength]) % prime;

      // Caso o valor seja dado como negativo, então ele é convertido com o número primo
      if (textHash < 0)
        textHash = (textHash + prime);
    }
  }

  // Caso não exista matches
  if (matches == 0)
    printf("Pattern not found\n");

  getchar();
};