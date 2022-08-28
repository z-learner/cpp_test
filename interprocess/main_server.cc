#include <iostream>
#include <vector>
#include "protocol.h"
#include <chrono>
using namespace boost::asio;


int main(int argc, char** argv) {


  // tow client 10001 10002
  ip::udp::endpoint ep1(ip::address::from_string("127.0.0.1"), 10001);
  ip::udp::endpoint ep2(ip::address::from_string("127.0.0.1"), 10002);
  ip::udp::endpoint ep3(ip::address::from_string("127.0.0.1"), 10003);

  using namespace protocol;  // NOLINT
  ProtocolConfig proto_config;
  proto_config.protocol_type_ = PROTOCOL_TYPE::UDP_SERVER;
  proto_config.udp_server_ip_ = "0.0.0.0";
  proto_config.udp_server_port_ = 3474;
  auto protocol = protocol::GetProtocolByConfig(proto_config, 1000);
  protocol->SetDataRecvCallback([](uint8_t* str, size_t size) -> void {
        std::string data((char*)str, size);
        std::cout << "get data: " << data << std::endl;
  });
  uint8_t* data = new uint8_t[1];
  while (true) {
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    while (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() < 1000)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
      end = std::chrono::steady_clock::now();
    }
    protocol->ProtocolSendRawDataToRemote(data, 1, ep1);
    protocol->ProtocolSendRawDataToRemote(data, 1, ep2);
    protocol->ProtocolSendRawDataToRemote(data, 1, ep3);
  }

  delete[] data;

}