#include <iostream>
#include "link/link.pb.h"

int main()
{
    pb::mp::link::DownlinkMessage msg;
    std::cout << msg.telemetry().sensors().has_accelerometer() << std::endl;
    return 0;
}