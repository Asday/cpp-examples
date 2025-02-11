#if 0 /*
g++ -std=c++23 $0 -o exe \
  -Wall -Werror -Wextra -Wsign-conversion -pedantic-errors \
  && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <cstdint>
#include <iostream>
#include <utility>

enum class A : uint8_t {
  a = 1,
  b = 2,
  LAST = b,
};

int f(const A& a) {
  switch (a) {
    case A::a: return 9;
    case A::b: return 10;
  }

  throw std::runtime_error("error: stop using `static_cast()`");
}

int main() {
  std::cout << f(A::a) << std::endl;
  std::cout << f(A::b) << std::endl;
  std::cout << f(A::LAST) << std::endl;

  f(static_cast<A>(255));
}
