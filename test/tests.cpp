#include "../include/request.h"
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  char *content = "GET / HTTP/1.0";
  moon::request req(content, strlen(content));
  cout << "method:" << req.getMethod() << '\n'
       << "url:" << req.getUrl() << '\n'
       << "version: " << req.getVersion() << '\n';
  return 0;
}
