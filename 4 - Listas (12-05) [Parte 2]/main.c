#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/utils.c"

int main() {
  int studentId;
  student	currentStudent;
  FILE *listFile;
  head = NULL;
  listFile = searchFile();

  while (listFile) {
    fscanf(listFile, "%d %s %f",
      &currentStudent.id,
      currentStudent.name,
      &currentStudent.grade
    );

    if (feof(listFile))
      break;

    insertNode(currentStudent);
  }

  fclose(listFile);
  mainMenu();
}
