//bis.c
#include<stdio.h>
#include<math.h>
#define e 0.00005
#define f(x) (x*x*x-4*x-9)
int main(){
   int i=1;
   float a,b,c,F;
   printf("Enter the inital two guess value::");
   scanf("%f %f",&a,&b);
   do{
      c=(a+b)/2;
      F=f(c);
      printf("i=%d || a=%.4f || b=%.4f || c=%.4f || F(c)=%.4f",i,a,b,c,F);
      printf("\n");
       if(f(a)*f(c)<0){
         b=c;
       }
       else{
         a=c;
       }
       i++;
   }while(fabs(F)>e);
    printf("\n");
    printf("\n\n Approx value %.4f",c);

}
// falsi mthod.....
 // c = (a*Fb-b*Fa)/(Fb-Fa)
 #include<stdio.h>
 #include<math.h>
 #define e 0.00005
 #define f(x) (x*x*x-4*x-9)
 int main(){
   int i=1;
   float a,b,c,Fa,Fb,Fc;
   printf("Enter the two inital gues no:");
   scanf("%f%f",&a,&b);
   Fa=f(a);
   Fb=f(b);
   do{
      c = (a*Fb-b*Fa)/(Fb-Fa);
      Fc=f(c);
       printf("i=%d || a=%.4f || b=%.4f || c=%.4f || F(c)=%.4f",i,a,b,c,Fc);
      printf("\n");
      if(Fa*Fc <0){
         b=c;
         Fb=Fc;
      }
      else{
         a=c;
         Fa=Fc;
      }
      i++;
   }while(fabs(Fc)>e);
   printf("\n");
   printf("aprrox val. %.4f",c);
   return 0;
 }
 //newton rapson..

 // x1 = x0 - f(x0)/f'(x0)
 #include<stdio.h>
 #include<math.h>
 #define e 0.00005
 #define f(x) (x*x*x -4*x-9)
 #define g(x) (3*x*x-4)
 int main (){
   int i=1;
   float x0,x1,df,f1,f0;
     printf("Enter the intial value ::");
     scanf("%f",&x0);
     do{
     f0= f(x0);
     df = g(x0);

     x1 = x0-(f0/df);
     x0=x1;
     
     i++;
     printf("i=%d || root =%.4f || function value=%.4f",i,x1,f1 );
      printf("\n");
     }while(fabs(f(x1))>e);
     printf("approvx val. %.4f",x1);
     return 0;
 }
 // iteration method.....
  #include<stdio.h>
  #include<math.h>
  #define e 0.00005
  #define f(x) (cos(x)-3*x+1)
  #define df(x) (cos(x)-0.5)
int main(){
   float x0,x1;
   int i=1;
   printf("Enter the intial number ::");
   scanf("%f",&x0);
   int N;
   printf("toal");
   scanf("%d",&N);

   do{
      x1 = df(x0);
      printf("i=%d  || root value = %.4f",i,x1);
      printf("\n");
      i++;
      if (i>N)
      {
       printf("NOT convergent");
       break;
      }
      
      x0=x1;
   }while(fabs(f(x1))>e);
    printf("\n");
    printf("approx value = %.4f",x1);
    return 0;
}
// newton forward..
#include<stdio.h>
#include<conio.h>
int main(){
 float x[20], y[20][20];
 int i,j, n;
 printf("Enter number of data?\n");
 scanf("%d", &n);
 printf("Enter data:\n");

 for(i = 0; i < n ; i++){
  printf("x[%d]=", i);
  scanf("%f", &x[i]);
  printf("y[%d]=", i);
  scanf("%f", &y[i][0]);
 }
// main logic for create a table...
 for(i = 1; i < n; i++){
  for(j = 0; j < n-i; j++){
   y[j][i] = y[j+1][i-1] - y[j][i-1];
  }
 }
// pritn table.....
 printf("\nFORWARD DIFFERENCE TABLE\n\n");
 for(i = 0; i < n; i++){
  printf("%0.2f", x[i]);
  for(j = 0; j < n-i ; j++){
   printf("\t%0.2f", y[i][j]);
  }
  printf("\n");
 }
 double x_interp;
    printf("\nEnter the value of x for interpolation: ");
    scanf("%lf", &x_interp);

    double result = y[0][0]; 
    double term = 1.0; 
    for (i = 1; i < n; i++) { 
        term *= (x_interp - x[i - 1]);
        result += y[0][i] * term; 
    }

    printf("Interpolated value at x = %.2lf is %.6lf\n", x_interp, result);
 return 0;
}
// newton backward///////////
#include<stdio.h>
#include<conio.h>
int main(){
 float x[20], y[20][20];
 int i,j, n;

 printf("Enter number of data?\n");
 scanf("%d", &n);
 printf("Enter data:\n");
 for(i = 0; i < n ; i++){
  printf("x[%d]=", i);
  scanf("%f", &x[i]);
  printf("y[%d]=", i);
  scanf("%f", &y[i][0]);
 }
// logic for create a table...
 for(i = 1; i < n; i++){
  for(j = n-1; j > i-1; j--) {
   y[j][i] = y[j][i-1] - y[j-1][i-1];
  }
 }

 // print table....
 printf("\nBACKWARD DIFFERENCE TABLE::\n\n");
 for(i = 0; i < n; i++){
  printf("%0.2f", x[i]);
  for(j = 0; j <= i ; j++){
   printf("\t%0.2f", y[i][j]);
  }
  printf("\n");
 }
 double x_interp;
    printf("\nEnter the value of x for interpolation: ");
    scanf("%lf", &x_interp);

    double result = y[n - 1][0]; 
    double term = 1.0; 
    double u = (x_interp - x[n - 1]) / (x[1] - x[0]); 
    
    for (i = 1; i < n; i++) {
        term *= (u + i - 1) / i; 
        result += y[n - 1][i] * term; 
    }
    printf("Interpolated value at x = %.2lf is %.6lf\n", x_interp, result);
 return 0;
}
