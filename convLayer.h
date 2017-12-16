#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
default_random_engine generator;
normal_distribution<float> distribution(0.0, RANDOM_NORMAL_STDDEV);
typedef struct{
    int inputHeight;
    int inputDepth;
    int inputWidth;
    int outputHeight;
    int outputWidth;
    int outputDepth;
    int filterSize;
    float*** filter // 3x3x3 filter
    int stride;
    int padding;
    float* bias;
    
}convLayer;

convLayer* ConvLayerSetup(int inputHeight, int inputDepth, int inputWidth, int stride, int padding, int filterSize);
