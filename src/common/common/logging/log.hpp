#pragma once

#include <fmt/format.h>
#include "../types.hpp"

namespace Log {

enum class Level : u8 {
  Trace,
  Debug,
  Info,
  Warn,
  Error,
  Critical,
  Count
};

enum class Class : u8 {
  Log,
  GLFW,
  Count
};

static bool verbose {false};

void initLogger(const bool v);
void shutdownLogger();

void _logMessage(Class logClass, Level logLevel, const char* filename, u32 lineNum,
  const char* func, const std::string msg);

template<typename... Args>
void logMessage(Class logClass, Level logLevel, const char* filename, u32 lineNum, const char* func, const Args&... args) {
  _logMessage(logClass, logLevel, filename, lineNum, func, fmt::format(args...));
}

}// namespace Log

#define LOG_INFO(logClass, ...) \
  ::Log::logMessage(::Log::Class::logClass, ::Log::Level::Info, __FILE__, __LINE__, __func__, __VA_ARGS__)

#define LOG_WARN(logClass, ...) \
  ::Log::logMessage(::Log::Class::logClass, ::Log::Level::Warn, __FILE__, __LINE__, __func__, __VA_ARGS__)

#define LOG_ERROR(logClass, ...) \
  ::Log::logMessage(::Log::Class::logClass, ::Log::Level::Error, __FILE__, __LINE__, __func__, __VA_ARGS__)

#define LOG_CRITICAL(logClass, ...) \
  ::Log::logMessage(::Log::Class::logClass, ::Log::Level::Critical, __FILE__, __LINE__, __func__, __VA_ARGS__)

