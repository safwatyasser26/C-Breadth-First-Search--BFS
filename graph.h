// this is the header for dealing with graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include "person.h"

typedef person* graph[LEN];

void init_graph(graph me) {
	for (int i = 0; i < LEN; i++) {
		me[i] = NULL;
	}
}

unsigned int hash(char* name) {
	unsigned int value = 0;

	for (int i = 0; i < strlen(name); i++) {
		value += name[i];
		value = (value * name[i]) % LEN;
	}

	return value;
}

void add_vertex(graph me, char* name, char* value) {
	int index = hash(name);

	if (me[index] != NULL && strncmp(me[index]->name, name, MAX) == 0) {
		strncpy(me[index]->friends[me[index]->last++], value, MAX);
	}
	else if (me[index] == NULL) {
		me[index] = create_person(name);
		strncpy(me[index]->friends[me[index]->last++], value, MAX);
	}
	else if (me[index] != NULL && strncmp(me[index]->name, name, MAX)) {
		for (int i = 0; i < LEN; i++) {
			int try = (index + i) % LEN;
			if (me[try] != NULL && strncmp(me[try]->name, name, MAX)) {
				me[try] = create_person(name);
				strcpy(me[try]->friends[me[try]->last++], value, MAX);
				return;
			}
		}
	}
	else {
		for (int i = 0; i < LEN; i++) {
			int try = (index + i) % LEN;

			if (me[try] == NULL) {
				me[try] = create_person(name);
				strcpy(me[try]->friends[me[try]->last++], value, MAX);
				return;
			}
		}
	}
	//printf("Adding to vertex %d...\n", index);
}

person* get_node(graph me, char* name) {
	int value = hash(name);
	int index = hash(name);
	int found = 0;
	if (me[value] != NULL && strncmp(me[value]->name, name, MAX) == 0) {
		found = 1;
		index = value;
	}
	else if (me[value] != NULL && strncmp(me[value]->name, name, MAX) != 0) {
		int try = value;
		for (int i = 0; i < LEN; i++) {
			try = (value + i) % 10;
			if (me[try] != NULL && strncmp(me[try]->name, name, MAX) == 0) {
				found = 1;
				index = try;
				break;
			}
		}
	}
	
	if (found == 1) {
		return me[index];
	}
	else {
		return NULL;
	}
}

void print_graph(graph me) {
	for (int i = 0; i < LEN; i++) {
		if (me[i] == NULL) {
			printf("\t%i\t---\n", i);
		}
		else {
			printf("\t%i\t", i);
			print_person(me[i]);

		}
	}
}


