
//3/8 simson1/3 rule...
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
    sum = sum + 3 * f(k);
  }
 }
sum= sum * h/3;
 printf("\nRequired value of integration is: %.3f", sum);
 return 0;
}