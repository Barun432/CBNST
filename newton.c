#include<stdio.h>
#include<math.h>
#define  e 0.001
#define  F(x) (x*x*x-4*x-9)
#define df(x) (3*x*x -4)
int main (){
    float x0,x1,f0,f1,df0;
    int i=0;
    printf("Enter the initial value::");
    scanf("%f",&x0);

    do{
        f0=F(x0);
        df0=df(x0);
        x1 = x0 - (f0/df0);

        f1=F(x1); // stopping condition...
        x0=x1;
        i++;
        printf("Iteration: %d\t",i);
        printf("Root = %f\t",x1);
        printf("Function Value = %f\n",f1);
    }while(fabs(f1)>e);
    printf("Apporxmiate root: %f after %d Iteration \n",x1,i);
    return 0;
}