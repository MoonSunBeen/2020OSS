CC = gcc
CFLAGS = -W -Wall
TARGET = project
OBJECTS = market.c product.o

$(TARGET) : $(OBJECTS)
         $(CC) $(CFLAGS) -o $@ $^

clean :
        rm *.o $(TARGET) $(DTARGET)
