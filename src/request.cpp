#include "../include/request.h"
#include <algorithm>
#include <cstring>

using std::find;

moon::request::request() {}

moon::request::request(const char *text, int size) {
  auto first_blank = find(text, text + size, ' ');
  auto second_blank = find(first_blank + 1, text + size, ' ');
  auto method = string(text, first_blank);
  if (method == "GET")
    this->method = httpMethods::GET;
  else if (method == "POST")
    this->method = httpMethods::POST;
  else
    this->method = httpMethods::UNKNOWN;
  this->url = string(first_blank + 1, second_blank);
  this->http_version = string(second_blank + 1, text + size);
  char *ite_line = std::strstr(text, "\n");
  char *ite_newline = nullptr;
  while (ite_newline = strstr(ite_line, "\n")) {
    if (ite_newline == ite_line)
      break;
    auto ite_colon = strstr(ite_line, ";");
    this->headers[string(ite_line, ite_colon)] =
        string(ite_colon + 1, ite_newline);
    ite_line = ite_newline + 1;
  }
}

const moon::httpMethods &moon::request::getMethod() { return this->method; }

const std::string &moon::request::getUrl() { return this->url; }

const std::string &moon::request::getVersion() { return this->http_version; }

void moon::request::show(std::ostream &out) {
  out << "method:" << this->getMethod() << '\n'
      << "url:" << this->getUrl() << '\n'
      << "version: " << this->getVersion() << '\n';
  for (auto &entry : this->headers) {
    out << entry.first << ":" << entry.second << '\n';
  }
}
