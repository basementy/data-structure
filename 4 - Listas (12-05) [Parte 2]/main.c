#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
	int id;
	float gpa;
	char name[100];
} student;

typedef struct _node {
	student	k;
	struct _node *next;
} node, *list;


void insert_list (list *L, student k) {
	node *p;

  p = (node *) malloc (sizeof (node));
	p->k = k;
	p->next = *L;

	*L = p;
}

student *search_list (list L, int id) {
	node *p;

	for (p = L; p && p->k.id != id; p = p->next);

	if (p)
    return &p->k;
	else
    return NULL;
}

void create_list(list *L) {
	*L = NULL;
}

int main() {
	list C;
	student	s, *p;
	int id;
	FILE *f;

	f = fopen ("./archive/list.txt", "r");
	if (!f) {
		perror ("List");
		exit (1);
	}

	create_list(&C);

	for (;;) {
		fscanf (f, "%d %s %f\n", &s.id, s.name, &s.gpa);

		if (feof (f))
      break;

		insert_list (&C, s);
	}

	fclose (f);

	for (;;) {
		printf ("Enter student ID, -1 to finish: ");
		scanf ("%d", &id);

		if (id == -1)
       break;

		p = search_list (C, id);


		if (!p)
			printf ("ID #%d not found!\n", id);
		else
			printf ("%d\t%s\t%0.2f\n", p->id, p->name, p->gpa);
	}

	exit (0);
}
