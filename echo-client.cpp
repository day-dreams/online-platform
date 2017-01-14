#include "include/base_functions.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: echo-client [server-ip]\n";
  }
  auto sock = moon::create_tcp_socket();
  cout << moon::build_connection(sock, argv[1]) << endl;
  while (true) {
    cout << "input > ";
    string tem;
    std::getline(std::cin, tem);
    if (tem == "exit") {
      cout << "??";
      close(sock);
      return 0;
    }
    moon::send_data(sock, tem);
    auto echo_data = moon::recv_data(sock);
    cout << "from-server > " << echo_data << endl;
  }
  return 0;
}
