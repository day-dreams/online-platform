#include "../include/base_functions.h"
#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv) {
  auto sock = moon::create_tcp_socket();
  if (argc > 2)
    moon::build_connection(sock, argv[1]);
  else
    moon::build_connection(sock, "127.0.0.1");
  while (true) {
    cout << "input > ";
    string tem;
    std::getline(std::cin, tem);
    if (tem == "exit") {
      cout << "??";
      close(sock);
      break;
    }
    moon::send_data(sock, tem);
    auto echo_data = moon::recv_data(sock);
    cout << "from-server > " << echo_data << endl;
    if (echo_data == "see you next time") {
      cout << "the server ended the connection.\n";
      close(sock);
      break;
    }
  }
  return 0;
}
