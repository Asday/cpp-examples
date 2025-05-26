#if 0 /*
g++ -std=c++23 $0 -o exe \
  -Wall -Werror -Wextra -Wsign-conversion -pedantic-errors \
  && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

// Can't be a `std::string_view()` 'cause characters get garbled.
void render(std::function<std::string()> getMsg) {
  std::clog << "start " << getMsg() << " end" << std::endl;
}

int main() {
  const auto f{
    // `.view()` doesn't work due to a lack of convertability.
    [](){ return (std::stringstream() << "asdf" << "butts").str(); }
  };
  const auto g{[](){ return "raw"; }};

  render(f);
  render(g);
}
