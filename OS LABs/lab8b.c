#include <stdio.h>
#include <stdlib.h>

// Structure to represent a free memory block
struct FreeBlock {
    int start_address;
    int size;
    struct FreeBlock *next;
};

// Global pointer to the head of the free list
struct FreeBlock *free_list = NULL;

// Function to initialize the free list with a single large block
void initialize_free_list(int total_memory_size) {
    free_list = (struct FreeBlock *)malloc(sizeof(struct FreeBlock));
    if (free_list == NULL) {
        printf("Memory allocation failed for free list initialization.\n");
        exit(1);
    }
    free_list->start_address = 0;
    free_list->size = total_memory_size;
    free_list->next = NULL;
    printf("Free list initialized with a block of size %d at address 0.\n", total_memory_size);
}

// Function to allocate memory using First Fit strategy
int allocate_memory(int requested_size) {
    struct FreeBlock *current = free_list;
    struct FreeBlock *previous = NULL;

    while (current != NULL) {
        if (current->size >= requested_size) {
            // Found a suitable block
            int allocated_address = current->start_address;

            if (current->size == requested_size) {
                // Exact fit, remove the block from the free list
                if (previous == NULL) {
                    free_list = current->next;
                } else {
                    previous->next = current->next;
                }
                free(current);
            } else {
                // Partial fit, adjust the existing block
                current->start_address += requested_size;
                current->size -= requested_size;
            }
            printf("Allocated %d bytes at address %d.\n", requested_size, allocated_address);
            return allocated_address;
        }
        previous = current;
        current = current->next;
    }
    printf("Not enough free memory to allocate %d bytes.\n", requested_size);
    return -1; // Allocation failed
}

// Function to free memory and add it back to the free list
void free_memory(int address, int size) {
    struct FreeBlock *new_block = (struct FreeBlock *)malloc(sizeof(struct FreeBlock));
    if (new_block == NULL) {
        printf("Memory allocation failed for new free block.\n");
        exit(1);
    }
    new_block->start_address = address;
    new_block->size = size;
    new_block->next = NULL;

    // Insert the new free block into the free list (maintaining sorted order by address)
    if (free_list == NULL || address < free_list->start_address) {
        new_block->next = free_list;
        free_list = new_block;
    } else {
        struct FreeBlock *current = free_list;
        while (current->next != NULL && current->next->start_address < address) {
            current = current->next;
        }
        new_block->next = current->next;
        current->next = new_block;
    }

    // Merge adjacent free blocks (coalescing)
    struct FreeBlock *temp = free_list;
    while (temp != NULL && temp->next != NULL) {
        if (temp->start_address + temp->size == temp->next->start_address) {
            temp->size += temp->next->size;
            struct FreeBlock *to_free = temp->next;
            temp->next = temp->next->next;
            free(to_free);
        } else {
            temp = temp->next;
        }
    }
    printf("Freed %d bytes at address %d.\n", size, address);
}

// Function to display the current state of the free list
void display_free_list() {
    printf("\n--- Free List --- \n");
    struct FreeBlock *current = free_list;
    if (current == NULL) {
        printf("Free list is empty.\n");
        return;
    }
    while (current != NULL) {
        printf("Block: Address = %d, Size = %d\n", current->start_address, current->size);
        current = current->next;
    }
    printf("-------------------\n");
}

int main() {
    initialize_free_list(1000); // Initialize with 1000 units of memory

    display_free_list();

    int addr1 = allocate_memory(200);
    display_free_list();

    int addr2 = allocate_memory(150);
    display_free_list();

    int addr3 = allocate_memory(500);
    display_free_list();

    free_memory(addr1, 200);
    display_free_list();

    free_memory(addr3, 500); // This should coalesce with the previously freed block if adjacent
    display_free_list();

    int addr4 = allocate_memory(400);
    display_free_list();

    return 0;
}