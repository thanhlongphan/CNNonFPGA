#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef struct{
    int inputHeight;
    int inputDepth;
    int inputWidth;
    int outputHeight;
    int outputWidth;
    int filterSize;
    int stride;
    int padding;
    float* bias;
}convLayer;

void ConvLayerSetup(int inputHeight, int inputDepth, int inputWidth, int stride, int padding, int filterSize);
