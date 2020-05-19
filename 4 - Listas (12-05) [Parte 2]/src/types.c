#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	int id;
	float grade;
	char name[100];
} student;

typedef struct node {
	student	student;
	struct node *next;
} node, *list;
