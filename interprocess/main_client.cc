#include <iostream>
#include <vector>
#include "protocol.h"
#include <chrono>
#include <atomic>
using namespace boost::asio;

std::atomic_int count{0};

int main(int argc, char** argv) {
  if (argc <= 1) {
    std::cout << "please set ports" << std::endl;;
    return 1;
  }
  int port = std::atoi(argv[1]);
  ip::udp::endpoint ep1(ip::address::from_string("127.0.0.1"), 3474);

  using namespace protocol;  // NOLINT
  ProtocolConfig proto_config;
  proto_config.protocol_type_ = PROTOCOL_TYPE::UDP_SERVER;
  proto_config.udp_server_ip_ = "0.0.0.0";
  proto_config.udp_server_port_ = port;
  auto protocol = protocol::GetProtocolByConfig(proto_config, 1000);
  protocol->SetDataRecvCallback([&](uint8_t* str, size_t size) -> void {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::string data = "done " + std::to_string(count);
        count++;
        protocol->ProtocolSendRawDataToRemote((uint8_t*)data.data(), data.size(), ep1);
  });


  while (count < 10) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
}