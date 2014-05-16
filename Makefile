all:library.c
	gcc library.c -o library
clean:
	rm -f library
