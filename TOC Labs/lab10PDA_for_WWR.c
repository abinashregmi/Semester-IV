#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Simulates a Pushdown Automaton (PDA) for strings of the form W WR.
 * * This is a classic palindrome checker. W is any binary string and WR is its
 * reverse. The string is accepted if it is a palindrome with an even length.
 * * @param str The input string.
 * @return true if the string is a palindrome with an even length, false otherwise.
 */
bool pda_w_wr(const char* str) {
    int len = strlen(str);
    if (len % 2 != 0) {
        // A string with an odd number of characters cannot be W WR (unless W is empty)
        // Let's assume W is non-empty for this problem.
        return false;
    }
    // A string is of the form W WR if it is a palindrome
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("Testing string \"0110\": %s\n", pda_w_wr("0110") ? "Accept" : "Reject");
    printf("Testing string \"100\": %s\n", pda_w_wr("100") ? "Accept" : "Reject");
    return 0;
}
