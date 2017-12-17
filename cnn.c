
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
default_random_engine generator;
normal_distribution<float> distribution(0.0, RANDOM_NORMAL_STDDEV);
/*  5x5x3 filter
*   10x10x3 input images
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
    float bias;
}conlayer;


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
    res->filter = (float***)malloc(sizeof(float**)*res->stride+1);
    for(int i=0; i<conv->filterDepth;i++){
        for(int j=0;j<conv->filterSize;j++){
            for(int k=0;k<conv->filterSize;k++){
                conv->filter[k][j][i] = distribution(generate)/sqrt(inputDepth*filterWidth*filterWidth);
            }
        }
    }
    //calculate output (feature map )


    //bias
    conv->bias = (float*)calloc(conv->outputDepth, sizeof(float));
    for (int i = 0; i < conv->outputDepth; i++) {
        conv->bias[i] = DEFAULT_BIAS;
    }



}



