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
        if(c == '\n' || c == '\r' || c == '\0'){    
            temp = parse_test(line, count);
            if(temp == 1) {
                getDigits(line, size);
                //printf("%d: RIght format\n", count2+1);
            }
            else{
                //printf("%d: Wrong format\n", count2+1);
                //exit(PARSING_ERROR_INVALID_FORMAT);
            }
            //printf("\n");
            index = 0;
            count = 0;
            count2++;
        }
        //index++;
    }
    // The last input you wanna check
    return;
}

int parse_test(char *input, int length) {
    char* num1, num2;
    //char right_format[3] = {'(', ',', ')'};
    char temp[4] = {'\0', '\0', '\0', '\0'};
    int index1 =0, index2 = 0, count = 0;
    // printf("%d\n", length);
    
    while(index1  < length){
        if(!(isdigit(input[index1]))){
            //printf("%c", input[index1]);
            temp[index2] = input[index1];
            index2++;
        }
        index1++;
    }
    
    index1 = 0;
    char right_format[4] = {'(', ',',',', ')'};
    count = 0;
    while(index1 < 3){
        // printf("%c", temp[index1]);
        if(temp[index1] == right_format[index1]){
            count++;
        }
        index1++;
    }
    
    if(count == 3) return 1;
    else return -1;
   
}

void getDigits(char* str, int size) {
    
    //printf("\nThe current line is: %s\n", str);
    
    int v1, v2, w;
    char *token = NULL;
    char *token2 = NULL;
    char *token3 = NULL;
    token = strtok(str, ",()");
    //printf("Token 1: %s\n", token);
    token2 = strtok(NULL, ",)(");
    //printf("Token 2: %s\n", token2);
    token3 = strtok(NULL, ")(,");
    //printf("Token 3: %s\n", token3);
    
    v1 = atoi(token);
    v2 = atoi(token2);
    w = atoi(token3);
    //printf("Vector: (%d,%d,%d)\n", v1, v2, w);
    
    if(v1 > size || v1 < 1 || v2 > size || v2 < 1) exit(INTEGER_IS_NOT_A_VERTEX);
    
    //addEdge(graph, v1, v2, w);
    addMatrixEdge(v1, v2, w);
}