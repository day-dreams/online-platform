#include "../include/base_functions.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
int moon::create_tcp_socket(int domain, int type, int protocol) {
  return socket(domain, type, protocol);
}

int moon::bind_tcp_socket(int sockfd, std::string ip_addr, short port) {
  sockaddr_in sock_addr;
  sock_addr.sin_addr.s_addr = inet_addr(ip_addr.c_str());
  sock_addr.sin_port = htons(port);
  return bind(sockfd, (sockaddr *)&sock_addr, sizeof(sock_addr));
}

void moon::set_socket_port_reuseable(int sockfd) {
  int on = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, (void *)&on, sizeof(on));
}

void moon::set_socket_ready(int sockfd, int max_wait) {
  listen(sockfd, max_wait);
}

int moon::build_connection(int sockfd, std::string ip_addr, short port) {
  sockaddr_in remote_addr;
  remote_addr.sin_addr.s_addr = inet_addr(ip_addr.c_str());
  remote_addr.sin_port = htons(port);
  return connect(sockfd, (sockaddr *)&remote_addr, sizeof(sockaddr));
}

size_t moon::send_data(int sockfd, std::string data) {
  return send(sockfd, data.c_str(), data.length(), 0);
}

std::string moon::recv_data(int sockfd) {
  static char buffer[1000];
  recv(sockfd, buffer, 1000, 0);
  return std::string(buffer);
}
