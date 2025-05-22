#if 0 /*
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
  && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <iostream>
#include <variant>

struct A {};
struct B {};

template <typename... Ts>
struct Visitor: Ts... { using Ts::operator()...; };

int main() {
  const std::variant<A, B> a{A()};
  std::visit(Visitor{
    []([[maybe_unused]] const A& a) { std::cout << "a" << std::endl; },
    []([[maybe_unused]] const B& a) { std::cout << "b" << std::endl; }
  }, a);
}
