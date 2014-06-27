CCFLAGS=-g -Wall -O2
LDFLAGS=-g
NO_CMOV_FLAGS= \
	-fno-tree-loop-if-convert \
	-fno-tree-loop-if-convert-stores \
	-fno-if-conversion \
	-fno-if-conversion2
OBJS=main.o test_cmov.o test_branch.o

main: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

main.o: main.c
	$(CC) $(CCFLAGS) -c $<

test_cmov.o: test_cmov.c
	$(CC) $(CCFLAGS)  -c $<

test_branch.o: test_branch.c
	$(CC) $(CCFLAGS) $(NO_CMOV_FLAGS) -c $<

run: main
	./main > out.csv
	./plot.gnuplot

clean:
	rm -f out.csv out.png
	rm -f *.o
	rm -f main
