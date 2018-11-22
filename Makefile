

LINKLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
CC = g++ 
source = test.cpp


.PHONY: clean


all: test

test: test.cpp
	$(CC) $< -o $@ $(LINKLIBS) 


clean:
	rm test