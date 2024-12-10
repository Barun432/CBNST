// bisection...
#include<stdio.h>
#include<math.h>
#define e 0.00005
#define f(x) (x*x*x-4*x-9)
int main(){
    float a,b,c,F;
    int i=1;
    printf("Enter the two initial guess value::");
    scanf("%f%f",&a,&b);
    
    do{
        c=(a+b)/2;
        F= f(c);
        printf("i=%d || a=%.4f || b=%.4f || c=%.4f || F(c)=%.4f\n\n",i,a,b,c,F);

        if(f(a)*f(c)<0){
            b=c;
        }else{
            a=c;
        }
        i++;
    }while(fabs(f(c))>e);
    printf("Approx value is %.4f",c);
    return 0;
}
// regular falsi method...
#include<stdio.h>
#include<math.h>
#define e 0.00005
#define f(x) (x*x*x-4*x-9)
int main(){
    float a,b,c,Fa,Fb,Fc;
    int i=1;
    printf("Enter the two initial guess value::");
    scanf("%f%f",&a,&b);
    Fa=f(a);
    Fb=f(b);
     do{
        c=(a*Fb-b*Fa)/(Fb-Fa);
        Fc=f(c);
 printf("i=%d || a=%.4f || b=%.4f || c=%.4f || F(c)=%.4f\n\n",i,a,b,c,Fc);
        if(Fa*Fc<0){
            b=c;
            Fb=Fc;
        }
        else{
            a=c;
            Fa=Fc;
        }
        i++;
     }while(fabs(Fc)>e);
      printf("Approx value is %.4f",c);
    return 0;
    
}
// iteration method...
#include<stdio.h>
#include<math.h>
#define e 0.00005
#define f(x) (cos(x)-3*x+1)
#define g(x) (cos(x)-0.5)
int main(){
    float x0,x1;
    int i=1;
     int N;
      printf("Enter the initial value:;");
      scanf("%f",&x0);
      printf("Enter the Number of iteration\n");
      scanf("%d",&N);
      do{
        x1= g(x0);
        printf("i=%d,value of root=%.4f",i,x1);
        i++;
        if(i>N){
            printf("NOT CONVERGENT");
            break;
        }
        x0=x1;
      }while(fabs(f(x1))>e);
    printf("approx value is %f",x1);
    return 0;
      
}
//