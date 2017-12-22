#include <conv.c>

typedef struct {
    int inputWidth;
    int inputHeight;

    int outputDepth;
    int outputWidth;

    DTYPE* out;

    DTYPE** weights;
    DTYPE* bias;
}fullyCon;


fullyCon* make_fully_connected(int inputSize, int outputSize) {
    fullyCon *fl = (fullyCon*)malloc(sizeof(fullyCon));
    fl->inputWidth = inputSize;
    fl->outputWidth = outputSize;
    //weights initialize
    fl->weights = (DTYPE**)malloc(sizeof(DTYPE*)*fl->outputWidth);
    for(int i = 0 ; i < fl->outputWidth ; i++) {
       for(int j = 0 ; j < fl->inputWidth ; j++) {
        fl->weights[i][j] = distribution(generator)/sqrt(inputSize);
       }
    }
    //bias initialize
    fl->bias = (DTYPE*)calloc(fl->outputWidth, sizeof(DTYPE));
    for(int i = 0 ; i < fl->outputWidth ; i++) {
        fl->bias[i] = 0.1;
    }
    //output
    fl->out = (feature_map*)malloc(sizeof(DTYPE)*fl->outputWidth);

    return fl;
}

void fc_feed_for_ward(DTYPE *input, fullyCon *fc){
    DTYPE sum;
    for(int p = 0 ; p < fc->outputWidth ; p++) {
        sum = 0.0;
        for( int i = 0; i < fc->inputWidth ; i++) {
            sum += fc->weights[p][i] * input[i];
        }
        sum += fc->bias[p];
        
        fc->out[p] = sum;
    }
}
