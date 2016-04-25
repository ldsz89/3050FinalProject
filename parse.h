/* 
 * File:   parse.h
 * Author: LeAndre
 *
 * Created on April 15, 2016, 4:34 PM
 */

#ifndef PARSE_H
#define PARSE_H

#include <stdio.h>
#include <stdlib.h>

/* Parses input string and returns numbers found */
void parse(FILE* fp, int size);

/* Checks format of given string */
int parse_test(char *input, int length);

/* Gets the numbers from line given */
void getDigits(char* str, int size);

#endif /* PARSE_H */

