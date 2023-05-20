CC = gcc

all : naive kmp

hw1_naive : naive.c
	$(CC) -o $@ $<

hw1_kmp : kmp.c
	$(CC) -o $@ $<

clean :
	rm -f *.o
	rm -f naive kmp
	rm -f result_naive.txt result_kmp.txt
