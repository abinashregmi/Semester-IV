#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Simulates a Pushdown Automaton (PDA) for well-formed parenthesis.
 * * This function uses a balance counter to simulate a stack. The counter is incremented
 * for each '(' and decremented for each ')'. A string is rejected if the balance
 * drops below zero, and accepted only if the final balance is exactly zero.
 * * @param str The input string of parenthesis.
 * @return true if the parenthesis are well-formed, false otherwise.
 */
bool pda_well_formed_parenthesis(const char* str) {
    int balance = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(') {
            balance++;
        } else if (str[i] == ')') {
            balance--;
            // If balance drops below zero, a closing parenthesis came before an opening one
            if (balance < 0) {
                return false;
            }
        } else {
            // Reject other characters
            return false;
        }
    }
    // For the parenthesis to be well-formed, the balance must be zero at the end
    return balance == 0;
}

int main() {
    printf("Testing string \"()\": %s\n", pda_well_formed_parenthesis("()") ? "Accept" : "Reject");
    printf("Testing string \"())(\": %s\n", pda_well_formed_parenthesis("())(") ? "Accept" : "Reject");
    return 0;
}
