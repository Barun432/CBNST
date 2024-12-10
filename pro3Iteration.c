#include<stdio.h>
#include<math.h>
#define F(x) (cos(x)-3*x+1)
#define g(x) (cos(x) - 0.5)
int main(){
    int i = 1, N;
    float x0,x1,e;
    
    printf("Enter the initial guess:");
    scanf("%f",&x0);
    printf("Enter the tolerable Error:");
    scanf("%f",&e);
    printf("Enter the maximum Iteration:");
    scanf("%d",&N);
    do{
        x1 =g(x0);
        printf("\nThe value after %d iteration is %f",i,x1);
         i++;
      if(i>N){
        printf("NOT Convergent");
          break;
    }
    x0 = x1;
    }while(fabs(F(x1))>e);
    printf("approxmiate root %.4f", x1);

}