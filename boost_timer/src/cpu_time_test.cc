#include <boost/timer/timer.hpp>
#include <chrono>
#include <thread>
#include <iostream>
using namespace boost;
using namespace boost::timer;


int main() {
  cpu_timer t;
  while (true) {
    t.start();
    while (t.elapsed().wall < 1e9)  // 1s
    {
      std::cout << t.elapsed().wall / double(1e9) << "s and sleep 100ms" << std::endl;
      std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
    std::cout << "1s" << std::endl;
  }
}