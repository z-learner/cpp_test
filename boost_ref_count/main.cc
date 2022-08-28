#include "ref_count.hpp"
#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <chrono>
class demo : public ref_count<demo>
{

public:
  demo() = default;
  ~demo() = default;
  int x;
};


template<class T> 
void function(T ptr, std::string trhead_name = "") {
  std::cout << trhead_name << " : " << ptr->count() << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
}



int main() {
  auto p = demo::make_ptr();

  p->x = 1;

  assert(p->x == 1);
  assert(p->count() == 1);

  auto p1 = p;

  std::vector<std::thread> threads;

  for (int i = 0; i < 1000; ++i) {
    threads.push_back(std::move(
      std::thread(
        function<decltype(p)>, p, std::to_string(i)
      )
    ));
  }

  for (auto& thread : threads) {
    thread.join();
  }

}