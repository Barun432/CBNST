//bisection method...
//c = (a+b)/2;
#include<stdio.h>
#include<math.h>
#define e 0.00005
#define f(x) (x*x*x-4*x-9)
int main(){
     int i=1;
     float a,b,c,F;
     printf("Enter the two inital guess no :\n");
     scanf("%f %f",&a,&b);

     do{
        c=(a+b)/2;
        F=f(c);
            printf("i=%d || a=%.4f || b=%.4f || c=%.4f || F(c)=%.4f\n\n",i,a,b,c,F);  
        if(f(a)*f(c)<0){
            b=c;
        }else{
            a=c;
        }
        i++;
     }while(fabs(f(c))>e);
     printf("approx value = %.4f",c);
     return 0;
}
// regual fasli...
// (a*Fb-b*Fa)/(Fb-Fa)
#include<stdio.h>
#include<math.h>
#define e 0.00005
#define f(x) (x*x*x-4*x-9)
int main(){
      float a,b,c,Fa,Fb,Fc;
     int i=1;
     printf("Enter the two guess no:: \n");
     scanf("%f %f",&a,&b);
      Fa=f(a);
      Fb=f(b);
     do{
       c = (a*Fb-b*Fa)/(Fb-Fa);
       Fc = f(c);
  printf("i=%d || a=%.4f || b=%.4f || c=%.4f || F(c)=%.4f\n\n",i,a,b,c,Fc); 
       if(Fa*Fc<0){
        b=c;
        Fb=Fc;
       }else{
        a=c;
        Fa=Fc;
       }
       i++;
     }while(fabs(Fc)>e);
     printf("approx value = %.4f",c);
     return 0;
}
//secant method...
#include<stdio.h>
#include<math.h>
#define e 0.00005
#define f(x) (x*x*x-2*x-5)
int main (){
    float x0,x1,x2,f0,f1,f2;
    int i=1;
    printf("Enter the two inital guess no::\n");
    scanf("%f%f",&x0,&x1);
     int N;
     printf("Enter the no of iteration:\n");
     scanf("%d",&N);
    do{
        f0=f(x0);
        f1=f(x1);

        x2 = x1-(x1-x0)*f1/(f1-f0);
        f2 = f(x2);
        printf("i=%d || x0=%.4f || x1=%.4f || x2=%.4f || F=%.4f\n\n",i,x0,x1,x2,f2);
        x0=x1;
        x1=x2;
        i++;
        if(i>N){
            printf("not convergent : \n");
         break;
        }
    }while(fabs(f2)>e);
    printf("approx value %f",x2);
    return 0;
}
// langrange interpolation....
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
			    	term = term* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  sum = sum + term * y[i];
	 }
	 printf("Interpolated value at %.3f is %.3f.", xp, sum);
}