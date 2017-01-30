#include "../include/base_functions.h"
#include "../include/exceptions.h"
#include <arpa/inet.h>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>

const int buffer_size = 1024 * 8;
static char buffer[buffer_size];

int moon::create_tcp_socket(int domain, int type, int protocol) {
  return socket(domain, type, protocol);
}

void moon::bind_tcp_socket(int sockfd, std::string ip_addr, short port) {
  sockaddr_in sock_addr;
  sock_addr.sin_addr.s_addr = inet_addr(ip_addr.c_str());
  sock_addr.sin_port = htons(port);
  sock_addr.sin_family = AF_INET;
  if (bind(sockfd, (sockaddr *)&sock_addr, sizeof(sock_addr)) != 0)
    throw bind_error();
}

void moon::set_socket_port_reuseable(int sockfd) {
  int on = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, (void *)&on, sizeof(on)) ==
      -1)
    throw opt_error();
}

void moon::set_socket_ready(int sockfd, int max_wait) {
  if (listen(sockfd, max_wait) == -1)
    throw listen_error();
}

void moon::build_connection(int sockfd, std::string ip_addr, short port) {
  sockaddr_in remote_addr;
  remote_addr.sin_addr.s_addr = inet_addr(ip_addr.c_str());
  remote_addr.sin_port = htons(port);
  remote_addr.sin_family = AF_INET;
  if (connect(sockfd, (sockaddr *)&remote_addr, sizeof(sockaddr)) == -1)
    throw connect_error();
}

size_t moon::send_data(int sockfd, std::string data) {
  auto size = send(sockfd, data.c_str(), data.length(), 0);
  if (size == -1)
    throw send_error();
  else
    return size;
}

std::string moon::recv_data(int sockfd) {
  std::memset(buffer, '\0', buffer_size);
  auto size = recv(sockfd, buffer, 1000, 0);
  if (size == -1)
    throw recv_error();
  else
    return std::string(buffer);
}
