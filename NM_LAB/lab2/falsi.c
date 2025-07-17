#include<stdio.h>
#include<math.h>
#define MAX_ITERATIONS 100
#define ERROR 0.00001 

double log_base(double x,double base){
	return log(x)/log(base);

}
double f(double x){
	//return x*x*x-x-1; //pow(x,3)-x-1;
    return x*exp(x)-cos(x);
    // return x*log_base(x,10)-1.2;
}
void regulaFalsi(double a, double b){
	if(f(a)*f(b)>=0){
          printf("invalld interval.The function does not have a root in the given range.\n");
          return;
	}
	double c;
	
	int iteration = 0;
	printf("iter        a       b       c       f(c)\n");
	while (iteration <MAX_ITERATIONS){
		
		c=(a*f(b)-b*f(a))/(f(b)-f(a));
		
	        printf("%-5d %-10.6f %-10.6f %-10.6f %-10.6f\n",
	        iteration +1,a,b,c,f(c));
	        
	        if(fabs(f(c))<ERROR){
	        	printf("\nRoot is approximately:%.6f\n",c);
	        	printf("f(root)=%.6f\n",f(c));
	        	return;
	        }	
	        if(f(c)*f(a)<0){
	        	b=c;

	        }
	        else {
	        	a=c;
	        }
	        
	        iteration++;
	}
	printf("\n Maximum iteration rached.Approximate root:%.6f\n",c);
	printf("f(root)=%.6f\n",f(c));
}
int main(){
	double a,b;
	printf("Enter the interval[a,b]:");
	scanf("%lf %lf",&a,&b);
	regulaFalsi(a,b);
	return 0;
}