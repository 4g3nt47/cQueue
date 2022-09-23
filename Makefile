bin/cQueue.o: src/cQueue.c src/cQueue.h
	gcc -Os -s -c src/cQueue.c -o bin/cQueue.o

clean:
	rm bin/*
