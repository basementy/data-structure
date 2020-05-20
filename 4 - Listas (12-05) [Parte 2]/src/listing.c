#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.c"

node *createNewNode(student data) {
	node *newNode = (node*)malloc(sizeof(node));

	newNode->student = data;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

void insertNode(student data) {
  node *temporaryNode = head;
  node *newNode = createNewNode(data);

  if (head == NULL) {
		head = newNode;
		return;
	}

  while (temporaryNode->next != NULL)
    temporaryNode = temporaryNode->next;

  temporaryNode->next = newNode;
	newNode->prev = temporaryNode;
}

student *searchList(int studentId) {
	node *listPointer;

	for (
    listPointer = head;
    listPointer && listPointer->student.id != studentId;
    listPointer = listPointer->next
  );

  if (listPointer)
  	return &listPointer->student;
	else
    return NULL;
}

void deleteStudent(int studentId) {
  for (
    head;
    head && head->student.id != studentId;
    head->next
  );

  system("@cls||clear");

  if (head) {
    if (head->next == NULL) {
      head = NULL;
      free(head);
    } else {
      node *listPointer = head;
      head = head->next;
      head->prev = NULL;
      free(listPointer);
    }

    printf("Student successfully deleted\n");
  } else {
    printf("Student doesn't exist\n\n");
  }

  getchar();
  getchar();
}

void searchAndDelete() {
  int studentId;

  system("@cls||clear");
  printf("Enter student ID: ");
  scanf("%d", &studentId);

  deleteStudent(studentId);
}

void searchStudent() {
  int studentId = 1;
  student *studentPointer;

  do {
    system("@cls||clear");
    printf("Enter student ID (0 to exit): ");
		scanf("%d", &studentId);

    if (studentId == 0)
      return;

    studentPointer = searchList(studentId);

		if (!studentPointer) {
			printf("Student ID #%d not found!\n", studentId);
    } else {
      printf("\nID\t Name\t Grade\n");
			printf("%d\t %s\t %0.2f",
        studentPointer->id,
        studentPointer->name,
        studentPointer->grade
      );
    }

    getchar();
    getchar();

  } while (studentId != 0);
}

void printListAscendant() {
	node *temporaryNode = head;
  student *temporaryStudent;

  system("@cls||clear");
  printf("Students: \n\n");
  printf("ID\t Name\t Grade\n");

	while(temporaryNode != NULL) {
    temporaryStudent = &temporaryNode->student;

    printf("%d\t %s\t %0.2f\n",
      temporaryStudent->id,
      temporaryStudent->name,
      temporaryStudent->grade
    );

    temporaryNode = temporaryNode->next;
	}

  getchar();
}

void printListDescendant() {
	node *temporaryNode = head;
  student *temporaryStudent;

	if(temporaryNode == NULL) return;

	while(temporaryNode->next != NULL) {
		temporaryNode = temporaryNode->next;
	}

	system("@cls||clear");
  printf("Students: \n\n");
  printf("ID\t Name\t Grade\n");

	while(temporaryNode != NULL) {
    temporaryStudent = &temporaryNode->student;

		printf("%d\t %s\t %0.2f\n",
      temporaryStudent->id,
      temporaryStudent->name,
      temporaryStudent->grade
    );

		temporaryNode = temporaryNode->prev;
	}

	getchar();
}