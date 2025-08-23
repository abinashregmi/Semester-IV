#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Checks if a binary string has an equal number of '1's and '0's.
 * * This program counts the number of '1's and '0's in the string and checks
 * if their counts are equal.
 * * @param str The input binary string.
 * @return true if the number of '1's and '0's are equal, false otherwise.
 */
bool accepts_equal_ones_and_zeros(const char* str) {
    int ones = 0;
    int zeros = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '1') {
            ones++;
        } else if (str[i] == '0') {
            zeros++;
        } else {
            // Reject if the string contains non-binary characters
            return false;
        }
    }
    return ones == zeros;
}

int main() {
    printf("Testing string \"0101\": %s\n", accepts_equal_ones_and_zeros("0101") ? "Accept" : "Reject");
    printf("Testing string \"101\": %s\n", accepts_equal_ones_and_zeros("101") ? "Accept" : "Reject");
    return 0;
}
