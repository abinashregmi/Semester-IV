#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Checks if a string contains at least three consecutive '1's.
 * * This function simulates a simple Finite Automaton (FA) to detect a sequence
 * of three or more '1's anywhere within the input string.
 * * @param str The input string.
 * @return true if the string contains three or more consecutive '1's, false otherwise.
 */
bool accepts_three_consecutive_ones(const char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '1') {
            count++;
            if (count >= 3) {
                return true;
            }
        } else {
            // Reset the count if a character other than '1' is found
            count = 0;
        }
    }
    return false;
}

int main() {
    printf("Testing string \"01110\": %s\n", accepts_three_consecutive_ones("01110") ? "Accept" : "Reject");
    printf("Testing string \"1101\": %s\n", accepts_three_consecutive_ones("1101") ? "Accept" : "Reject");
    return 0;
}
