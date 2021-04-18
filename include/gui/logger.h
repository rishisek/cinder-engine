//
// Created by rishi on 18-04-2021.
//
#pragma once

#include <fstream>
#include <sstream>

namespace gui {
class Logger {
 public:
  static void Log(std::string message);
  static void Log(int message);

  template<typename ... Args>
  static void Log(const Args &... args);
 private:
};

// Referenced from StackOverflow: https://bit.ly/2OYPtZr
template<typename ... Args>
void Logger::Log(Args const &... args) {
  std::ofstream log_stream(
      "E:\\Coursework\\Spring 2020\\CS 126\\Cinder\\my-projects\\final-project-rishisek-illinois\\log\\log1.txt",
      std::ios::app);
  std::ostringstream stream;
  using List = int[];
  (void) List{0, ((void) (stream << args), 0)...};
  log_stream << stream.str() << std::endl;
  log_stream.close();
}
}