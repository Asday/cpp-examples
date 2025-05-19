#if 0 /*
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
  && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <iostream>
#include <thread>

using namespace std::chrono_literals;

int main() {
  // I mean it works but it's kinda gross.  Just put the sleep in the
  // loop body.
  while (std::this_thread::sleep_for(5s), true) {
    std::clog << ".";
  }
}
