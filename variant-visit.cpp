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

struct ABVisitor {
  void operator()([[maybe_unused]] const A& a) const noexcept {
    std::cout << "a" << std::endl;
  }

  void operator()([[maybe_unused]] const B& a) const noexcept{
    std::cout << "b" << std::endl;
  }
};

static constexpr ABVisitor abVisitor{};

int main() {
  const std::variant<A, B> a{A()};
  std::visit(abVisitor, a);
}
