#include <stdio.h>
#include <stdlib.h>


int main() {
  FILE *fp; /*filepointer*/
      size_t size; /*filesize*/
      unsigned char *buffer; /*buffer*/

      fp = fopen("C:\\Users\\Kevin D\\Desktop\\INFO\\Fachprojekt Data-Mining und Datenanalyse\\daten\\train\\resized_images.bin","rb"); /*open file*/
      fseek(fp, 0, SEEK_END);
      size = ftell(fp);         /*calc the size needed*/
      fseek(fp, 0, SEEK_SET);
      buffer = (unsigned char *) malloc(size);  /*allocate space on heap*/

      if (fp == NULL){ /*ERROR detection if file == empty*/
          printf("Error: There was an Error reading the file %s \n", "C:\\Users\\Kevin D\\Desktop\\INFO\\Fachprojekt Data-Mining und Datenanalyse\\daten\\train\\resized_images.bin");
          exit(1);
      }
      else if (fread(buffer, sizeof *buffer, size, fp) != size){  /* if count of read bytes != calculated size of .bin file -> ERROR*/
          printf("Error: There was an Error reading the file %s - %d\n", "C:\\Users\\Kevin D\\Desktop\\INFO\\Fachprojekt Data-Mining und Datenanalyse\\daten\\train\\resized_images.bin");
          exit(1);
      }else{int i;
          for(i=0; i<size;i++){
              printf("%u ", buffer[i]);
          }
      }
      fclose(fp);
      free(buffer);

}
