#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Checks if a string has an even number of '0's and an odd number of '1's.
 * * This program counts the occurrences of '0's and '1's and then checks for
 * the specified parity. It simulates a simple state machine.
 * * @param str The input string.
 * @return true if the string meets the criteria, false otherwise.
 */
bool accepts_even0s_odd1s(const char* str) {
    int zeros = 0;
    int ones = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '0') {
            zeros++;
        } else if (str[i] == '1') {
            ones++;
        }
    }
    // Check if the number of zeros is even and the number of ones is odd
    return (zeros % 2 == 0) && (ones % 2 != 0);
}

int main() {
    printf("Testing string \"001\": %s\n", accepts_even0s_odd1s("001") ? "Accept" : "Reject");
    printf("Testing string \"010\": %s\n", accepts_even0s_odd1s("010") ? "Accept" : "Reject");
    return 0;
}
