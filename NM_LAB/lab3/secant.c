//Implementation of secant method.


#include<stdio.h>
#include<math.h>

float log_base(float x, float base)
{
    return log(x)/log(base);
}
float f(float x)
{
    float y;
    y=exp(-x)-x;
    return y;
}
void main()
{
    float x1,x2,x0, error=0.0001;
    int i=0;
    printf("\nEnter two initial guesses:");
    scanf("%f %f",&x1,&x2);
    
    printf("\niter\tx1\t\ttx2\\t\t\tf(x1)\t\tf(x2)\t\tx0\t\t\t\tf(x0)\n");
    do{
        x0=x1-(f(x1)*(x2-x1))/(f(x2)-f(x1));
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n",i+1,x1,x2,f(x1),f(x2),x0,f(x0));
        x1=x2;
        x2=x0;
        i++;
    }
    while(fabs(f(x0))>error);
    printf("\nRoot=%f",x0);
    printf("\nNumber of iteration=%d",i);
}