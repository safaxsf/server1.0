/*************************************************************************
    > File Name: tcp_net_socket.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 26 Oct 2023 08:54:41 PM PDT
 ************************************************************************/

#include "tcp_net_socket.h"

#define PORT 8888

int tcp_init(const char* ip,int port){
	int ret = 0;
	int sfd;
	struct sockaddr_in serveraddr;
	memset(&serveraddr,0,sizeof(struct sockaddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ip);

	sfd = socket(AF_INET,SOCK_STREAM,0);
	PERROR("socket",(COMMON_ERROR == sfd));

	ret = bind(sfd,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr));
	PERROR_C("bind",(COMMON_ERROR == ret),sfd);

	ret = listen(sfd,10);
	PERROR_C("listen",(COMMON_ERROR == ret),sfd);

	return sfd;
}

int tcp_accept(int sfd){
	int addrlen;
	int new_fd;
	struct sockaddr_in clientaddr;
	memset(&clientaddr,0,sizeof(struct sockaddr));
	addrlen = sizeof(struct sockaddr);
	new_fd = accept(sfd,(struct sockaddr*)&clientaddr,&addrlen);
	PERROR_C("accept",(COMMON_ERROR == new_fd),sfd);

	printf("%s success connect! \n",inet_ntoa(clientaddr.sin_addr));
	return new_fd;
}

int tcp_connect(const char* ip,int port){
	int sfd;
	int ret = 0;
	struct sockaddr_in serveraddr;
	sfd = socket(AF_INET,SOCK_STREAM,0);
	PERROR("SOCKET",(COMMON_ERROR == sfd));

	memset(&serveraddr,0,sizeof(struct sockaddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(port);
	serveraddr.sin_addr.s_addr = inet_addr(ip);

	ret = connect(sfd,(struct sockaddr*)&serveraddr,sizeof(struct sockaddr));
	PERROR_C("connect",(COMMON_ERROR == ret),ret);
	return sfd;
}

