#include "tcp_net_socket.h"
void client_start(int argc,char** argv){
	int sfd;
	int buf[512] = {0};
	char msg[32]={"hello I am client"};
	if(argc < 3){
		printf("param error");
	}
	sfd = tcp_connect(argv[1],atoi(argv[2]));
	while(1){
		scanf("%s",msg);
		send(sfd,msg,strlen(msg),0);
		recv(sfd,buf,sizeof(buf),0);
		puts((const char*)buf);
	}
	close(sfd);
}
int main(int argc,char **argv){
	client_start(argc,argv);
	return 0;
}
