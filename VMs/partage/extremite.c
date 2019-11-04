#include "extremite.h"
#include "iftun.h"

void ext_out(char* ip_addr,int tun_fd) {
  struct sockaddr_in6 my_addr;
  int port = 123;
  int client;
  char buffer[SIZE_BUFFER];
  int addrlen = sizeof(my_addr);
  int opt = 1;

  int server_fd = socket(AF_INET6, SOCK_STREAM, 0);

  if (server_fd == -1) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  /* Prevents error such as: “address already in use”. */
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  my_addr.sin6_family = AF_INET6;
  //my_addr.sin_addr.s_addr = INADDR_ANY;
  my_addr.sin6_port = htons(port);

  //inet_aton(ip_addr, &my_addr.sin_addr);
  if(inet_pton(AF_INET6, ip_addr, &my_addr.sin6_addr) <= 0) {
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

  if ((client = accept(server_fd, (struct sockaddr *) &my_addr, (socklen_t *) &addrlen)) == -1) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  if (fork() == 0) {

    while (1) {
      //Redirection des données
      //printf("lol");
      iftun(client,tun_fd);
    }

    exit(0);

  } else {

    while (1) {
      //Redirection des données
      //printf("lol");
      iftun(tun_fd, client);
    }

  }

  wait();

}

void ext_int(char* addr, int port,int tun_fd) {
  struct sockaddr_in6 address;

  int client_fd = socket(AF_INET6, SOCK_STREAM, 0);

  address.sin6_family = AF_INET6;
  address.sin6_port = htons(port);

  //inet_aton(addr, &address.sin_addr);
  if(inet_pton(AF_INET6, addr, &address.sin6_addr) <= 0) {
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

  if (fork() == 0) {

    while (1) {
      iftun(tun_fd, client_fd);
    }

    exit(0);

  } else {

    while (1) {
      iftun(client_fd, tun_fd);
    }

  }

  wait();

}
