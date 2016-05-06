TARGET	:= 	lib.o

OBJS	:= task_call.o startup.o

CFLAGS += -I ../../include -I../include

.PHONY: all
all: $(TARGET)

.SUFFIXES: .o.S.c
.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<
.S.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<


$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -r $(OBJS) -o $@


clean:
	rm -f *.o
