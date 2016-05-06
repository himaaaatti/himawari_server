#pragma once
#include <stdint.h>
#include <task_call.h>


extern uint64_t receive(struct Message* msg);
extern uint64_t send(struct Message *msg);

