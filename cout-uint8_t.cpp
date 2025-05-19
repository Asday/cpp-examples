#if 0 /*
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
  && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <iostream>

int main() {
  uint8_t a{64};
  std::cout << +a << std::endl;
}
