#pragma once
#include "macros.h"
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
namespace moon {
/*
  create a specific tcp socket
*/
int create_tcp_socket(int domain = AF_INET, int type = SOCK_STREAM,
                      int protocol = 0);

/*
  bind the tcp socket to an interface
*/
void bind_tcp_socket(int sockfd, std::string ip_addr = std::string("0.0.0.0"),
                     short port = TCP_SERVER_PORT);

/*
  set the server socket's stening port reuseable
*/
void set_socket_port_reuseable(int sockfd);

/*
  set the server socket ready to accept connections
*/
void set_socket_ready(int sockfd, int max_wait = 5);

/*
  build connection betwwen the peers
*/
void build_connection(int sockfd, std::string ip_addr,
                      short port = TCP_SERVER_PORT);

/*
  send data to remote socket
*/
size_t send_data(int sockfd, std::string data);

/*
  recv data from remote socket
*/
std::string recv_data(int sockfd);
};
