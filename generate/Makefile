CC := gcc
CFLAGS := -g -Wall
LIBS := #libc libm
DEBUG_FOLDER := debug/

EXECUTABLE := generate
SOURCES := $(wildcard ../*.c)
OBJECTS := $(notdir $(patsubst %.c, %.o, $(SOURCES)))

.PHONY: debug
all: debug
	
	
debug:
	mkdir -p $(DEBUG_FOLDER)
	make --directory=$(DEBUG_FOLDER) --makefile=../Makefile usual
	
usual: $(EXECUTABLE)
	
$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	
	
	
%.o: ../%.c
	@echo $@ " :" $<
	$(CC) $(CFLAGS) -c $< -MD


include $(wildcard *.d) 


clean:
	rm -rf $(DEBUG_FOLDER)*.o $(DEBUG_FOLDER)*.d $(DEBUG_FOLDER)$(EXECUTABLE)
