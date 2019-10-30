#include "extremite.h"
#include "tunalloc.h"

int main(int argc, char** argv) {

  if (atoi(argv[1]) == 1) {
    int tunfd;
    printf("Création de %s\n",argv[3]);
    tunfd = tun_alloc(argv[3]);
    printf("Faire la configuration de %s...\n",argv[3]);
    printf("Appuyez sur une touche pour continuer\n");
    getchar();
    printf("Interface %s Configurée:\n",argv[1]);
    system("ip addr");
    char* ip_addr = argv[2];
    printf("---------------------\n");
    printf("Lancement du serveur\n");
    ext_out(ip_addr,tunfd);
  }

  if (atoi(argv[1]) == 2) {
    int tunfd;
    tunfd = tun_alloc(argv[4]);
    printf("Faire la configuration de %s...\n",argv[4]);
    printf("Appuyez sur une touche pour continuer\n");
    system("/mnt/partage/config-tun-VM1-6.sh");
    getchar();
    printf("Interface %s Configurée:\n",argv[4]);
    system("ip addr");
    char* ip_addr = argv[2];
    int port = atoi(argv[3]);
    printf("---------------------\n");
    printf("Lancement du client \n");
    sleep(10);
    ext_int(ip_addr, port,tunfd);
  }

  return 0;
}
