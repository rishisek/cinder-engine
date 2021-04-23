//
// Created by rishi on 18-04-2021.
//
#include "interface/logger.h"

namespace interface {
void Logger::Log(std::string message) {
  Log("s", message.c_str());
}

void Logger::Log(int message) {
  Log("i", message);
}
}