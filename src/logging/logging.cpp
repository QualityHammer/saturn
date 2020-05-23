#include "logging.hpp"
#include <spdlog/spdlog.h>

namespace Logging {

void logErr(const char* msg) {
  spdlog::info("Error: {}", msg);
}

}// namespace Logging

