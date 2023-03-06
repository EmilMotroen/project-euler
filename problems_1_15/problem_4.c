/**
 * A palindromic number reads the same both ways. The largest palindrome
 * made from the product of two 2-digit numbers is 9009 = 91 x 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
*/
#include <stdio.h>
#include <string.h>

#define START 2
#define STOP  1000
#define SIZE  7  // Max of six digits and '\0' in array

int checkIfPalindrome(int);

int main(){
    unsigned int max = 0, product = 0, num1, num2;
    for (num1 = START; num1 < STOP; num1++){
        for (num2 = START; num2 < STOP; num2++){
            product = num1 * num2;
            if (checkIfPalindrome(product) == 0){
                if (max < product){
                    max = product;
                }
            }        
        }
    }

    printf("Largest palindrome for two 3-digit numbers: %d\n", max);

    return 0;
}

int checkIfPalindrome(int number){
    char string[SIZE];
    sprintf(string, "%d", number);
    int left = 0, right = strlen(string) - 1;

    while (right > left){
        if (string[left++] != string[right--]){
            return -1;
        }
    }

    return 0;
}