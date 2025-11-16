#pragma once
#include <iostream>
#include <string>
enum class LogLevel { INFO, WARNING, ERROR, NONE };

inline LogLevel CURRENT_LOG_LEVEL = LogLevel::INFO;

inline void log(LogLevel level, const std::string& msg) {
    const char* prefix = "";
    switch (level) {
        case LogLevel::INFO: prefix = "[INFO] "; break;
        case LogLevel::WARNING: prefix = "[WARN] "; break;
        case LogLevel::ERROR: prefix = "[ERROR] "; break;
    }

    if (level >= CURRENT_LOG_LEVEL) {
        std::cout << prefix << msg << std::endl;
    }
}
