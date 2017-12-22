#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <conv.c>

typedef struct  {
  int inputDepth;
  int inputWidth;
  int inputHeight;

  int outputDepth;
  int outputHeight;
  int outputWidth;

  int pool; //size of max pool
  feature_map *fm;  //output image
}poolLayer;

poolLayer* make_pool_layer(convolution *conv, int pool) {
  poolLayer *pl = (pool*)malloc(sizeof(pool)); //speicher reservieren
  pl->inputDepth = conv->inputDepth;
  pl->inputWidth = conv->inputWidth;
  pl->inputHeight = conv->inputHeight;

  pl->outputWidth = conv->outputWidth / pool;
  pl->outputHeight = conv->outputHeight / pool;
  pl->outputDepth = conv->outputDepth;

  pl->fm = (feature_map*)malloc(sizeof(feature_map)*pl->outputDepth);
  for (int fmap = 0; fmap < pl->outputDepth; fmap++) {
        if (fmap == 0) {
            pl->fm->data[0] = (DTYPE**)malloc(sizeof(DTYPE*) * pl->outputDepth * (pl->outputWidth);
        }
        else {
            pl->fm->data[fmap] = &(pl->fm->data[0][fmap * (pl->outputWidth)]);
        }
        for (int j = 0; j < pl->outputWidth ; j++) {
            // use a single coherent array
            if (fmap == 0 && j == 0) {

                pl->fm->data[0][0] = (DTYPE*)calloc(pl->outputDepth * (pl->outputWidth ) *
                                                (pl->output ), sizeof(DTYPE));
            }
            // point to beginnings
            else {
                pl->fm->data[fmap][j] = &(pl->fm->data[0][0][fmap * (pl->outputWidth ) * (pl->outputHeight )
                                                     + j * (pl->outputWidth)]);
            }
        }
    }
    return pl;
}
