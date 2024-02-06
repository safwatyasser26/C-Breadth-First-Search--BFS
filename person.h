// this is the header file to handle object person
#pragma once
#include <string.h>
#include <stdlib.h>
#define MAX 255
#define LEN 50

typedef struct {
	char name[MAX];
	char friends[LEN][MAX];
	int last;
} person;

person* create_person(char name[]) {
	person* newperson = (person*)malloc(sizeof(person));
	
	if (newperson) {
		strncpy(newperson->name, name, MAX);
		newperson->last = 0;
	}
	
	return newperson;
}

void print_person(person* me) {
	printf("%s", me->name);

	for (int i = 0; i < me->last; i++) {
		printf(" -> %s", me->friends[i]);
	}
	printf("\n");
}