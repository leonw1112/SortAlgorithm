CC = g++
CFLAGS = -Wall -g

OBJ = main.o bubble.o heap.o heapify.o insertion.o mergesort.o partition.o quick.o swap.o



main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -MD -MP $< -c -o $@

clean:
	rm *.o ./main *.d
