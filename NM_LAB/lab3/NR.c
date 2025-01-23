#include<stdio.h>
#include<math.h>
// float f(float x)
// {
//     return (3*x - exp(-x));
// }
// float fd(float x){
//     return 3 + exp(-x);
// }
float f(float x)
{
   // return (3*x - exp(-x));
    return (x*exp(x)-cos(x));
}
float fd(float x){
    return (exp(x)+x*exp(x)+sin(x));
}
void main()
{
 float x0, x1,error=0.0001;
 int i = 0;
 printf("\nEnter two initial gusses:");
 scanf("%f", &x1);
 printf("\ninter\tx1\t\tf(x1)\t\tf'(x1)\t\tx0\t\tf(x0)\n");
 do
 {
  x0 = x1 - (f(x1) / fd(x1));
  printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n", i + 1, x1, f(x1), fd(x1), x0, f(x0));
  x1 = x0;
  i++;
 } while (fabs(f(x0))>error);
 printf("\n Root = %f",x0);
 printf("\nNumber of iterations = %d",i);
}