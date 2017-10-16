all: node.c
	gcc -o node node.c

clean:
	rm *.~

run: all
	./node
