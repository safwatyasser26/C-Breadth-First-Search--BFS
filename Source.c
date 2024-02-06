#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include "person.h"
#include "graph.h"
#include "queue.h"

typedef struct {
	char arr[LEN][MAX];
	int last;
}array;

array* create_array() {
	array* me = (array*)malloc(sizeof(array));
	if (me) me->last = 0;
	return me;
}

void array_insert(array* me, char* value) {
	strncpy(me->arr[me->last++], value, MAX);
}

bool is_element(array* me, char* value) {
	if (value[0] == '\0') return false;
	for (int i = 0; i <= me->last; i++) {
		if (strncmp(me->arr[i], value, MAX) == 0) return true;
	}

	return false;
}

bool is_seller(char* name) {
	return name[strlen(name) - 1] == 't';
}

bool breadth_first_search(graph me, char* name) {
	queue* search_queue = create_queue();

	for (int i = 0; i < get_node(me, name)->last; i++) {
		enqueue(search_queue, get_node(me, name)->friends[i]);
	}
	array* searched = create_array();

	while (!isEmpty(search_queue)) {
		char person[MAX];
		strncpy(person, dequeue(search_queue), MAX);
		if (strncmp(person, "", MAX) == 0) continue;
		printf("-> %s", person);
		if (!is_element(searched, person)) {
			
			if (is_seller(person)) {
				printf("\n%s is a mango seller.\n", person);
				return true;
			}
			else {
				//if (strncmp(get_node(me, person)->friends[0], "", MAX) == 0) break;
					for (int i = 0; i < get_node(me, person)->last; i++) {
						enqueue(search_queue, get_node(me, person)->friends[i]);
					}
					array_insert(searched, person);
					
				
			}
		}
		

	}
	
	return false;
}

int main()
{
	// declaring the graph and its vertices 
	// hint: this can be done by scanf but this for test
	graph mygraph;
	init_graph(mygraph);

	add_vertex(mygraph, "safwat", "bob");
	add_vertex(mygraph, "safwat", "hamdy");
	add_vertex(mygraph, "safwat", "abdullah");

	add_vertex(mygraph, "bob", "hamdy");
	add_vertex(mygraph, "bob", "mossaad");

	add_vertex(mygraph, "hamdy", "");

	add_vertex(mygraph, "abdullah", "scront");

	add_vertex(mygraph, "scront", "mossaad");
	add_vertex(mygraph, "mossaad", "");



	//printf("%s", get_node(mygraph, "bob")->friends[1]);
	
	breadth_first_search(mygraph, "safwat");

	
	
	//system("pause");
	return 0;
}