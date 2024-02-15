OBJS =  main.o prelab1.o
CC = gcc-12
CFLAGS = -Wall -Werror -c -g -std=c11
LDFLAGS = -lm

%.o : %.c	
	$(CC) $(CFLAGS) $^

a.out : $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

clean :
	rm -f a.out
	rm -f $(OBJS) 