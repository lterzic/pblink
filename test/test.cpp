#include <iostream>
#include <pblink/link/link.pb.h>

int main()
{
    pblink::link::Downlink msg;
    std::cout << msg.telemetry().telemetry().channels_size();
    return 0;
}