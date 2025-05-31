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
#include <string_view>
#include <vector>

static PGconn* conn;

PGresult* exec(std::string_view sql, std::vector<char*> params) {
  return PQexecParams(
    conn,
    sql.data(),
    params.size(),
    nullptr,
    params.data(),
    nullptr,
    nullptr,
    1
  );
}

PGresult* exec(std::string_view sql) {
  return exec(sql, std::vector<char*>{});
}

bool ok(PGresult* res) {
  if (
    auto s{PQresultStatus(res)};
    s != PGRES_COMMAND_OK
    && s != PGRES_TUPLES_OK
  ) {
    std::clog << PQresStatus(s) << '\n' << PQerrorMessage(conn) << std::endl;

    return false;
  }

  return true;
}

bool script() {
  {
    auto res{exec("BEGIN")};
    if (!ok(res)) { PQclear(res); return false; }
    PQclear(res);
  }

  {
    auto res{exec("CREATE TYPE testenum AS ENUM ('asdf', 'butts');")};
    if (!ok(res)) { PQclear(res); return false; }
    PQclear(res);
  }

  {
    auto res{exec("SELECT 'asdf'::testenum AS e;")};
    if (!ok(res)) { PQclear(res); return false; }

    if (PQntuples(res) != 1) { PQclear(res); return false; }

    // Yeah I should use `PQfnumber()`, fight me.
    // Comes back as a cstring.
    std::clog << static_cast<char*>(PQgetvalue(res, 0, 0)) << std::endl;

    PQclear(res);
  }

  PQclear(exec("ROLLBACK;"));

  return true;
}

int main() {
  conn = PQconnectdb("");
  if (PQstatus(conn) != CONNECTION_OK) {
    std::clog << PQerrorMessage(conn) << std::endl;

    return -1;
  }

  bool success{script()};

  PQfinish(conn);

  if (!success) return -1;
}
