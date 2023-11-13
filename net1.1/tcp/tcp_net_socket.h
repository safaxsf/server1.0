/*************************************************************************
    > File Name: tcp_net_socket.h
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 26 Oct 2023 08:43:16 PM PDT
 ************************************************************************/
#ifndef __TCP_NET_SOCKET_H__
#define __TCP_NET_SOCKET_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define COMMON_ERROR -1
#define PERROR(err,ret) \
	do{\
		perror(err);\
		if(ret){\
			exit(EXIT_FAILURE);\
		}\
	}while(0)
#define PERROR_C(err,ret,sfd)\
	do{\
		perror(err);\
		if(ret){\
			close(sfd);\
			exit(EXIT_FAILURE);\
		}\
	}while(0)
#define PERROR_CC(err,ret,sfd,cfd)\
	do{\
		perror(err);\
		if(ret){\
			close(sfd);\
			close(cfd);\
			exit(EXIT_FAILURE);\
		}\
	}while(0)
extern int tcp_init(const char *ip , int port);

extern int tcp_accept(int sfd);

extern int tcp_connect(const char* ip,int port);
#endif

