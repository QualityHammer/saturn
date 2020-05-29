#include <array>
#include <vector>

#include <spdlog/async.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "log.hpp"

namespace Log {

using LoggerType = std::shared_ptr<spdlog::logger>;

namespace {

  LoggerType fileLogger;
  LoggerType consoleLogger;

  std::vector<LoggerType> loggers {};

  const std::array<std::string, static_cast<u8>(Class::Count)> logClassNames {{"Log",
    "GLFW"}};

  constexpr const char* trimPath(std::string_view srcPath) {
    const auto rfind = [srcPath](const std::string_view match) {
      return srcPath.rfind(match) == match.npos ? 0 : (srcPath.rfind(match) + match.size());
    };
    auto idx = std::max({rfind("src/"), rfind("src\\"), rfind("../"), rfind("..\\")});
    return srcPath.data() + idx;
  }

}// namespace

void _logMessage(Class logClass, Level logLevel, const char* filename, u32 lineNum,
  const char* func, const std::string msg) {
  const std::string logOutputMsg {fmt::format("[{}] |{} - {}:{}| {}",
    logClassNames[static_cast<u8>(logClass)],
    trimPath(filename),
    func,
    lineNum,
    msg)};
  switch (logLevel) {
  case Level::Trace:
    for (auto& logger : loggers)
      logger->trace(logOutputMsg);
    break;
  case Level::Debug:
    for (auto& logger : loggers)
      logger->debug(logOutputMsg);
    break;
  case Level::Info:
    for (auto& logger : loggers)
      logger->info(logOutputMsg);
    break;
  case Level::Warn:
    for (auto& logger : loggers)
      logger->warn(logOutputMsg);
    break;
  case Level::Error:
    for (auto& logger : loggers)
      logger->error(logOutputMsg);
    break;
  case Level::Critical:
    for (auto& logger : loggers)
      logger->critical(logOutputMsg);
    break;
  default:
    break;
  };
}

void initLogger(const bool v) {
  verbose = v;
  try {
    fileLogger = spdlog::rotating_logger_mt<spdlog::async_factory>("saturn", "logs/log.txt", 1048576 * 5, 3);
    loggers.push_back(fileLogger);
    if (verbose) {
      consoleLogger = spdlog::stdout_color_mt<spdlog::async_factory>("saturn-console");
      loggers.push_back(consoleLogger);
    }
  } catch (const spdlog::spdlog_ex& ex) {
    fmt::print("Log initialization failed: {}", ex.what());
  }
}

void shutdownLogger() {
  spdlog::shutdown();
  fileLogger = nullptr;
}

}// namespace Log
