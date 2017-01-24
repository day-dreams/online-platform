#pragma once

namespace moon {
enum baseType { TCP, UDP, RAW };
enum httpStatus { OK, ERROR };
enum httpMethods { GET, POST, UNKNOWN };
}

const short TCP_SERVER_PORT = 80;
