#include <iostream>
#include "link/link.pb.h"

int main()
{
    mp::pb::link::DownlinkMessage msg;
    std::cout << msg.telemetry().sensors().has_accelerometer() << std::endl;
    return 0;
}