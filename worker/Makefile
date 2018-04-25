CC=gcc
CFLAGS=-c -g -Wall
LDFLAGS=-pthread
SOURCES=my_worker.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=workers
DEP=my_worker.h my_cq.h

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) $(DEP)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm workers my_worker.o
