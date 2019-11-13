#include "traitement.h"

void display(int read_count, char buffer[]) {
  int i;
  char string[read_count];
  for (i = 0; i < read_count; i++) {
    string[i] = buffer[i];
  }
  printf("%s\n", string);
}

void test(int read_count, char buffer[]) {
  int i;
  int j = 0;
  char string[4];
  for (i = 3; i <= 9; i++) {
    printf("------------------\n");
    printf("Hexa = %04x\n", buffer[i]);
    printf("Entier = %d\n", buffer[i]);
    printf("Read_count = %d\n", read_count);
    printf("******************\n");
    /*
    string[j] = buffer[i];
    j++;
    */
  }
}

int get_packet_size(char buffer[], int length_pos) {
  return buffer[length_pos];
}

char * tailleauto(char buffer[], int length_pos, int packet_size) {
  char * data = (char *) malloc(sizeof(char) * packet_size);
  int i;
  for (i = 0; i < packet_size; i++) {
    data[i] = buffer[i];
  }
  return data;
}

int tailleentete_in() {

}
