#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//function to compute logarithm of x with base b
float log_base(float x, float base){
    return log(x)/log(base);
}

float f(float x){
    // return x*sin(x)+cos(x);// example function
    return log_base(x,5)-x+2;
}

int main() {

    float a, b, c, error=0.0001;
    int maxiterations = 100, iterations =0;

    printf("Enter two initial guesses:");
    scanf("%f %f", &a,&b);

    if (f(a) == 0) {
    printf("Root = %f\n", a);
    return 0;
}
if (f(b) == 0) {
    printf("Root = %f\n", b);
    return 0;
}
    if (f(a) * f(b)>=0){
        printf("Invalid initial guesses. The function must have opposite signs at the two points.\n");
        exit(0);
    }
    
    printf("\niter\t a\t\t b\t\t c\t\t f(c)\n");
    do{
        c=(a+b)/2;
        printf("%d\t%f\t%f\t%f\t%f\n",iterations+1,a,b,c,f(c));
        if (fabs(f(c))<=error){
            break;
        }
        if(f(c)*f(a)<0)
        b=c;
        else
        a=c;
        iterations++;
    }while(iterations<maxiterations);
    printf("\nApproximate Root=%f\n",c);
    printf("Number of iterations =%d\n", iterations);
return 0;
}