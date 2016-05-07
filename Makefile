export CC	:= clang
export CFLAGS 	:= -Wall -ffreestanding -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -std=c11 -nostdlib
export LDFLAGS := -nostdlib

DIRS	:= memory
TARGET_LIST	:= $(foreach dir, $(DIRS), $(dir).elf)

.PHONY: all
all: $(TARGET_LIST)

lib.o:
	cd lib; $(MAKE);
	
$(TARGET_LIST): lib.o
	for dir in $(DIRS); do\
		(cd $$dir; $(MAKE);)\
	done

install_iso:
	for elf in $(TARGET_LIST); do\
		cp $$elf ../../root/boot/$$elf;\
	done

clean:
	cd lib; $(MAKE) clean
	for dir in $(DIRS); do\
		(cd $$dir; $(MAKE) clean;)\
	done

	rm -rf *.elf

