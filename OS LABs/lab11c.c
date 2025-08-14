#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 4
#define MAX_BLOCKS 50
#define MAX_INDEX_BLOCKS 10

typedef struct {
    char filename[20];
    int indexBlock;
    int blocks[MAX_INDEX_BLOCKS];
    int blockCount;
} IndexedFile;

int disk[MAX_BLOCKS] = {0}; // 0 means free, 1 means allocated

void createFile(IndexedFile files[], int *fileCount) {
    if (*fileCount >= MAX_FILES) {
        printf("Maximum file limit reached.\n");
        return;
    }

    IndexedFile file;
    printf("Enter filename: ");
    scanf("%s", file.filename);

    printf("Enter number of blocks required: ");
    scanf("%d", &file.blockCount);

    if (file.blockCount > MAX_INDEX_BLOCKS) {
        printf("Exceeds maximum index blocks per file.\n");
        return;
    }

    // Find a free index block
    int found = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (disk[i] == 0) {
            file.indexBlock = i;
            disk[i] = 1;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No free index block available.\n");
        return;
    }

    // Allocate data blocks
    int allocated = 0;
    for (int i = 0; i < MAX_BLOCKS && allocated < file.blockCount; i++) {
        if (disk[i] == 0) {
            file.blocks[allocated++] = i;
            disk[i] = 1;
        }
    }
    if (allocated < file.blockCount) {
        printf("Not enough free blocks. Rolling back allocation.\n");
        disk[file.indexBlock] = 0;
        for (int i = 0; i < allocated; i++)
            disk[file.blocks[i]] = 0;
        return;
    }

    files[*fileCount] = file;
    (*fileCount)++;
    printf("File created successfully.\n");
}

void displayFiles(IndexedFile files[], int fileCount) {
    printf("\nIndexed File Allocation Table:\n");
    printf("Filename\tIndexBlock\tBlocks\n");
    for (int i = 0; i < fileCount; i++) {
        printf("%s\t\t%d\t\t", files[i].filename, files[i].indexBlock);
        for (int j = 0; j < files[i].blockCount; j++)
            printf("%d ", files[i].blocks[j]);
        printf("\n");
    }
}

int main() {
    IndexedFile files[MAX_FILES];
    int fileCount = 0;

    for (int i = 0; i < MAX_FILES; i++) {
        printf("\nCreating file %d of %d:\n", i + 1, MAX_FILES);
        createFile(files, &fileCount);
    }

    displayFiles(files, fileCount);

    return 0;
}
