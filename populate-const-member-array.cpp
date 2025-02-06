#if 0
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
    && ./exe $@
RET=$?
rm -f exe
exit $RET
#endif

#include <array>
#include <iomanip>
#include <iostream>
#include <ranges>

struct UUID {
  const std::array<const uint8_t, 16> uuid;

  UUID() : uuid(std::array<const uint8_t, 16>{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  }) {}
  UUID(const char* v) : uuid(std::array<const uint8_t, 16>{
    static_cast<uint8_t>(v[0]),
    static_cast<uint8_t>(v[1]),
    static_cast<uint8_t>(v[2]),
    static_cast<uint8_t>(v[3]),
    static_cast<uint8_t>(v[4]),
    static_cast<uint8_t>(v[5]),
    static_cast<uint8_t>(v[6]),
    static_cast<uint8_t>(v[7]),
    static_cast<uint8_t>(v[8]),
    static_cast<uint8_t>(v[9]),
    static_cast<uint8_t>(v[10]),
    static_cast<uint8_t>(v[11]),
    static_cast<uint8_t>(v[12]),
    static_cast<uint8_t>(v[13]),
    static_cast<uint8_t>(v[14]),
    static_cast<uint8_t>(v[15]),
  }) {}
  UUID(std::ranges::input_range auto&& uuid) :
    uuid(std::array<const uint8_t, 16>{
      uuid[0],
      uuid[1],
      uuid[2],
      uuid[3],
      uuid[4],
      uuid[5],
      uuid[6],
      uuid[7],
      uuid[8],
      uuid[9],
      uuid[10],
      uuid[11],
      uuid[12],
      uuid[13],
      uuid[14],
      uuid[15],
    }) {}

  friend std::ostream& operator<<(std::ostream& os, const UUID& uuid) {
    auto flags = os.flags();
    os << std::hex;
    for (const auto& [i, c] : uuid.uuid | std::views::enumerate) {
      os << std::setw(2) << std::setfill('0') << +c;
      if (i == 3 || i == 5 || i == 7 || i == 9) os << '-';
    }
    os.flags(flags);

    return os;
  }
};

int main() {
    const UUID a{};
    std::cout << a << std::endl;

    static constexpr const std::array<const uint8_t, 16> bArr{
      1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16
    };
    const UUID b{bArr};
    std::cout << b << std::endl;

    static constexpr const std::array<const uint8_t, 25> cArr{
      1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
      17, 18, 19, 20, 21, 22, 23, 24, 25
    };
    const UUID c{std::span(cArr).subspan(2, 18)};
    std::cout << c << std::endl;

    const UUID d{"aaaaaaaabbbbbbbb"};
    std::cout << d << std::endl;
}
