#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void scan(int req[], int n, int head, int disk_size) {
    int i, j, total_movement = 0;
    int left[MAX], right[MAX];
    int l = 0, r = 0;

    // Separate requests to left and right of head
    for (i = 0; i < n; i++) {
        if (req[i] < head)
            left[l++] = req[i];
        else
            right[r++] = req[i];
    }

    // Sort left and right arrays
    for (i = 0; i < l - 1; i++)
        for (j = 0; j < l - i - 1; j++)
            if (left[j] < left[j + 1]) {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
    for (i = 0; i < r - 1; i++)
        for (j = 0; j < r - i - 1; j++)
            if (right[j] > right[j + 1]) {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }

    printf("Order of servicing requests:\n");

    // Move towards right (higher tracks)
    for (i = 0; i < r; i++) {
        printf("%d ", right[i]);
        total_movement += abs(head - right[i]);
        head = right[i];
    }

    // If not at the end, go to the end
    if (head != disk_size - 1) {
        total_movement += abs(head - (disk_size - 1));
        head = disk_size - 1;
    }

    // Move towards left (lower tracks)
    for (i = 0; i < l; i++) {
        printf("%d ", left[i]);
        total_movement += abs(head - left[i]);
        head = left[i];
    }

    printf("\nTotal head movement: %d\n", total_movement);
}

int main() {
    int n, i, head, disk_size;
    int req[MAX];

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    scan(req, n, head, disk_size);

    return 0;
}