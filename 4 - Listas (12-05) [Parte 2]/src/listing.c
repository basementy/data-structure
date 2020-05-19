#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createList(list *studentList) {
	*studentList = NULL;
}

void insertList(list *studentList, student listKey) {
	node *listPointer;

  listPointer = (node*)malloc(sizeof(node));
	listPointer->student = listKey;
	listPointer->next = *studentList;

	*studentList = listPointer;
}

student *searchList(list studentList, int studentId) {
	node *listPointer;

	for (
    listPointer = studentList;
    listPointer && listPointer->student.id != studentId;
    listPointer = listPointer->next
  );

  if (listPointer)
  	return &listPointer->student;
	else
    return NULL;
}

void searchStudent(list studentList) {
  int studentId;
  student *studentPointer;

  while (studentId != -1) {
    system("@cls||clear");
    printf("\nEnter student ID (0 to exit): ");
		scanf("%d", &studentId);

		studentPointer = searchList(studentList, studentId);

		if (!studentPointer)
			printf("\nStudent ID #%d not found!\n", studentId);
		else
			printf("\n%d\t%s\t%0.2f\n",
        studentPointer->id,
        studentPointer->name,
        studentPointer->grade
      );

    getchar();
    getchar();
  }
}