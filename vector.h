#ifndef H_VECTOR_H
#define H_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INIT_VECTOR_SIZE 512

enum vector_errors {
	OUT_OF_BOUNDS = 0,
};

typedef struct vector {
	char* data;
	int size;//total size of the vector
	int capacity;//number of vectors in it currently
} vector_t;

void init_vector(vector_t* v);
int access_element_vector(vector_t* v, size_t index);
void insert_element_vector(vector_t* v, char element_to_insert);
int get_value_and_clear_vector(vector_t* v);
void free_vector(vector_t* v);

#endif
