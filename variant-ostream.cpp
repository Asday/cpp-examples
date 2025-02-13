#if 0 /*
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
    && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <iostream>
#include <string>
#include <variant>

struct A {
    friend std::ostream& operator<<(
        std::ostream& os,
        [[maybe_unused]] const A& a
    ) {
        os << "I am A"; return os;
    }
};

struct B {
    friend std::ostream& operator<<(
        std::ostream& os,
        [[maybe_unused]] const B& a
    ) {
        os << "I am B"; return os;
    }
};

template <typename T, typename... Ts>
std::ostream& operator<<(
    std::ostream& os,
    const std::variant<T, Ts...>& e
) {
    std::visit([&os](auto& v){ os << v; }, e);

    return os;
}

int main() {
    const std::variant<A, B> a{A()};
    std::cout << std::get<A>(a) << std::endl;
    const std::variant<A, B> b{B()};

    std::cout << a << '\n' << b << std::endl;
}
