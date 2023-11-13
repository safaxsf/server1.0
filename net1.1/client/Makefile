CC=gcc
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/test/net1.1/tcp/
client:client.o ../tcp/libsocket.so
	$(CC) -Wall -g $^ -o $@ -L../tcp -I ../tcp 

client.o:client.c 
	$(CC) -Wall -g $^ -c -I ../tcp
.PHONY:clean
clean:
	rm *.o client
