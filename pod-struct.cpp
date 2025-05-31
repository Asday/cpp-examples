#if 0 /*
g++ -std=c++23 $0 -o exe \
  -Wall -Werror -Wextra -Wsign-conversion -pedantic-errors \
  && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <iostream>
#include <cstdint>

struct S { std::uint8_t x; };

std::ostream& operator<<(std::ostream& os, const S& s) {
  os << +s.x;

  return os;
}

S f() { return { .x{5} }; }

struct N { S s; };

N g() { return { .s{static_cast<int>(5)} }; }

std::ostream& operator<<(std::ostream& os, const N& n) {
  os << "N(" << n.s << ")";

  return os;
}

int main() {
  auto s{f()};
  std::clog << s << std::endl;

  auto n{g()};
  std::clog << n << std::endl;
}
