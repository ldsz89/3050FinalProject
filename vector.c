#include "../include/vector.h"

void init_vector(vector_t* v) {//realloc memory for new vector elements function 
	v->data = malloc(sizeof(char)*INIT_VECTOR_SIZE);
	v->size = 0;
	v->capacity = INIT_VECTOR_SIZE;
}

int access_element_vector(vector_t* v, size_t index) {//access the elements in vector
	if (index >= v->size)
		exit(OUT_OF_BOUNDS);
	return v->data[index];
}

void insert_element_vector(vector_t* v, char element_to_insert) {//insert element in vector
	if (v->capacity == v->size) {
		v->data = realloc(v->data, sizeof(char)*v->capacity*2);
		v->capacity *= 2;
	}
	v->data[v->size] = element_to_insert;
	v->size += 1;	
}

int get_value_and_clear_vector(vector_t* v) {//get values and empty the vector
	int value;

	v->data[v->size] = '\0';
	value = atoi(v->data);

	memset(v->data, '\0', v->size*sizeof(char));
	v->size = 0;

	return value;
}

void free_vector(vector_t* v) {//free vector
	free(v->data);
	v->size = 0;
}
