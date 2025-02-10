#if 0
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
    && ./exe $@
RET=$?
rm -f exe
exit $RET
#endif

#include <array>
#include <concepts>
#include <iostream>
#include <ranges>

template<size_t N>
void f(std::ranges::sized_range auto&& r) {
  static_assert(r.size() == N, "invalid size");
  std::cout << r.size() << std::endl;
}

int main() {
    f<2>(std::array<uint8_t, 2>{2, 3});
    // f<2>(std::array<uint8_t, 3>{5, 7, 11});
}
