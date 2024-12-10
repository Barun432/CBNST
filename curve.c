/////////////////////7///langrange
#include<stdio.h>
#include<conio.h>
void main(){
	 float x[100], y[100], xp, sum=0, term;
	 int n;
	 printf("Enter number of data: ");
	 scanf("%d", &n);
	 printf("Enter data:\n");
	 for(int i=1;i<=n;i++){
		  printf("x[%d] = ", i);
		  scanf("%f", &x[i]);
		  printf("y[%d] = ", i);
		  scanf("%f", &y[i]);
	 }
	 printf("Enter interpolation point: ");
	 scanf("%f", &xp);
	
	 for(int i=1;i<=n;i++){
		  term=1;
		  for(int j=1;j<=n;j++){
			   if(i!=j)  {
			    	term *= (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  sum +=  term * y[i];
	 }
	 printf("Interpolated value at %.3f is %.3f.", xp, sum);
}
//8. //////////////3/8 simpson
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) 1/(1+x*x)
int main()
{
 float lower, upper, sum=0.0, h, k;
 int i, n;
 
 printf("Enter lower limit of integration: ");
 scanf("%f", &lower);
 printf("Enter upper limit of integration: ");
 scanf("%f", &upper);
 printf("Enter number of sub intervals: ");
 scanf("%d", &n);
 h = (upper - lower)/n;
sum= f(lower) + f(upper);
 for(i=1; i<=n-1; i++)
 {
  k = lower + i*h;
  if(i%3 == 0)
  {
   sum = sum + 2 * f(k);
  }
  else
  {
   sum = sum+ 3 * f(k);
  }
 }
 sum = sum* h*3/8;
 printf("\nRequired value of integration is: %.3f", sum);
 return 0;
}
///////////////////9. 1/3 simpson...
#include<stdio.h>
#include<math.h>
#define f(x) 1/(1+x*x)

int main()
{
 float lower, upper, sum=0.0, h, k;
 int i, n;

 printf("Enter lower limit of integration: ");
 scanf("%f", &lower);
 printf("Enter upper limit of integration: ");
 scanf("%f", &upper);
 printf("Enter number of sub intervals: ");
 scanf("%d", &n);

 h= (upper - lower)/n;


 sum= f(lower) + f(upper);
 for(i=1; i<=n-1; i++)
 {
  k = lower + i*h;
  if(i%2==0)
  {
    sum = sum+ 2 * f(k);
  }
  else
  {
    sum = sum + 4 * f(k);
  }
 }
sum= sum * h/3;
 printf("\nRequired value of integration is: %.3f", sum);
 return 0;
}
//////////////////10.trapezoidal
#include<stdio.h>
#include<math.h>

#define f(x) 1/(1+pow(x,2))
 int main(){
    int n; //no. of interval
    float LL,UL,sum=0,h;

    printf("Enter the value of lower limit and upper limit::\n ");
    scanf("%f %f",&LL,&UL);
    printf("Enter the no. of Intervals \n");
    scanf("%d",&n);

    // main logic
    h=(UL - LL)/n;
    sum = f(LL) + f(UL);
    for(float i=LL+h;i<UL;i=i+h){
        sum=sum+2*f(i);
    }
    sum = (h*sum)/2;
    printf("\nRequired value of integration is: %f", sum);
}

//11. //////////////eulers method//
#include<stdio.h>
#define f(x,y) x+y

int main(){
 float x0, y0, xn, h, yn, slope;
 int i, n;

 printf("Enter Initial Condition\n");
 printf("x0 = ");
 scanf("%f", &x0);
 printf("y0 = ");
 scanf("%f", &y0);
 printf("Enter  upper limit xn = ");
 scanf("%f", &xn);
 printf("Enter number of steps: ");
 scanf("%d", &n);

 h = (xn-x0)/n;

 printf("\nx0\ty0\tslope\tyn\n");
 printf("------------------------------\n");
 for(i=0; i < n; i++){
  slope = f(x0, y0);
  yn = y0 + h * slope;
  printf("%.4f\t%.4f\t%0.4f\t%.4f\n",x0,y0,slope,yn);
  y0 = yn;
  x0 = x0+h;
 }
 printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);
  return 0;
}

/////////////////12.runga kutta fourth method..

#include<stdio.h>
#include<conio.h>

#define f(x,y) x+y

int main(){
 float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
 int i, n;
 
 printf("Enter Initial Condition\n");
 printf("x0 = ");
 scanf("%f", &x0);
 printf("y0 = ");
 scanf("%f", &y0);
 printf("Enter calculation point xn = ");
 scanf("%f", &xn);
 printf("Enter number of steps: ");
 scanf("%d", &n);

 h = (xn-x0)/n;


 printf("\nx0\ty0\tyn\n");
 for(i=0; i < n; i++){
  k1 = h * (f(x0, y0));
  k2 = h * (f((x0+h/2), (y0+k1/2)));
  k3 = h * (f((x0+h/2), (y0+k2/2)));
  k4 = h * (f((x0+h), (y0+k3)));
  k = (k1+2*k2+2*k3+k4)/6;
  yn = y0 + k;
  printf("%0.4f\t%0.4f\t%0.4f\n",x0,y0,yn);
  x0 = x0+h;
  y0 = yn;
 }
 printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);
 return 0;
}


//13.//////////////////////////straightline/// least square////
#include <stdio.h>
int main() {
    int n, i;
    double x[100], y[100], sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, a, b;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the x and y values:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i + 1);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i + 1);
        scanf("%lf", &y[i]);
    }

    for (i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / n;
    printf("\nThe fitted linear equation is: y = %.2f + %.2f*x\n", a, b);

    return 0;
}
