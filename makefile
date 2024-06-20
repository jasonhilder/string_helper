CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -L. -lstring_helper

TARGET = main
SRCS = main.c
OBJS = $(SRCS:.c=.o)

LIB_SRCS = string_helper.c
LIB_OBJS = $(LIB_SRCS:.c=.o)
LIBRARY = libstring_helper.a

$(TARGET): $(OBJS) $(LIBRARY)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.c string_helper.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBRARY): $(LIB_OBJS)
	ar rcs $(LIBRARY) $(LIB_OBJS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) $(LIB_OBJS) $(LIBRARY)
