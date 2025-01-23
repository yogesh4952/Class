#include<stdio.h>
#include<math.h>
double g(double x){
    return (7+log(x))/2;
}
int main(){
    double x0,x1,tolerance=0.00001;
    int max_iter=50,iter;
    printf("enter the initial guess x0:");
    scanf("%lf", &x0);

    //print table header
    printf("\niter xn   xn+1\n");

    //start with initial guess
    x1= g(x0);

    //iterate and displlay results 
    for(iter = 1; iter<= max_iter; iter++){
        printf("%3d  %0.6lf  %0.9lf\n", iter, x0,x1);

        if( fabs(x1-x0)<tolerance){
            printf("\nConverged in %d iterations\n", iter);
            break;
        }

        //update values for next iteration 
        x0=x1;
        x1=g(x0);
    }

    // if the method doesn't converge in max_iterations 
    if(iter==max_iter){
        printf("\nMaximum iterations reached\n");
    }
    return 0;
    }