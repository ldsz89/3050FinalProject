/* 
 * File:   stock.c
 * Author: LeAndre
 *
 * Created on April 22, 2016, 7:20 PM
 */

#include "stock.h"

void addPrice(int day, int value) {
    price[day-1] = value;
}

void printPrice(int day) {
    int i = 1;
    for(i = 0; i < day; i++)
        printf("Day %d: %d\n", i, price[i]);
}

void initializeProfits(int days, int transactions) {
    int i;
    int j;
    
    for(i = 0; i <= transactions; i++) {
        price[i] = 0;
        for(j = 0; j <= days; j++) {
            profit[i][j] = 0;
        }
    }
}

void calculateProfits(int days, int transactions) {
    int m = 1;
    int j = 1;
    int i = 1;
    
    for(i = 1; i < transactions; i++) {
        for(j = 1; j < days; j++) {
            int maxVal = 0;
            
            for(m = 0; m < j; m++) {
                if((price[j] - price[m] + profit[i - 1][m]) > maxVal) {
                    maxVal = (price[j] - price[m] + profit[i - 1][m]);
                }
                if(profit[i][j - 1] < maxVal)
                    profit[i][j] = maxVal;
                else
                    profit[i][j] = profit[i][j - 1];
            }
        }
    }
}

void printProfits(int days, int transactions) {
    int i;
    int j;
    
    for(i = 1; i <= transactions; i++) {
        printf("Transaction %d:\t", i);
        for(j = 1; j <= days; j++) {
            printf("%d\t", profit[i][j]);
        }
        printf("\n");
    }
}
