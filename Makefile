EXEC = bin-swap bin-bubble bin-merge
SH = test-swap.sh test-bubble.sh
.PHONY: all
all: $(EXEC)

CC ?= gcc
CFLAGS = -std=gnu99 -Wall -O2 -g
LDFLAGS =

OBJS := \
	swap.o \
	bubble.o \
	stub.o \
	merge.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

bin-%: %.o stub.o
	$(CC) -o $@ $^ $(LDFLAGS)

check: $(EXEC) $(SH)
	bash test-swap.sh data-swap.in result-swap
	bash test-bubble.sh data-bubble.in result-bubble
	bash test-merge.sh data-merge.in result-merge
swap-check: $(EXEC) $(SH)
	-rm result-swap
	bash test-swap.sh data-swap.in result-swap
bubble-check: $(EXEC) $(SH)
	-rm result-bubble
	bash test-bubble.sh data-bubble.in result-bubble
merge-check: $(EXEC) $(SH)
	-rm result-merge
	bash test-merge.sh data-merge.in result-merge
	
clean:
	$(RM) $(EXEC) $(OBJS) result-swap result-bubble
