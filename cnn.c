
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


conlayer* makeConlayer(int inputHeight, int inputWidth, int inputDepth, int nextLayerPadding, int stride){
    conlayer *res = (conlayer*)malloc(sizeof(conlayer));
    res->inputWidth = inputWidth;
    res->inputDepth = inputDepth;
    res->inputHeight = inputHeight;
    res->filterDepth = FILTER_DEPTH;
    res->filterSize = FILTER_SIZE;
    res->outputDepth = FILTER_DEPTH;
    res->stride = stride;
    res->outputHeight = (res->inputHeight - res->filterSize)/res->stride +1;
    res->outputWidth = (res->inputWidth - res->filterSize)/res->stride +1;
    res->next_layer_padding = nextLayerPadding;
    //initialize filter random
    res->filter = (float***)malloc(sizeof(float**)*res->stride+1);
    for(int i=0; i<res->filterDepth;i++){
        for(int j=0;j<res->filterSize;j++){
            for(int k=0;k<res->filterSize;k++){
                res->filter[k][j][i] = distribution(generate)/sqrt(inputDepth*filterWidth*filterWidth);
            }
        }
    }
    //calculate output (feature map )


    //bias
    res->bias = (float*)calloc(res->outputDepth, sizeof(float));
    for (int i = 0; i < res->outputDepth; i++) {
        res->bias[i] = DEFAULT_BIAS;
    }



}



