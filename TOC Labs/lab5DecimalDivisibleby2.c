#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Checks if a decimal number, represented as a string, is divisible by 2.
 * * A number is divisible by 2 if its last digit is even (0, 2, 4, 6, 8).
 * This program checks the last character of the input string.
 * * @param str The input string representing a decimal number.
 * @return true if the number is divisible by 2, false otherwise.
 */
bool accepts_divisible_by_2(const char* str) {
    // Check if the string is empty
    if (strlen(str) == 0) {
        return false;
    }
    // Get the last character of the string
    char last_char = str[strlen(str) - 1];
    // Check if the last character is a decimal digit
    if (last_char >= '0' && last_char <= '9') {
        int digit = last_char - '0';
        // A number is divisible by 2 if its last digit is even
        return digit % 2 == 0;
    }
    return false;
}

int main() {
    printf("Testing string \"124\": %s\n", accepts_divisible_by_2("124") ? "Accept" : "Reject");
    printf("Testing string \"55\": %s\n", accepts_divisible_by_2("55") ? "Accept" : "Reject");
    return 0;
}
