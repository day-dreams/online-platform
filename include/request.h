#pragma once

#include "macros.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::map;

namespace moon {

class request {
private:
  httpMethods method;
  string url;
  string http_version;
  map<string, string> headers;

public:
  /*
    constructors
  */
  request();
  request(const char *text, int size);

  /*
    member functions for attributes
  */
  const httpMethods &getMethod();
  const string &getUrl();
  const string &getVersion();

  /*
    print atributes to stream
  */
  void show(std::ostream &out);
};
}
