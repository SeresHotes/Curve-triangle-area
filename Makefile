
FUNCTION_NUM ?= 1
DIR = calculate/
DEST = f$(FUNCTION_NUM)
DEST_DER = f$(FUNCTION_NUM)_der


BORDER = $(file < $(SPEC_FILE))
p1 = $(word 1, $(BORDER))
p2 = $(word 2, $(BORDER))

all:
	make run
help:
	@echo "set_function: sets function on specific number. Reqires FUNCTION_NUM and SPEC_FILE"
set_function:
	make -s --directory=generate/ 
	generate/debug/generate -o $(DIR)$(DEST).asm -g $(SPEC_FILE) $(DEST)
	generate/debug/generate -o $(DIR)$(DEST_DER).asm -d $(SPEC_FILE) $(DEST_DER)
	
compile:
	make --directory=calculate/
	cp calculate/debug/calculate calculate

run:
	mkdir -p .temp
	split -l 1 $(SPEC_FILE) .temp/
	
	make set_function SPEC_FILE=.temp/ab FUNCTION_NUM=1
	make set_function SPEC_FILE=.temp/ac FUNCTION_NUM=2
	make set_function SPEC_FILE=.temp/ad FUNCTION_NUM=3
	
	make --directory=calculate/ LEFT_BORDER=$(p1) RIGHT_BORDER=$(p2) 
	cp calculate/debug/calculate area_calculation
	
clean:
	rm -rf ./temp
	make --directory=calculate/ clean
	make --directory=generate/ clean
