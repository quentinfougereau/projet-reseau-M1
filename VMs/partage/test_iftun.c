#include "iftun.h"

void main(int argc, char** argv){

    int tunfd;
    char quit = 'n';
    printf("Création de %s\n",argv[1]);
    tunfd = tun_alloc(argv[1]);
    printf("Faire la configuration de %s...\n",argv[1]);
    printf("Appuyez sur une touche pour continuer\n");
    system("/mnt/partage/configure-tun.sh");
    getchar();
    printf("Interface %s Configurée:\n",argv[1]);
    system("ip addr"); 
    while (1)
    {
            iftun(tunfd,1);
    }
}   