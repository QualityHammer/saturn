#include <iostream>

#include <spdlog/async.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include "log.hpp"

namespace Log {

namespace {

  std::shared_ptr<spdlog::logger> fileLogger;

}// namespace

void _logMessage(Class logClass, Level logLevel, const char* filename, u32 lineNum,
  const char* func, const std::string msg) {
  switch (logLevel) {
  case Level::Trace:
    fileLogger->trace(msg);
    break;
  case Level::Debug:
    fileLogger->debug(msg);
    break;
  case Level::Info:
    fileLogger->info(msg);
    break;
  case Level::Warn:
    fileLogger->warn(msg);
    break;
  case Level::Error:
    fileLogger->error(msg);
    break;
  case Level::Critical:
    fileLogger->critical(msg);
    break;
  default:
    break;
  };
}

void initLogger() {
  try {
    fileLogger = spdlog::rotating_logger_mt<spdlog::async_factory>("saturn", "logs/log.txt", 1048576 * 5, 3);
  } catch (const spdlog::spdlog_ex& ex) {
    std::cout << "Log initialization failed: " << ex.what() << '\n';
  }
}

void shutdownLogger() {
  spdlog::shutdown();
  fileLogger = nullptr;
}

}// namespace Log

