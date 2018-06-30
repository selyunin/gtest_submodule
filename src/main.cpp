#include <iostream>
#include "project1.h"
#include "message.h"
#include <array>

using namespace std;

void readmsg(Message<std::array<uint8_t, 16>::iterator,
                     std::array<uint8_t, 16>::iterator > & msg)
{
    std::array<uint8_t, 16> buffer;
    auto iter = buffer.begin();
    ErrorStatus ex = msg.read(iter, buffer.size());
    if(ex != ErrorStatus::Success){
        cout<<"read failed"<<endl;
    }
}

int main() {

    HelloMessage<std::array<uint8_t, 16>::iterator,
                 std::array<uint8_t, 16>::iterator> msg1;
    StatusMessage<std::array<uint8_t, 16>::iterator,
                  std::array<uint8_t, 16>::iterator> msg2;
    readmsg(msg1);
    readmsg(msg2);

    return 0;
}