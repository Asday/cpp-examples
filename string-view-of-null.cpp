#if 0 /*
g++ -std=c++23 $0 -o exe \
  -Wall -Werror -Wextra -Wsign-conversion -pedantic-errors \
  && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <cstdlib>
#include <iostream>
#include <string_view>

int main() {
  char* v{getenv("BUTTS")};
  // std::string_view sv{v};  // This will segfault if `BUTTS` is unset.
  std::string_view sv{""};
  if (v != NULL) sv = v;

  std::clog << "asdf" << sv << "butts" << std::endl;
}
