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
#include <sstream>
#include <string_view>

#define _BASE "asdf"
static constexpr std::string_view BASE{_BASE};
static constexpr std::string_view CONCATTED{_BASE "butts"};
#undef _BASE

int main() {
  std::clog << CONCATTED << std::endl;
}
