#include "iftun.h"

void iftun(int src, int dest){
    char buffer[SIZE_BUFFER];
    if(src < 0 || dest < 0){
        perror("Error src or dest");
        exit(1);
    }

    int read_count = read(src, buffer, SIZE_BUFFER);

    if(read_count < 0){
        perror("Erreur read");
    }

    write(dest, buffer, read_count);
}
