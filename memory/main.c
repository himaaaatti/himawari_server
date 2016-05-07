#include <task.h>
#include <stdbool.h>

void main(void)
{
    uint64_t result; 
    struct Message msg = {
        .source = Memory,
        .dest = System,
        .type = Receive,
        .content = {0,0},
    };

    result = receive(&msg);
    while (true) {
        
    }
}
