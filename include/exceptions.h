#include <stdexcept>

namespace moon {
class base_error : public std::runtime_error {
public:
  base_error(const char *argv) : runtime_error(argv) {}
};

class bind_error : public base_error {
public:
  bind_error() : base_error("error in binding!") {}
};

class opt_error : public base_error {
public:
  opt_error() : base_error("error in setting option!") {}
};

class listen_error : public base_error {
public:
  listen_error() : base_error("error in listening!") {}
};

class connect_error : public base_error {
public:
  connect_error() : base_error("error in connecting!") {}
};
}
