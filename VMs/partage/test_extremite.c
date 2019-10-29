#include "extremite.h"

int main(int argc, char** argv) {

  if (atoi(argv[1]) == 1) {
    int tunfd;
    printf("Création de %s\n",argv[1]);
    tunfd = tun_alloc(argv[1]);
    printf("Faire la configuration de %s...\n",argv[1]);
    printf("Appuyez sur une touche pour continuer\n");
    system("/mnt/partage/configure-tun.sh");
    getchar();
    printf("Interface %s Configurée:\n",argv[1]);
    char* ip_addr = argv[2];
    printf("Lancement du serveur\n");
    ext_out(ip_addr);
  }

  if (atoi(argv[1]) == 2) {
    int tunfd;
    tunfd = tun_alloc(argv[4]);
    printf("Faire la configuration de %s...\n",argv[4]);
    printf("Appuyez sur une touche pour continuer\n");
    system("/mnt/partage/configure-tun.sh");
    getchar();
    printf("Interface %s Configurée:\n",argv[4]);
    system("ip addr"); 
    char* ip_addr = argv[2];
    int port = atoi(argv[3]);
    printf("Lancement du client \n");
    ext_int(ip_addr, port,tunfd);
  }

  return 0;
}