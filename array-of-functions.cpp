#if 0 /*
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
  && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <array>
#include <cstdint>
#include <iostream>

void f() { std::cout << 194 << std::endl; }

int main() {
  std::array<decltype(&f), 2> a{{f, f}};

  a[0]();
}
