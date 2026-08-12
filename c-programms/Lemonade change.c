#include <stdio.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
    int count_five = 0;
    int count_ten = 0;
    
    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            count_five++;
        } 
        else if (bills[i] == 10) {
            // Change needed: $5
            if (count_five == 0) {
                return false;
            }
            count_five--;
            count_ten++;
        } 
        else { // bills[i] == 20
            // Change needed: $15
            // Greedy Choice: Prioritize using a $10 + $5 over three $5s
            if (count_ten > 0 && count_five > 0) {
                count_ten--;
                count_five--;
            } 
            else if (count_five >= 3) {
                count_five -= 3;
            } 
            else {
                return false;
            }
        }
    }
    
    return true;
}
