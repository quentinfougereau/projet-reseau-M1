#include "iftun.h"

void iftun(int src, int dest){
    char buffer[SIZE_BUFFER];
    if(src < 0 || dest < 0){
        perror("Oops, y'a R");
        exit(1);
    }

    int res = read(src, buffer, SIZE_BUFFER);

    if(res < 0){
        perror("Erreur read");
    }

    int wr = write(buffer, dest, SIZE_BUFFER);

    if(wr < 0){
        perror("Erreur write");
    }
}