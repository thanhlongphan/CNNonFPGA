#include <stdio.h>
#include <stdlib.h>

typedef double DTYPE;

#define RANDOM_NORMAL_STDDEV 1.0

default_random_engine generator;
normal_distribution<float> distribution(0.0, RANDOM_NORMAL_STDDEV);

inline double rmse(DTYPE output, int desiredOut) {
    return (pow(desiredOut - output, 2)) / 2;
}

inline double rmseD(DTYPE output, int desiredOut) {
    return (output - desiredOut);
}

//output map
typedef struct feature_map {
  int height;
  int width;
  DTYPE ***data;
}feature_map;
//input map
typedef struct inputImage {
  int height;
  int depth;
  int width;
  DTYPE ***data;
}inputImage;
//filter
typedef struct {
  int filterSize;
  int filterDepth;
  DTYPE*** data;
}filter;
//conv layer struktor
typedef struct convolution {
  filter* filter;
  int filterSize;
  feature_map* fm;
  int inputHeight;
  int inputWidth;
  int inputDepth;
  int outputDepth;
  DTYPE *bias;
  int stride;
  int padding;
  
  double(*lossF)(DTYPE, int);
  double(*lossD)(DTYPE, int);
}convolution;


feature_map* init_fmaps(int depth, int width, int height){
  feature_map* fm = (feature_map*)malloc(sizeof(feature_map)*depth);
  for(int i = 0, i < depth, i++){
    fm[i].width = width;
    fm[i].height = height;
  }
  return fm;
}

convolution *makeConv(int inputDepth, int inputHeight, int inputWidth, int stride, int filterSize, int padding, char actChoice, char lossChoice){
  convolution* conv = (convolution*)malloc(sizeof(convolution));  //Speicher reservieren
  conv->inputDepth = img->depth;
  conv->inputHeight = img->height;
  conv->inputWidth = img->width;
  conv->outputDepth = img->depth;
  conv->stride = stride;
  conv->padding = padding;
  //berechnet outputWidth und outputHeight
  conv->outputWidth = (conv->inputWidth - conv->filterSize + 2*padding) / conv->stride + 1; 
  conv->outputHeight = (conv->inputHeight - conv->filterSize +2*padding) / conv->stride + 1;
  //initialisiere output map (feature_map)
  conv->fm = (feature_map*)malloc(sizeof(feature_map) * conv->outputDepth);
    for (int f = 0; fm < conv->outputDepth; f++) {
        if (f == 0) {
            conv->fm->data[0] = (DTYPE**)malloc(sizeof(DTYPE*) * conv->outputDepth * (conv->outputWidth + 2 * conv->padding));
        }
        else {
            conv->fm->data[f] = &(conv->fm->data[0][f * (conv->outputWidth + 2 * conv->padding)]);
        }
        for (int j = 0; j < conv->outputWidth + 2 * conv->padding; j++) {
            // use a single coherent array
            if (f == 0 && j == 0) {

                conv->fm->data[0][0] = (DTYPE*)calloc(conv->outputDepth * (conv->outputWidth + 2 * conv->padding) *
                                                (conv->outputWidth + 2 * conv->padding), sizeof(DTYPE));
            }
            // point to beginnings
            else {
                conv->fm->data[f][j] = &(conv->fm->data[0][0][f * (conv->outputWidth + 2 * conv->padding) * (conv->outputWidth + 2 * conv->padding)
                                                     + j * (conv->outputWidth + 2 * conv->padding)]);
            }
        }
    }

  //initialisiere filter mit zufälligen Zahlen zwischen 0 und 1
  conv->filter->filterSize = filterSize;
  conv->filter->filterDepth = conv->inputDepth;
  conv->filter = (DTYPE***)malloc(sizeof(DTYPE**) * conv->inputDepth);  //Speicher reservieren
  //depth
  for(int i = 0 ; i < conv->outputDepth ; i++) {
    //width
    for(int j = 0 ; j < conv->filterSize ; j++) {
      //width
      for(int k = 0 ; k < conv->filterSize ; k++) {
        conv->filter->data[i][j][k] = distribution(generator);
      }
    }
  }
  //initialisiere biases
  conv->bias = (DTYPE*)calloc(conv->outputDepth, sizeof(DTYPE)); //Speicher reservieren
  for( int i = 0 ; i < conv->outputDepth ; i++) {
    conv->bias[i] = 0.1; //DEFAULT BIAS 0.1
  }
  
  conv->lossF = rmse;
  conv->lossD = rmseD;
  return conv;
}

//convCalculate berechnet feature_map einer inputImage

feature_map *convCalculate(inputImage ***img, convolution* conv ){
  feature_map *fmap = (feature_map*)malloc(sizeof(feature_map));
  int stride = conv->stride;
  for(int dep = 0 ; dep < conv->outputDept, dep++) {
    for(int height = 0 ; height < conv->outputHeight ; height++) {
      for(int width = 0 ; width < conv->outputWidth ; width++) {
        DTYPE sum = 0;
        for(int i = 0 ; i < conv->inputDepth ; i++ ) {
          for(int j = 0 ; j < conv->filterSize ; j++) {
            for(int k = 0 ; k < conv->filterSize ; k++) {
              sum += conv->filter[i][j][k]*img[i][height*stride+j][width*stride+k];
            }
          }
        }
        conv->fm->data[dep][height][width] = sum + conv->bias[dep];
      }
    }
  }
  fmap = conv->fm;
}
