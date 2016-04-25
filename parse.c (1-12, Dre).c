#include "input_error.h"
#include "parse.h"

void parse(FILE* fp, int size) {
    int index = 0, count = 0, count2 = 0;
    int temp;
    char c = '\0';
    /* */
    char line[11] = {'\0','\0','\0','\0','\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    while((c = getc(fp)) != EOF) {
        //printf("%c", c);
        line[index] = c;
        count++;
        index++;
        if(c == '\n' || c == '\r' || c == '\0') {
            parse_test(line);
            getDigits(line, size);
            //printf("\n");
            index = 0;
            count = 0;
            count2++;
        }
        //index++;
    }
    
    return;
}

int parse_test(char *input) {
    int i = 0;
    char c = '\0';
    c = input[i];
    
    while(c != '\0' || c != '\r', c != '\n') {
        if(!isdigit(c)){
            exit(PARSING_ERROR_INVALID_FORMAT);
        }
        i++;
        c = input[i];
    }
    
    return 1;
}

void getDigits(char* str, int size) {
    
    //printf("\nThe current line is: %s\n", str);
    
    int value = atoi(str);
    
    //printf("getDigits(%d)\n", value);
    
    if(value < 0) exit(INTEGER_IS_NOT_A_VERTEX);
}