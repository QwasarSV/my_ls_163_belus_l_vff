
# set default compiler
CC = gcc

# CFLAGS variable 
# -g
# -Wall give verbose compiler warnings
# -o0 do not optimize generated code
# -std=c99 use the c99 standard language defintion
# -Wextra enables extra warnings flag
# -Werror make all warning into error
CFLAGS = -g3 -fsanitize=address 
#-Wall -Wextra -Werror 

# LDFLAGS sets flags for linker
#-1m says to link in libm
# LDFLAGS = -1m

# list files that are parts of the project 

SOURCES = *.c
#SOURCES = $(wildcard *.c) #list src file


OBJECTS = $(SOURCES:.c)
#OBJECTS = $(patsubst %.c, %.o, $(SOURCES)) #list obj files.


TARGET = my_node_test

# first target defined in Makefile is the one
# used when makefile file is invoked with no argument. given the defintions.
# above, this Makefile will build the one named TARGET and 
# assume that it depend on all the named objects files. 

$(TARGET) :
	$(CC)  $(SOURCES) -o $@ -IC $^ $(CFLAGS)   

#phony means not a real target, it doesn't build anything
#the phony target clean is used to remove all compiled object files.

.PHONY: fclean

fclean:
	@rm -f $(TARGET) $(OBJECTS) core 

.PHONY: run

run:
	@./$(TARGET) 