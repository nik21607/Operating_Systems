#include <math.h>
#include <stdio.h>
#include "func.h"

int main(){
  int x;
  printf("Enter x:");
  scanf("%d",&x);
  printf("x = %d\n",x);
  printf("f(x) = %f\n",ffunc(x));
  printf("g(x) = %f\n",gfunc(x));
  return 0;
}
