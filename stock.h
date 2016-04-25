#include "parse.h"

int profit[512][512]; //[transactions][day]
int price[512];
int buyDays[512];
int sellDays[512];
int totalDays;

/* Fill price array with stock prices from file */
void addPrice(int day, int value);

void printPrice(int day);

void initializeProfits(int days, int transactions);

void calculateProfits(int days, int transactions);

void printProfits(int days, int transactions);
