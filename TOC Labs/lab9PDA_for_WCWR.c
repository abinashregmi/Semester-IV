#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Simulates a Pushdown Automaton (PDA) for strings of the form W C WR.
 * * W is any binary string and WR is its reverse. 'C' is a separator. This program
 * checks if the string is of this form by finding the 'C' and comparing the
 * substrings on either side.
 * * @param str The input string.
 * @return true if the string is of the form W C WR, false otherwise.
 */
bool pda_w_c_wr(const char* str) {
    int len = strlen(str);
    int c_pos = -1;
    // Find the position of 'C'
    for (int i = 0; i < len; i++) {
        if (str[i] == 'C') {
            c_pos = i;
            break;
        }
    }
    // If 'C' is not found, or is at the beginning or end, it's not a valid string
    if (c_pos <= 0 || c_pos == len - 1) {
        return false;
    }
    // Check if the length of W is equal to the length of WR
    if (c_pos != len - 1 - c_pos) {
        return false;
    }
    // Compare the first half (W) with the reverse of the second half (WR)
    for (int i = 0; i < c_pos; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("Testing string \"01C10\": %s\n", pda_w_c_wr("01C10") ? "Accept" : "Reject");
    printf("Testing string \"10C11\": %s\n", pda_w_c_wr("10C11") ? "Accept" : "Reject");
    return 0;
}
