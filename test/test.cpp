#include <iostream>
#include "link/link.pb.h"

int main()
{
    mp::pb::link::DownlinkMessage msg;
    std::cout << msg.telemetry().telemetry().channels_size();
    return 0;
}