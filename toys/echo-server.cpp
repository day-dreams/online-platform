#include "../include/base_functions.h"
#include <glog/logging.h>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv) {
  // initailize glog and set log directory to current directory.
  google::InitGoogleLogging(argv[0]);
  FLAGS_log_dir = ".";
  auto socket = moon::create_tcp_socket();
  moon::set_socket_port_reuseable(socket);
  moon::bind_tcp_socket(socket);
  moon::set_socket_ready(socket);
  LOG(ERROR) << "server_socket set up already.";
  // cout << "server_socket set up already.";
  while (true) {
    sockaddr client_addr;
    int tem_len = sizeof(sockaddr);
    auto client =
        accept(socket, (sockaddr *)&client_addr, (socklen_t *)&tem_len);
    LOG(ERROR) << "an client reached.\n";
    auto pid = fork();
    if (pid == -1) {
      std::cout << "error during fork()!" << '\n';
      return -1;
    } else if (pid == 0) {
      close(socket);
      while (true) {
        auto data = moon::recv_data(client);
        if (data == "goodbye") {
          moon::send_data(client, "see you next time");
          close(client);
          break;
        } else
          moon::send_data(client, data + " [again]\n");
      }
      return 0;
    } else {
      close(client);
    }
  }
  cout << socket << endl;
  return 0;
}
