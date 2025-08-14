#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100
#define MAX_FILES 4
#define FILENAME_LEN 20

typedef struct Block {
    int block_num;
    struct Block *next;
} Block;

typedef struct File {
    char name[FILENAME_LEN];
    Block *start;
} File;

int free_blocks[MAX_BLOCKS];
File files[MAX_FILES];
int file_count = 0;

void init_blocks() {
    for (int i = 0; i < MAX_BLOCKS; i++)
        free_blocks[i] = 1;
}

int allocate_block() {
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (free_blocks[i]) {
            free_blocks[i] = 0;
            return i;
        }
    }
    return -1;
}

void create_file(const char *name, int size) {
    if (file_count >= MAX_FILES) return;
    File *f = &files[file_count];
    strncpy(f->name, name, FILENAME_LEN);
    f->start = NULL;
    Block *prev = NULL;
    for (int i = 0; i < size; i++) {
        int blk_num = allocate_block();
        if (blk_num == -1) break;
        Block *new_blk = (Block *)malloc(sizeof(Block));
        new_blk->block_num = blk_num;
        new_blk->next = NULL;
        if (prev)
            prev->next = new_blk;
        else
            f->start = new_blk;
        prev = new_blk;
    }
    file_count++;
}

void display_files() {
    printf("\nFiles and their blocks:\n");
    for (int i = 0; i < file_count; i++) {
        printf("File: %s -> ", files[i].name);
        Block *cur = files[i].start;
        while (cur) {
            printf("%d ", cur->block_num);
            cur = cur->next;
        }
        printf("\n");
    }
}

int main() {
    init_blocks();
    create_file("file1.txt", 5);
    create_file("file2.txt", 3);
    create_file("file3.txt", 4);
    create_file("file4.txt", 2);
    display_files();
    // Free memory
    for (int i = 0; i < file_count; i++) {
        Block *cur = files[i].start;
        while (cur) {
            Block *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    return 0;
}