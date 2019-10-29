#ifndef H_EXTREMITE
#define H_EXTREMITE

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define SIZE_BUFFER 1024

void ext_out(char* ip_addr);
void ext_int(char* addr, int port,int tun_fd);

#endif