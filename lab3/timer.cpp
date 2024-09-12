#include "timer.h"

#include <iostream>
using namespace std;

Timer::Timer(std::string description): description(description) {}

void Timer::start() {
  begin = clock();
}

void Timer::stop() {
  end = clock();
}

double Timer::getSecondsElapsed() const {
  return static_cast<double>(end - begin) / CLOCKS_PER_SEC;
}

void Timer::printData() const {
  cout << description << ": " << getSecondsElapsed() << " seconds" << endl;
}
