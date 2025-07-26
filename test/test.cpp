#include <iostream>
#include "mpsim/bridge.pb.h"

int main()
{
    pb::mpsim::Response response;
    const auto& msg = response.read_state().state();
    std::cout << msg.has_acceleration() << std::endl;
    return 0;
}