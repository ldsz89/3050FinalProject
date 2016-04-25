/* 
 * File:   input_error.h
 * Author: LeAndre
 *
 * Created on April 15, 2016, 4:34 PM
 */

#ifndef INPUT_ERROR_H
#define INPUT_ERROR_H

enum error {
    INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS = 1,
    FILE_FAILED_TO_OPEN,
    FILE_FAILED_TO_CLOSE,
    PARSING_ERROR_INVALID_FORMAT,
    PARSING_ERROR_EMPTY_FILE,
    INTEGER_IS_NOT_A_VERTEX,
};

#endif /* INPUT_ERROR_H */

