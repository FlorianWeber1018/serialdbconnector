#include <iostream>


void ArduIoInterface::SerialDispatcher(std::string cmd)
{
  std::cout << "ArduIoInterface::SerialDispatcher" << std::endl;
}
void ArduIoInterface::connectBoth()
{
  std::cout << "ArduIoInterface::connectBoth" << std::endl;
}
ArduIoInterface::ArduIoInterface(std::string device, int baudrate, std::string host, unsigned int port, std::string user, std::string pw, std::string db)
{
  std::cout << "ArduIoInterface::ArduIoInterface" << std::endl;
}