#include "tcp_net_socket.h"
k

void server_start(int argc,const char** argv){
	int sfd ;
	int ret = 0;
	int fd[1000] = {0};
	int MacFd,i=0,j;
	fd_set ReadFd,tmpfd;
	char buf[64] = {0};
	struct timeval timeout={5,0};
	if(argc < 3){
		printf("param error");
	}
	sfd =  tcp_init(argv[1],atoi(argv[2]));
	FD_ZERO(&ReadFd);
	DS_SET(sfd,&ReadFd);
	Maxfd = sfd;
	while(1){
		tmpfd=ReadFd;
		ret = select(MaxFd+1,&tmpfd,NULL,NULL,NULL);
		PREEOR("select",(COMMON == ret));
		if(FD_ISSET(sfd,&tmpfd)){
			for(j=0;j<i;j++){
				if(0==fd[j]) break;
			}

			fd[j] = tcp_accept(sfd);
			PERROR("tcp_accept",(COMMON_ERROR == ret));
			if(Maxfd < fd[j]) Maxfd = fd[j];
			FD_SET(fd[j],&ReadFd);
			ret = setsockopt
		}



		int cfd = tcp_accept(sfd);
		char buf[512] = {0};
		char msg[32]={"hello I am server."};

		ret = recv(cfd,buf,sizeof(buf),0);
		PERROR_CC("rev",(COMMON_ERROR == ret),sfd,cfd);
		puts(buf);

		ret = send(cfd,msg,strlen(msg),0);
		PERROR_CC("send",(COMMON_ERROR == ret),sfd,cfd);
		close(cfd);
	}
	close(sfd);
}

int main(int argc,const char* argv[]){
	server_start(argc,argv);
	return 0;
}


