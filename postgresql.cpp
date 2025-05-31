#if 0 /*
g++ -std=c++23 $0 -o exe -Wall -Werror -Wextra -pedantic-errors \
  -I/usr/include -L/usr/lib -lpq \
  && ./exe $@
RET=$?
rm -f exe
exit $RET
*/
#endif

#include <libpq-fe.h>

#include <iostream>

int main() {
  auto conn{PQconnectdb("")};
  if (PQstatus(conn) != CONNECTION_OK) {
    std::clog << PQerrorMessage(conn) << std::endl;

    return -1;
  }

  auto res{PQexecParams(
    conn,
    "SELECT 1 as x UNION ALL SELECT 2 as x;",
    0,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    1
  )};
  if (auto s{PQresultStatus(res)}; s != PGRES_TUPLES_OK) {
    std::clog << PQresStatus(s) << '\n' << PQerrorMessage(conn) << std::endl;

    goto exit;
  }

  std::clog << PQntuples(res) << '\n';

  PQclear(res);

  exit:
  PQfinish(conn);
}
