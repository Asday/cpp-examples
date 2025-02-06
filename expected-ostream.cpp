#if 0
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
    && ./exe $@
rm exe
exit
#endif

#include <expected>
#include <iostream>
#include <string>

struct A {
    friend std::ostream& operator<<(
        std::ostream& os,
        [[maybe_unused]] const A& a
    ) {
        os << "I am A"; return os;
    }
};

template<typename T>
concept Any = true;

std::ostream& operator<<(
    std::ostream& os,
    const std::expected<Any auto, Any auto>& e
) {
    if (e.has_value()) os << e.value();
    else os << e.error();

    return os;
}

int main() {
    const std::expected<A, std::string> a{A()};
    const std::expected<A, std::string> b{std::unexpected("I am not A")};

    std::cout << a << '\n' << b << std::endl;
}
