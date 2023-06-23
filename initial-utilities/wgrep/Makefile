CFLAGS = -Wall -Werror
OBJS = wgrep.o

all: wgrep

wcat: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) wgrep
