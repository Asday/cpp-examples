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
#include <vector>


int main() {
  std::array<std::uint8_t, 4> plain{{0, 1, 2, 3}};
  std::array<std::vector<std::uint8_t>, 4> vectorsWithItems{
    {{4}, {5, 6}, {7}, {8}}
  };
  std::array<std::vector<std::uint8_t>, 4> emptyVectors{{{}, {}, {}, {}}};

  std::clog
    << +plain[1]
    << '\n'
    << +vectorsWithItems[1][1]
    << '\n'
    << emptyVectors[0].size()
    << std::endl;
  ;
}
