#include <convLayer.h>

convLayer* ConvLayerSetup(int inputHeight, int inputDepth, int inputWidth, int stride, int padding, int filterSize, int filterCount){
  convLayer *conv = (convLayer*)malloc(sizeof(convLayer));
  conv->inputHeight = inputHeight;
  conv->inputDepth = inputDepth;
  conv->inputWidth = inputWidth;
  conv->outputDepth = filterCount;
  conv->stride = stride;
  conv->filterSize = filterSize;
  conv->padding = padding;
  conv->outputWidth = (conv->inputWidth - conv->filterSize + 2*conv->padding) / conv->stride + 1;
  conv->outputHeight = (conv->inputHeight - conv->filterSize + 2*conv->padding) / conv->stride + 1;
  conv->filter = (float****)malloc(sizeof(float***)*conv->filter);
  int i,j,k,l;
  for(i = 0; i < conv->outputDepth; i++) {
        if (i == 0) {
            conv->filter[0] = (float***)malloc(sizeof(float**) * conv->outputDepth * conv->inputDepth);
        }
        else {
            conv->filter[i] = &(conv->filter[0][i * conv->inputDepth]);
        }
        for (j = 0; j < conv->inputDepth; j++) {
            if (i == 0 && j == 0) {
                conv->filter[0][0] = (float**)malloc(sizeof(float*) *  conv->outputDepth * conv->inputDepth * conv->filterSize);
            }
            else {
                conv->filter[i][j] = &(conv->filter[0][0][i * conv->inputDepth * conv->filterSize + j * conv->filterSize]);
            }
            for (k = 0; k < conv->filterSize; k++) {
                // use a single coherent array
                if (i == 0 && j == 0 && k == 0) {
                    conv->filter[0][0][0] = (float*)malloc(sizeof(float)  *  conv->outputDepth * conv->inputDepth * conv->filterSize * conv->filterSize);
                }
                // point to beginnings
                else {
                    conv->filter[i][j][k] = &(conv->filter[0][0][0][i * conv->inputDepth * conv->filterSize * conv->filterSize +
                                             j * conv->filterSize * conv->filterSize + k * conv->filterSize]);
                }
               // initialisiere Filter mit Random-Werten zwischen 0 und 1
                for (l = 0; l < res->filterSize; l++) {
                    res->filter[i][j][k][l] = distribution(generator) / sqrt(inputDepth * filterSize * filterSize);
                    
                }
            }
        }
  }
  //https://stats.stackexchange.com/questions/200513/how-to-initialize-the-elements-of-the-filter-matrix
  
  //TODO output map
    
}
