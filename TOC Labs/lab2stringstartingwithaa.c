#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Checks if a string starts with the substring "aa".
 * * This function acts as a simple Finite Automaton (FA) that accepts a string
 * only if its first two characters are 'a' and 'a'.
 * * @param str The input string.
 * @return true if the string starts with "aa", false otherwise.
 */
bool accepts_starting_with_aa(const char* str) {
    // Check if the string has at least two characters
    if (strlen(str) < 2) {
        return false;
    }
    // Check if the first two characters are 'a' and 'a'
    if (str[0] == 'a' && str[1] == 'a') {
        return true;
    }
    return false;
}

int main() {
    printf("Testing string \"aaba\": %s\n", accepts_starting_with_aa("aaba") ? "Accept" : "Reject");
    printf("Testing string \"baa\": %s\n", accepts_starting_with_aa("baa") ? "Accept" : "Reject");
    return 0;
}
