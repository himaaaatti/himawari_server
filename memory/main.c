#include <task.h>
#include <stdbool.h>
#include <server.h>

#define EARLY_MEMORY_PAGE_NUM 64
#define bitmap_size ((EARLY_MEMORY_PAGE_NUM + 64 - 1) >> 6)

uint64_t bitmap[bitmap_size];

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

    if(!msg.content.num)
    {
        while (true) {
            //todo
            //failed
        } 
    }
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
