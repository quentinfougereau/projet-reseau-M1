#include "extremite.h"
#include "tunalloc.h"
#include "iftun.h"

int main(int argc, char**argv){
    int tunfd;

    char tun_name[50];
    char inip[64];
    char inport[5];
    char options[100];
    char outip[64];
    char outport[5];   
    pid_t filsPID;
    FILE* fichier_config = NULL;


    if(argc < 2){
        perror("Nombre d'argument incorrect : ./tunnel46d <fichier_config> <script>");
    }
    fichier_config = fopen(argv[1],"r+");
    if(fichier_config != NULL){
        int r = fscanf(fichier_config,
                        "# interface tun\ntun=%s\n# adresse locale\ninip=%s\ninport=%s\noptions=%s\n# adresse distante\noutip=%s\noutport=%s",
                        tun_name,
                        inip,
                        inport,
                        options,
                        outip,
                        outport);
        if(r<=0){
            perror("Erreur dans la syntaxe du fichier");
            fclose(fichier_config);
            exit(EXIT_FAILURE);
        }
    }else
    {
        perror("Erreur dans la lecture du fichier");
        exit(EXIT_FAILURE);
    }
    

    
    printf("Création de %s\n",tun_name);
    printf("%s %s %s %s",inip,inport,outip,outport);
    tunfd = tun_alloc(tun_name);
    system(argv[2]);

    filsPID = fork();

    if(filsPID < 0)
    {
    	perror("Echec fork\n");
        return 0;
    }
	if(filsPID == 0) //Entree tunnel
	{
        printf("Lancement du client \n");
		sleep(10); //pour avoir le temps de le lancer sur la 2eme machine
		ext_int(outip,atoi(inport),tunfd);
		return 0;
	}else
    {
        printf("Lancement du serveur\n");
	    ext_out(inip,tunfd);
    }
    
	
    return 0;
}