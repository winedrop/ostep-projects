CFLAGS = -Wall -Werror
OBJS = wcat.o

all: wcat

wcat: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) wcat
