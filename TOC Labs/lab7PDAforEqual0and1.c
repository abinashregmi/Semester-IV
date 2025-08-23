#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Simulates a Pushdown Automaton (PDA) for strings with an equal number of 0's and 1's.
 * * This function uses a balance counter to simulate a stack. The counter is incremented
 * for each '0' and decremented for each '1'. A string is accepted if the balance
 * is 0 at the end.
 * * @param str The input string.
 * @return true if the string has an equal number of 0's and 1's, false otherwise.
 */
bool pda_equal_0s_1s(const char* str) {
    int balance = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '0') {
            balance++;
        } else if (str[i] == '1') {
            balance--;
        } else {
            // Reject non-binary characters
            return false;
        }
    }
    // An equal number of 0s and 1s means the balance ends at 0
    return balance == 0;
}

int main() {
    printf("Testing string \"0011\": %s\n", pda_equal_0s_1s("0011") ? "Accept" : "Reject");
    printf("Testing string \"001\": %s\n", pda_equal_0s_1s("001") ? "Accept" : "Reject");
    return 0;
}
