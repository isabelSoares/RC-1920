#ifndef __SERVER_H__
#define __SERVER_H__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <strings.h>
#include <sys/stat.h>
 #include <string.h>

typedef struct serverOptions {
  char ip[16];
  char port[6];
} ServerOptions;

typedef struct udpConn {
  int fd;
  struct addrinfo hints, *res;
} UDPConn;

typedef struct tcpConn {
  int fd;
  struct addrinfo hints, *res;
} TCPConn;

ServerOptions getOptions (int argc, char** argv);

UDPConn *connectUDP (ServerOptions opts);

UDPConn *listenUDP (ServerOptions opts);

TCPConn *listenTCP (ServerOptions opts);

void closeUDP (UDPConn* conn);

int sendUDP (UDPConn *conn, const char* msg, struct sockaddr_in addr);

char* sendWithReplyUDP (UDPConn *conn, char* msg);

char* receiveUDP (UDPConn *conn, struct sockaddr_in* addr, socklen_t* addrlen);

TCPConn *connectTCP (ServerOptions opts);

void closeTCP (TCPConn* conn);

char* readWordTCP (int socket);

int readTCP (int socket, char* buffer, int chars);

int readSpaceTCP (int socket);

int writeTCP(int socket, const char* buffer, int size);

int sendFile (int connFd, char *file, int extension, int sendSize);

int readTextAndImage (int socket, const char *basename, int isServer);

long int readPositiveNumber (int socket);

#endif
