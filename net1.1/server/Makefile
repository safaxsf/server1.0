CC=gcc
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/test/net/tcp/
server:server.o ../tcp/libsocket.so
	$(CC) -Wall -g $^ -o $@ -L../tcp -I ../tcp 

server.o:server.c 
	$(CC) -Wall -g $^ -c -I ../tcp
.PHONY:clean
clean:
	rm *.o server
