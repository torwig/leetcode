#include <iostream>
#include <cassert>
#include <bitset>


int hammingWeightV1(uint32_t n) {
    int ones_counter = 0;
    while (n != 0) {
        if (n % 2 == 1) ++ones_counter;
        n = n / 2;
    }
    return ones_counter;
}

int hammingWeightV2(uint32_t n) {
    int ones_counter = 0;
    while (n != 0) {
        ++ones_counter;
        n &= n -1;
    }
    return ones_counter;
}

int hammingWeightV3(uint32_t n) {
    return std::bitset<32>(n).count();
}

int main() {
    assert(hammingWeightV2(11) == 3);
    assert(hammingWeightV2(0) == 0);
    assert(hammingWeightV2(1) == 1);
    assert(hammingWeightV2(0b000110110101) == 6);
    return 0;
}
