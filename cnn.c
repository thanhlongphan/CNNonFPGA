
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

using namespace std;

#define FILTER_DEPTH 3
#define FILTER_SIZE 5
#define DEFAULT_STRIDE 1
#define DEFAULT_BIAS 0.1
default_random_engine generator;
normal_distribution<float> distribution(0.0, RANDOM_NORMAL_STDDEV);
/*  5x5x3 filter
*   12x12x3 input images
*   
*/
typedef struct{
    int inputHeight;
    int inputWidth;
    int inputDepth;
    int outputHeight;
    int outputWidth;
    int outputDepth;
    int filterSize;
    int filterDepth;
    float*** filter;
    float*** output;
    int stride;
    int padding;
    float* bias;
}conlayer;


typedef struct{
    int inputDepth;
    int inputWidth;
    int inputHeight;
    int outputDepth;
    int outputWidth;
    int outputHeight;
}reluLayer;

typedef struct{
    int inputDepth;
    int inputWidth;
    int inputHeight;
    int height;
    int width;
    int stride;
    int padding;
    int outputDepth;
    int outputWidth;
    int outputHeight;
    int pool;
}poolLayer;

poolLayer* makePooLayer(conlayer* conv, int pool ){
    pooLayer* pl = (poolLayer*)malloc(sizeof(poolLayer));
    pl->width = width;
    pl->inputDepth = conv->inputDepth;
    pl->inputWidth = conv->inputWidth;
    pl->inputHeight = conv->inputHeight;
    pl->stride = conv->stride;
    //TODO
}

reluLayer* makeReluLayer(int inputWidth, int inputHeight, int inputDepth){
   reluLayer* relu = (reluLayer*)malloc(sizeof(reluLayer));
   relu->inputDepth = inputDepth;
   relu->inputWidth = inputWidth;
   relu->inputHeight = inputHeight;
   relu->outputDepth = inputDepth;
   relu->outputHeight = outputHeight; 
   relu->outputWidth = outputWidth;
   return relu;  
}

conlayer* makeConlayer(int inputHeight, int inputWidth, int inputDepth, int padding){
    conlayer *conv = (conlayer*)malloc(sizeof(conlayer));
    conv->inputWidth = inputWidth;
    conv->inputDepth = inputDepth;
    conv->inputHeight = inputHeight;
    conv->filterDepth = FILTER_DEPTH;
    conv->filterSize = FILTER_SIZE;
    conv->outputDepth = FILTER_DEPTH;
    conv->stride = DEFAULT_STRIDE;
    conv->outputHeight = (conv->inputHeight - conv->filterSize)/conv->stride +1;
    conv->outputWidth = (conv->inputWidth - conv->filterSize)/conv->stride +1;
    conv->padding = padding;
    //initialize filter random
    conv->filter = (float***)malloc(sizeof(float**)*conv->stride+1);
    for(int i=0; i<conv->filterDepth;i++){
        for(int j=0;j<conv->filterSize;j++){
            for(int k=0;k<conv->filterSize;k++){
                conv->filter[i][j][k] = distribution(generate)/sqrt(inputDepth*filterWidth*filterWidth);
            }
        }
    }
    //(feature map )
    
    conv->output = (float***)malloc(sizeof(float**)*conv->outputDepth);
    for(int dep=0;dep<outputDepth;dep++){
        for(int h=0;h<outputHeight;h++){
            for(int w=0;w<outputWidth;w++){
                //TODO
            }
        }
    }

    //bias
    conv->bias = (float*)calloc(conv->outputDepth, sizeof(float));
    for (int i = 0; i < conv->outputDepth; i++) {
        conv->bias[i] = DEFAULT_BIAS;
    }
}





