#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conv.c>
typedef struct  {
  int inputDepth;
  int inputHeight;
  int inputWidth;
  int outputDepth;
  int outputHeight;
  int outputWidth;
}reluLayer;

reluLayer* makeReluLayer(int inputWidth, int inputHeight, int inputDept){
   reluLayer* relu = (reluLayer*)malloc(sizeof(reluLayer));
   relu->inputDepth = inputDepth;
   relu->inputWidth = inputWidth;
   relu->inputHeight = inputHeight;
   relu->outputDepth = inputDepth;
   relu->outputHeight = outputHeight;
   relu->outputWidth = intputWidth;
   return relu;
}

int relu_feed_forward(reluLayer *rl, feature_map *fm) {
  for(int i = 0; i < rl->outputDepth ; i++) {
    for(int j = 0 ; j < fm->width ; j++) {
      for(int k = 0 ; k < fm->height ; k++) {
        if(fm->data[i][j][k] < 0) {
          fm->data[i][j][k] = 0 ;
      }
    }
  }
}
