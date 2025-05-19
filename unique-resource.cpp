#if 0 /*
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
  && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <cstdio>
#include <iostream>
#include <experimental/scope>

int main() {
  auto file = std::experimental::make_unique_resource_checked(
    std::fopen("unique-resource.cpp", "r"),
    nullptr,
    [](std::FILE *fptr) { std::fclose(fptr); }
  );
  if (file.get())
    std::cout << "The file exists." << std::endl;
  else
    std::cout << "The file does not exist." << std::endl;
}
