CC = gcc
CFLAGS = -W -Wall
TARGET = project
DTARGER = project_debug
OBJECTS = market.c manager.o

$(TARGET) : $(OBJECTS)
         $(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
        $(CC) $(CFLAGS) -o $@ $^

clean :
        rm *.o $(TARGET) $(DTARGET)
