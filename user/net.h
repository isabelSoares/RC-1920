#ifndef __SERVER_H__
#define __SERVER_H__

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <strings.h>

typedef struct serverOptions {
  char ip[16];
  char port[6];
} ServerOptions;

typedef struct udpConn {
  int fd;
  struct addrinfo hints, *res;
} UDPConn;

ServerOptions getOptions (int argc, char** argv);

UDPConn *connectUDP (ServerOptions opts);

void closeUDP (UDPConn* conn);

char* sendUDP (UDPConn *conn, char* msg);

#endif