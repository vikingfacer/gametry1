
OS = $(shell uname)

# graphics stuff OS specific
ifeq ($(OS), Darwin)
	LINKLIBS = -lraylib -framework OpenGL -framework OpenAL -framework Cocoa 
else
	LINKLIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
endif

flags = -std=c++14

LINKLIBS += #Other libs to link


CC = g++ 

headers= userInlib.h

source = test.cpp


.PHONY: clean


all: test

test: $(source) $(headers)
	$(CC) $(flags) $< -o $@ $(LINKLIBS) 


clean:
	rm test