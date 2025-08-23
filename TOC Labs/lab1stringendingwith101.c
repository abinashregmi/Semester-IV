#include <stdio.h>
#include <string.h>

// Function to check if a string is accepted by the DFA
int check_string_ends_with_101(const char* input_string) {
    int current_state = 0; // Start at state 0

    // Get the length of the input string
    int len = strlen(input_string);

    // If the string is empty, it can't end with "101"
    if (len == 0) {
        return 0;
    }

    // Process each character of the string
    for (int i = 0; i < len; i++) {
        char current_char = input_string[i];

        // Check for invalid characters
        if (current_char != '0' && current_char != '1') {
            printf("Error: Invalid character '%c' in the input string.\n", current_char);
            return 0; // Reject on invalid input
        }

        switch (current_state) {
            case 0:
                if (current_char == '1') {
                    current_state = 1;
                } else {
                    current_state = 0;
                }
                break;
            case 1:
                if (current_char == '0') {
                    current_state = 2;
                } else {
                    current_state = 1;
                }
                break;
            case 2:
                if (current_char == '1') {
                    current_state = 3;
                } else {
                    current_state = 0;
                }
                break;
            case 3:
                if (current_char == '1') {
                    current_state = 1;
                } else {
                    current_state = 0;
                }
                break;
        }
    }

    // The string is accepted if the final state is 3
    return (current_state == 3);
}

int main() {
    char input_string[100];
    printf("Enter binary strings to check (type 'exit' to quit):\n");
    while (1) {
        printf("Input: ");
        scanf("%99s", input_string);
        if (strcmp(input_string, "exit") == 0) {
            break;
        }
        if (check_string_ends_with_101(input_string)) {
            printf("The string '%s' is ACCEPTED.\n", input_string);
        } else {
            printf("The string '%s' is REJECTED.\n", input_string);
        }
    }
    return 0;
}