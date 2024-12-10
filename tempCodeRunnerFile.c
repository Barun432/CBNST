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