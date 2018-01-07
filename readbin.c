#include <stdio.h>
#include <stdlib.h>

int number_of_images = 1;

void print_images(int images[number_of_images][3][4096]) {
  for(int i = 0; i<number_of_images; i++) {
    printf("[");
      for(int k = 0; k<4096; k++) {
        printf("[%d %d %d]", images[i][0][k], images[i][1][k], images[i][2][k]);
      }
    printf("]\n");
  }
}

int main() {
  FILE *fp; /*filepointer*/
      size_t size; /*filesize*/
      unsigned char *buffer; /*buffer*/
      int images[number_of_images][3][4096];

      fp = fopen("C:\\Users\\Kevin\\Desktop\\INFO\\Fachprojekt Data-Mining und Datenanalyse\\resized_images.bin","rb"); /*open file*/
      fseek(fp, 0, SEEK_END);
      size = ftell(fp);         /*calc the size needed*/
      fseek(fp, 0, SEEK_SET);
      buffer = (unsigned char *) malloc(size);  /*allocate space on heap*/

      if (fp == NULL){ /*ERROR detection if file == empty*/
          printf("Error: There was an Error reading the file %s \n", "C:\\Users\\Kevin\\Desktop\\INFO\\Fachprojekt Data-Mining und Datenanalyse\\resized_images.bin");
          exit(1);
      }
      else if (fread(buffer, sizeof *buffer, size, fp) != size){  /* if count of read bytes != calculated size of .bin file -> ERROR*/
          printf("Error: There was an Error reading the file %s - %d\n", "C:\\Users\\Kevin\\Desktop\\INFO\\Fachprojekt Data-Mining und Datenanalyse\\resized_images.bin");
          exit(1);
      }
      else {
        int i;
        int red = 0;
        int green = 0;
        int blue = 0;
        for(i=0; i<number_of_images*12288; i++){
          if(red == 4096) {red = 0;}
          if(green == 4096) {green = 0;}
          if(blue == 4096) {blue = 0;}
          int img_no = (int)i/12288;
          int color = (i % 3);
          if(color == 0) {
            //printf("%d, %d, %d  ", img_no, color, red);
            images[img_no][color][red] = (int)buffer[i];
            red++;
          }
          if(color == 1) {
            //printf("%d, %d, %d  ", img_no, color, green);
            images[img_no][color][green] = (int)buffer[i];
            green++;
          }
          if(color == 2) {
            //printf("%d, %d, %d  ", img_no, color, blue);
            images[img_no][color][blue] = (int)buffer[i];
            blue++;
          }
        }
      }

      //print_images(images);

      fclose(fp);
      free(buffer);

}
