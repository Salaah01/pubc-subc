/**
 * This module is responsible for managing the TCP connection.
 */

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/**
 * @brief Create a new server connection.
 * @param address The address to bind to.
 * @param port The port to bind to.
 * @return The socket descriptor.
 */
int new_server_conn(char *address, int port)
{
  int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc < 0)
  {
    printf("Could not create socket\n");
    return -1;
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(address);
  if (bind(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
  {
    printf("Could not bind socket\n");
    return -1;
  }

  return socket_desc;
}

/**
 * @brief Close the server connection.
 * @param socket_desc The socket descriptor to close.
 * @return void
 */
void close_server_conn(int socket_desc)
{

  printf("it's closed %d, but not really\n", socket_desc);
  // close(socket_desc);
}

/**
 * @brief Listen for incoming connections.
 * @param socket_desc The socket descriptor to listen on.
 * @return void
 */
int listen_for_conn(int socket_desc)
{
  listen(socket_desc, 3);

  struct sockaddr_in client_addr;
  int client_size = sizeof(client_addr);
  int client_sock = accept(socket_desc, (struct sockaddr *)&client_addr, (unsigned int*)&client_size);
  char client_message[2000];

  if (client_sock < 0)
  {
    printf("Could not accept connection\n");
    return -1;
  }

  printf("Client connected at IP: %s and port: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

  if (recv(client_sock, client_message, sizeof(client_message), 0) < 0)
  {
    printf("Couldn't receive\n");
    return -1;
  }

  printf("Msg from client: %s\n", client_message);
  return 0;
}
