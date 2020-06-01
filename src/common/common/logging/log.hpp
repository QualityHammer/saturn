#pragma once

#include <fmt/format.h>

#include "common/types.hpp"

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
  FreeType,
  Count
};

static bool verbose {false};

void initLogger(const bool v);
void shutdownLogger();

void _logMessage(Class logClass, Level logLevel, const char* filename, u32 lineNum,
  const char* func, const String msg);

template<typename... Args>
void logMessage(Class logClass, Level logLevel, const char* filename, u32 lineNum, const char* func, const Args&... args) {
  _logMessage(logClass, logLevel, filename, lineNum, func, fmt::format(args...));
}

}// namespace Log

#ifdef DEBUG
#define LOG_TRACE(logClass, ...) \
  ::Log::logMessage(::Log::Class::logClass, ::Log::Level::Trace, __FILE__, __LINE__, __func__, __VA_ARGS__)
#define LOG_DEBUG(logClass, ...) \
  ::Log::logMessage(::Log::Class::logClass, ::Log::Level::Debug, __FILE__, __LINE__, __func__, __VA_ARGS__)
#else
#define LOG_TRACE(logClass, ...) (void(0))
#define LOG_DEBUG(logClass, ...) (void(0))
#endif

#define LOG_INFO(logClass, ...) \
  ::Log::logMessage(::Log::Class::logClass, ::Log::Level::Info, __FILE__, __LINE__, __func__, __VA_ARGS__)

#define LOG_WARN(logClass, ...) \
  ::Log::logMessage(::Log::Class::logClass, ::Log::Level::Warn, __FILE__, __LINE__, __func__, __VA_ARGS__)

#define LOG_ERROR(logClass, ...) \
  ::Log::logMessage(::Log::Class::logClass, ::Log::Level::Error, __FILE__, __LINE__, __func__, __VA_ARGS__)

#define LOG_CRITICAL(logClass, ...) \
  ::Log::logMessage(::Log::Class::logClass, ::Log::Level::Critical, __FILE__, __LINE__, __func__, __VA_ARGS__)

