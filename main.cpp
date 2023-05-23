#include "third-party/include/serial/serial.h"
#include <iostream>
#include "thread"
int main()
{
    serial::Serial my_serial("/dev/ttyACM0", 19200, serial::Timeout::simpleTimeout(3000));

    if (my_serial.isOpen())
    {
        std::cout << "Port opened succesfully" << std::endl;
    }
    else
    {
        std::cout << "Port failed to open" << std::endl;
    }
    my_serial.flushOutput();

    std::string test_string = "hi\n";
 


    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    my_serial.flushInput();
    std::string response = my_serial.read(6);
    std::cout << "Arduino said: " << response << std::endl;
}