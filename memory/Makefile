TARGET	:= $(shell pwd).elf

OBJS 	:= ../lib/lib.o main.o
CFLAGS += -I../include -I../../include

.PHONY: all
all: $(TARGET)

.SUFFIXES: .o.c
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $@

clean:
	rm -f *.o
