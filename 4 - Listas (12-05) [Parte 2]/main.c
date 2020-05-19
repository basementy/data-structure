#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/utils.c"

int main() {
  int studentId;
  list studentList;
  student	currentList;
  FILE *studentsFile;

  studentsFile = searchFile();
  createList(&studentList);

  while (studentsFile) {
    fscanf(studentsFile, "%d %s %f",
      &currentList.id,
      currentList.name,
      &currentList.grade
    );

    if (feof(studentsFile))
      break;

    insertList(&studentList, currentList);
  }

  fclose(studentsFile);
  mainMenu(studentList);
}
