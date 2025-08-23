#include <stdio.h>
#include <string.h>

#define MAX_BLOCKS 20
#define MAX_FILES 5
#define FILENAME_LEN 20

typedef struct {
    char name[FILENAME_LEN];
    int start;
    int length;
} File;

int disk[MAX_BLOCKS];
File files[MAX_FILES];
int file_count = 0;

void initialize_disk() {
    for (int i = 0; i < MAX_BLOCKS; i++)
        disk[i] = 0;
}

int allocate_file(const char *name, int length) {
    int start = -1;
    for (int i = 0; i <= MAX_BLOCKS - length; i++) {
        int free = 1;
        for (int j = i; j < i + length; j++) {
            if (disk[j] != 0) {
                free = 0;
                break;
            }
        }
        if (free) {
            start = i;
            break;
        }
    }
    if (start == -1 || file_count >= MAX_FILES)
        return 0;

    for (int i = start; i < start + length; i++)
        disk[i] = 1;

    strcpy(files[file_count].name, name);
    files[file_count].start = start;
    files[file_count].length = length;
    file_count++;
    return 1;
}

void display_files() {
    printf("Files:\nName\tStart\tLength\n");
    for (int i = 0; i < file_count; i++)
        printf("%s\t%d\t%d\n", files[i].name, files[i].start, files[i].length);
}

void display_disk() {
    printf("Disk blocks:\n");
    for (int i = 0; i < MAX_BLOCKS; i++)
        printf("%d", disk[i]);
    printf("\n");
}

int main() {
    initialize_disk();

    allocate_file("A.txt", 5);
    allocate_file("B.txt", 3);
    allocate_file("C.txt", 4);
    allocate_file("D.txt", 2);
    allocate_file("E.txt", 3);

    display_files();
    display_disk();

    return 0;
}
