#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int abs_diff(int a, int b) {
    return a > b ? a - b : b - a;
}

int main() {
    int n, head, i, j, min, pos, total = 0;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n], visited[n];
    printf("Enter disk requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Order of servicing requests:\n");
    for (i = 0; i < n; i++) {
        min = 1 << 30; // large number
        pos = -1;
        for (j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = abs_diff(head, req[j]);
                if (dist < min) {
                    min = dist;
                    pos = j;
                }
            }
        }
        visited[pos] = 1;
        printf("%d ", req[pos]);
        total += abs_diff(head, req[pos]);
        head = req[pos];
    }
    printf("\nTotal head movement: %d\n", total);
    return 0;
}