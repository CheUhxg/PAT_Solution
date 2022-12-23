#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cstdlib>

uint32_t layers, calling;
std::mutex mu_call;

[[noreturn]] void passenger() {

}

[[noreturn]] void elevator() {
    std::vector<int> isCall(layers, -1);
    uint32_t pos = 0, high, cnt;

    while(true) {
        assert(calling <= layers);
        if(calling == 0) continue ;

        high = -1;
        mu_call.lock();
        for(int i = layers - 1; i >= 0; --i) {
            if(isCall[i] > 0) {
                high = i;
                break;
            }
        }
        mu_call.unlock();
        if(high == -1) continue;

        cnt = pos > high?pos-high:high-pos;
        pos = high;
    }
}

int main() {
    std::thread p;
}