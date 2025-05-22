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
#include <sstream>
#include <string_view>
#include <vector>

// Trailing delimiter doesn't create an empty entry.
static constexpr std::string_view terminated{"abc;def;ghi;"};
static constexpr std::string_view unterminated{"jkl;mno;pqr"};

int main() {
  // Got to be `string` not `string_view` as these vectors are the owners.
  std::vector<std::string> splitTerminated{};
  std::vector<std::string> splitUnterminated{};
  // Resizes during push backs make no difference.
  splitTerminated.resize(0);
  splitUnterminated.reserve(3);
  std::string word{};
  std::stringstream ss{};

  // `move()`ing avoids a copy (I think).
  ss.str(std::move(std::string(terminated)));
  while (std::getline(ss, word, ';')) {
    std::clog << "found " << word << std::endl;
    splitTerminated.push_back(word);
  }

  // Reusing the same `stringstream` is doable, but manual handling of the
  // seeking is required.
  ss.str(std::move(std::string(unterminated)));
  ss.clear();  // Has to come before `.seekg()`.
  ss.seekg(0);  // Not `.seekp()`.
  while (std::getline(ss, word, ';')) {
    std::clog << "found " << word << std::endl;
    splitUnterminated.push_back(word);
  }

  for (const auto& w : splitTerminated) std::clog << "t: " << w << std::endl;
  for (const auto& w : splitUnterminated) std::clog << "u: " << w << std::endl;
}
