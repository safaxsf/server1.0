CC=gcc
tcp_net_socket.so:tcp_net_socket.c
	$(CC) -fPIC -shared $^ -o $@
.PHONY:clean
clean:
	rm *.so 
