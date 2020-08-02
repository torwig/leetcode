#include <iostream>

uint32_t  reverseBitsV1(uint32_t n) {
    uint32_t result = 0;
    uint32_t power = 31;

    while (n != 0) {
        result += (n & 1) << power;
        n = n >> 1;
        power -= 1;
    }
    return result;
}

uint32_t reverseBitsV2(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
