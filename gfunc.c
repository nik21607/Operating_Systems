#include <math.h>
#include <stdio.h>

double gfunc(int x){
  double resG;
  resG = expf(-abs(x))*cos(x);
  return resG;
 }
