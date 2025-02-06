#if 0
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
    && ./exe $@
RET=$?
rm -f exe
exit $RET
#endif

#include <iostream>

struct A {
    uint8_t i;
    static constexpr size_t iOffset{0};
    uint8_t x;
    static constexpr size_t xOffset{iOffset + sizeof(x)};

    static void a() {
        std::cout << sizeof(i) << std::endl;
    }
};

int main() { A::a(); }
