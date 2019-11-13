#include "iftun.h"
#include "traitement.h"

void iftun(int src, int dest) {
    char buffer[SIZE_BUFFER];
    if(src < 0 || dest < 0) {
        perror("Error src or dest");
        exit(1);
    }

    int read_count;
    if ((read_count = read(src, buffer, SIZE_BUFFER)) < 0) {
      perror("Erreur read");
      exit(EXIT_FAILURE);
    }

    int length_pos = 3;
    int packet_size = get_packet_size(buffer, length_pos);
    char * data = tailleauto(buffer, length_pos, packet_size);

    write(dest, data, packet_size);
    //write(dest, buffer, read_count);
}
