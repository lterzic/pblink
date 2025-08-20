#include <iostream>
#include "mp/link.pb.h"

int main()
{
    pb::mp::DownlinkMessage msg;
    std::cout << msg.telemetry().sensors().has_accelerometer() << std::endl;
    return 0;
}