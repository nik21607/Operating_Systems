#include <math.h>
#include <stdio.h>

double ffunc(int x){
  double resF;
  resF = expf(-abs(x))*sin(x);
  return resF;
 }
 double gfunc(int x){
  double resG;
  resG = expf(-abs(x))*cos(x);
  return resG;
 }

int main(){
  int x;
  printf("Enter x:");
  scanf("%d",&x);
  printf("x = %d\n",x);
  printf("f(x) = %f\n",ffunc(x));
  printf("g(x) = %f\n",gfunc(x));
  return 0;
}

