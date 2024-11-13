#include "logger.h"
#include <fstream>
#include <chrono>
#include <iomanip>

Logger::Logger(const std::string& logFileName) : logFile(logFileName) {
    std::ofstream logStream(logFile, std::ios::app);
    if (!logStream) {
        throw std::runtime_error("Failed to open log file");
    }
}

void Logger::log(const std::string& message) {
    std::ofstream logStream(logFile, std::ios::app);
    if (!logStream) return;

    auto now = std::chrono::system_clock::now();
    auto nowTime = std::chrono::system_clock::to_time_t(now);
    logStream << "[" << std::put_time(std::localtime(&nowTime), "%Y-%m-%d %H:%M:%S") << "] " << message << std::endl;
}