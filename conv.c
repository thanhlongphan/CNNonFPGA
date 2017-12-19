#include <stdio.h>
#include <stdlib.h>

typedef double DTYPE;

#define RANDOM_NORMAL_STDDEV 1.0

default_random_engine generator;
normal_distribution<float> distribution(0.0, RANDOM_NORMAL_STDDEV);

//output map
typedef struct feature_map {
  int height;
  int width;
  DTYPE *data;
}feature_map;

typedef struct inputImage {
  int height;
  int depth;
  int width;
  DTYPE *data;
}inputImage;

struct data {
	int w;
	int h;
	double *data;
}data;
/*
typedef struct filter {
  int width; // filter size
  DTYPE *data;
  int *inp; //verstehe nicht , was ist das denn
}filter;
*/
//conv layer struktor
typedef struct convolution {
  DTYPE ***filter;
  int filterSize;
  feature_map *fm;
  int inputHeight;
  int inputWidth;
  int inputDepth;
  int outputDepth;
  DTYPE *bias;
  int stride;
  //ich würde gern keine Zero padding benutzen
  //int padding;
}convolution;


feature_map* init_fmaps(int depth, int width, int height){
  feature_map* fm = (feature_map*)malloc(sizeof(feature_map)*depth);
  for(int i = 0, i < depth, i++){
    fm[i].width = width;
    fm[i].height = height;
  }
  return fm;
}

convolution *makeConv(inputImage *img, int stride, int filterSize)
//convolution *makeConv(int inputDepth, int inputHeight, int inputWidth, int stride, int filterSize){
  convolution* conv = (convolution*)malloc(sizeof(convolution));  //Speicher reservieren
  conv->inputDepth = img->depth;
  conv->inputHeight = img->height;
  conv->inputWidth = img->width;
  conv->outputDepth = img->depth;
  conv->stride = stride;
  conv->filterSize = filterSize;
  //berechnet outputWidth und outputHeight
  conv->outputWidth = (conv->inputWidth - conv->filterSize) / conv->stride + 1; //hier ist padding gleich 0
  conv->outputHeight = (conv->inputHeight - conv->filterSize) / conv->stride + 1; //hier ist padding gleich 0;
  //initialisiere output map (feature_map)
  feature_map* fm = init_fmaps(conv->outputDept, conv->outputWidth, conv->outputHeight);
  conv->fm = fm;
  //initialisiere filter mit zufälligen Zahlen zwischen 0 und 1
  conv->filter = (DTYPE***)malloc(sizeof(DTYPE**) * conv->inputDepth);  //Speicher reservieren
  //depth
  for(int i = 0 ; i < conv->outputDepth ; i++) {
    //width
    for(int j = 0 ; j < conv->filterSize ; j++) {
      //width
      for(int k = 0 ; k < conv->filterSize ; k++) {
        conv->filter[i][j][k] = distribution(generator);
      }
    }
  }
  //initialisiere biases
  conv->bias = (DTYPE*)calloc(conv->outputDepth, sizeof(DTYPE)); //Speicher reservieren
  for( int i = 0 ; i < conv->outputDepth ; i++) {
    conv->bias[i] = 0.1; //DEFAULT BIAS 0.1
  }

  return conv;
}

int convCalculate(inputImage *img, feature_map *fm, int filterSize, int stride){
  //TODO
}
