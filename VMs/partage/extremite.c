#include "extremite.h"

void ext_out(char* ip_addr) {
  struct sockaddr_in my_addr;
  int port = 123;
  int client;
  char buffer[SIZE_BUFFER];
  int addrlen = sizeof(my_addr);

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);

  if (server_fd == -1) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  my_addr.sin_family = AF_INET;
  //my_addr.sin_addr.s_addr = INADDR_ANY;
  my_addr.sin_port = htons(port);

  //inet_aton(ip_addr, &my_addr.sin_addr);
  if(inet_pton(AF_INET, ip_addr, &my_addr.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported \n");
    exit(EXIT_FAILURE);
  }

  if (bind(server_fd, (struct sockaddr *) &my_addr, sizeof(my_addr)) == -1) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  while (1) {
    if ((client = accept(server_fd, (struct sockaddr *) &my_addr, (socklen_t *) &addrlen)) == -1) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    if (read(client, buffer, SIZE_BUFFER) == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }

    if (write(1, buffer, SIZE_BUFFER) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }

  }

}

void ext_int(char* addr, int port) {
  struct sockaddr_in address;
  char* msg = "Hello from client";

  int client_fd = socket(AF_INET, SOCK_STREAM, 0);

  address.sin_family = AF_INET;
  address.sin_port = htons(port);

  //inet_aton(addr, &address.sin_addr);
  if(inet_pton(AF_INET, addr, &address.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported \n");
    exit(EXIT_FAILURE);
  }

  if (client_fd == -1) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  if (connect(client_fd, (struct sockaddr *) &address, sizeof(address)) == -1) {
    perror("connect failed");
    exit(EXIT_FAILURE);
  }

  send(client_fd, msg, strlen(msg), 0);

}

int main(int argc, char** argv) {
  if (atoi(argv[1]) == 1) {
    char* ip_addr = argv[2];
    printf("Lancement du serveur\n");
    ext_out(ip_addr);
  }

  if (atoi(argv[1]) == 2) {
    char* ip_addr = argv[2];
    int port = atoi(argv[3]);
    printf("Lancement du client \n");
    ext_int(ip_addr, port);
  }

  return 0;
}
