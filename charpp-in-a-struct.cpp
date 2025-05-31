#if 0 /*
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
  && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <array>
#include <iostream>

int main() {
  typedef struct { char **a; } s;

  [[maybe_unused]] s var{
    .a{std::array<char*, 1>{NULL}.data()}
  };
}
