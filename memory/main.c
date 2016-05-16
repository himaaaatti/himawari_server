#include <task.h>
#include <stdbool.h>
#include <server.h>

#define PAGE_SIZE 0x1000
#define EARLY_MEMORY_SIZE 0x01000000 // 16MB (after ISA memory hole)
#define EARLY_MEMORY_PAGE_NUM (EARLY_MEMORY_SIZE / PAGE_SIZE)
#define BIT_NUMBER_OF_BYTE 8
#define BITMAP_UNIT64_NUM (EARLY_MEMORY_PAGE_NUM / ((sizeof(uint64_t) * BIT_NUMBER_OF_BYTE)))
#define BITMAP_ENTRY_NUM BITMAP_UNIT64_NUM

uint64_t bitmap[BITMAP_ENTRY_NUM];

static void initialize(void)
{
    struct Message msg;

    uint64_t result; 

    // get early memory map
    msg.number = Initialize,
    msg.content.address = (uintptr_t)bitmap;
    msg.content.num = bitmap_size * 8; // bitmap end

    result = send(System, &msg);

    msg.content.address = 0;
    msg.content.num = 0;
    result = receive(System, &msg);

    uintptr_t physical_end_addr = msg.content.end_address;
}

void main(void)
{
    uint64_t result; 

    initialize();

    struct Message msg;
    while (true) {
        result = receive(Any, &msg);
    }
}
