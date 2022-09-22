#include <math.h>
#include <stdio.h>

double ffunc(int x){
  double resF;
  resF = expf(-abs(x))*sin(x);
  return resF;
 }
