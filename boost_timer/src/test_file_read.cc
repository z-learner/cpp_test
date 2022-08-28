#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
class FileReadMs {
public:
  explicit FileReadMs(std::string file_name, std::ios_base::openmode mode, double cycle_ms);
  virtual ~FileReadMs() {
    in_.close();
  }
  bool read(char* buff, size_t size);
  double get_cycle_ms() {
    return total_.count() / double(count_);
  }

private:
  std::ifstream in_;
  double cycle_ms_;
  std::chrono::steady_clock::time_point start_{};
  std::chrono::steady_clock::time_point end_{};
  std::chrono::milliseconds total_{};
  size_t count_;
};

FileReadMs::FileReadMs(std::string file_name, std::ios_base::openmode mode, double cycle_ms)
:in_(file_name, mode), cycle_ms_(cycle_ms), count_(0) {
}


bool FileReadMs::read(char* buff, size_t size) {
  try
  {
    if (in_.eof()) {
      return false;
    }
    if (!count_) {
      start_ = std::chrono::steady_clock::now();
    }
    end_ = std::chrono::steady_clock::now();
    while (std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_).count() < cycle_ms_) {
      std::this_thread::sleep_for(std::chrono::microseconds(100));
      end_ = std::chrono::steady_clock::now();
    }
    total_ += std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_);
    count_++;
    start_ = std::chrono::steady_clock::now();
    in_.read(buff, size);
    return in_.gcount() == size ? true : false; 
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return false;
  }
  
}


void function(std::string file_name, std::ios_base::openmode mode, double cycle_ms) {
  FileReadMs in(file_name, mode, cycle_ms);
  char buff[2];

  while (in.read(buff, 2))
  {
    // std::cout << std::string(buff) << std::endl;
  }
  std::cout << "cycle : " << in.get_cycle_ms() << " ms" << std::endl;
}


int main() {
  std::string file_name  = "test.txt";
  // std::ios_base::in | std::ios_base::binary
  std::vector<std::thread> threads;
  for (int i = 0; i < 10; ++i) {
    threads.emplace_back(std::move(std::thread(&function, file_name, std::ios_base::in | std::ios_base::binary, (i + 1) * 10)));
  }

  for (auto& thread : threads) {
    thread.join();
  }
}