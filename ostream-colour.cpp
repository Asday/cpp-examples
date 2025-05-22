#if 0
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
    && ./exe $@
RET=$?
rm -f exe
exit $RET
#endif

#include <iostream>
#include <string_view>

static constexpr std::string_view fg_red{"\033[0;31m"};
static constexpr std::string_view reset{"\033[0m"};

int main() {
    std::cout << "asdf" << fg_red << "butts" << reset << std::endl;
}
