/* 
 * File:   main.c
 * Author: LeAndre
 *
 * Created on April 15, 2016, 4:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "input_error.h"
#include "parse.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    if(argc != 4)
        return(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);
    
    totalDays = 0;
    
    FILE* fp = fopen(argv[3], "r");
    if(fp == NULL) return(FILE_FAILED_TO_OPEN);
    
    int n = atoi(argv[1]);
    int r = atoi(argv[2]);
    printf("Days: %d\nTransactions: %d\n", n, r);
    
    initializeProfits(n, r);
    
    parse(fp, n);
    
    calculateProfits(n,r);
    
    printPrice(n);
        
    printProfits(n, r);

    return (EXIT_SUCCESS);
}

