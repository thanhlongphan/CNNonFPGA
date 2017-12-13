#include <convLayer.h>

convLayer* ConvLayerSetup(int inputHeight, int inputDepth, int inputWidth, int stride, int padding, int filterSize){
  convLayer *conv = (convLayer*)malloc(sizeof(convLayer));
  conv->inputHeight = inputHeight;
  conv->inputDepth = inputDepth;
  conv->inputWidth = inputWidth;
  conv->stride = stride;
  conv->padding = padding;
  conv->filterSize = filterSize;
  //TODO
}
