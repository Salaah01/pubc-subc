#ifndef _CONN_H_
#define _CONN_H_


int new_server_conn(char *address, int port);


void close_server_conn(int socket_desc);

void listen_for_conn(int socket_desc);

#endif
