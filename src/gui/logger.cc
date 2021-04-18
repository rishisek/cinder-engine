//
// Created by rishi on 18-04-2021.
//
#include "gui/logger.h"

namespace gui {
void Logger::Log(std::string message) {
  Log("s", message.c_str());
}

void Logger::Log(int message) {
  Log("i", message);
}
}