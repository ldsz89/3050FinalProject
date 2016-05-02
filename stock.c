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
    int currentDay = 1;
    int currentTrans = 1;
    
    for(currentTrans = 1; currentTrans < transactions; currentTrans++) {
        for(currentDay = 1; currentDay < days; currentDay++) {
            int maxVal = 0;
            
            for(m = 0; m < currentDay; m++) {
                if((price[currentDay] - price[m] + profit[currentTrans - 1][m]) > maxVal) {
                    maxVal = (price[currentDay] - price[m] + profit[currentTrans - 1][m]);
                }
                if(profit[currentTrans][currentDay - 1] < maxVal)
                    profit[currentTrans][currentDay] = maxVal;
                else
                    profit[currentTrans][currentDay] = profit[currentTrans][currentDay - 1];
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