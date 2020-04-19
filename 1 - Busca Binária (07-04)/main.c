#include <stdio.h>
#include <stdlib.h>
#include "search.c"

int getInput() {
  int num;

  system("@cls||clear");
  printf("Informe o número que deseja buscar: ");
  scanf("%d", &num);

  return num;
}

int main() {
  int arr[] = { 3, 11, 20, 24, 30, 41, 41, 44, 50, 51, 60, 69, 70, 77, 80, 83, 83, 89, 9 };
  int length = sizeof(arr) / sizeof(arr[0]);
  int number = getInput();
  int result = search(arr, 0, length - 1, number);


  (result == -1)
    ? printf("O elemento não se encontra no array\n")
    : printf("O elemento se encontra no index: %d\n", result);

  return 0;
}