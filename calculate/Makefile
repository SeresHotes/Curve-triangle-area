CC := gcc
ASM := nasm
ASMFLAGS := -f elf32
CFLAGS := -g -Wall -m32
LIBS := /usr/lib32/libc.so /usr/lib32/libm.so
DEBUG_FOLDER := debug/

LEFT_BORDER ?= -10
RIGHT_BORDER ?= 10


EXECUTABLE := $(DEBUG_FOLDER)calculate
SOURCES := $(wildcard *.c *.asm)
OBJECTS :=  $(addprefix $(DEBUG_FOLDER), $(patsubst %.asm, %.o, $(patsubst %.c, %.o, $(SOURCES))))

.PHONY: debug
all: $(EXECUTABLE)
	@echo $(OBJECTS)
	@echo $(SOURCES)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	
	
	
$(DEBUG_FOLDER)%.o: %.c
	@echo $@ " :" $<
	$(CC) $(CFLAGS) -c $< -MD -o $@ -DLEFT_BORDER=$(LEFT_BORDER) -DRIGHT_BORDER=$(RIGHT_BORDER)
$(DEBUG_FOLDER)%.o: %.asm
	@echo $@ " :" $<
	$(ASM) $(ASMFLAGS) $< -o $@


include $(wildcard *.d) 


clean:
	rm -rf $(DEBUG_FOLDER)*.o $(DEBUG_FOLDER)*.d $(DEBUG_FOLDER)$(EXECUTABLE)
