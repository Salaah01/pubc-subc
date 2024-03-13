#include "conn.h"

int main()
{
  // Open TCP connection
  // While loop
  // Listen for message
  // When received messaged send it off to some function.
  int conn = new_server_conn("127.0.0.1", 8000);
  listen_for_conn(conn);
  close_server_conn(conn);

  return 0;
}