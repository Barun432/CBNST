#include<stdio.h>
#include<math.h>
#define F(x)  (x*x*x*-x-1)
int main(){
    int i=1;
    float a,b,c,f;
     printf("\n Enter the value of a and b");
     scanf("%f %f",&a,&b);
     do{
        c =(a+b)/2;
        f = F(c);
         printf("\n i=%d   a=%f  b=%f  c=%f F(c)=%f",i,a,b,c,f);
          if(F(a)*F(c)<0){
            b=c;
          }
          else{
            a=c;
          }
          i++;
     }while(fabs(F(c))>0.001);
     printf("%.4f",c);
     return 0;
     
     }
    // int i =1;
    // float a,b,c,f;
    //  printf("\n Enter the value of a and b");
    //  scanf("%f %f",&a,&b);

    //  do{
    //     c =(a+b)/2;
    //     f = F(c);
    // printf("\n i=%d   a=%f  b=%f  c=%f F(c)=%f",i,a,b,c,f);
    //     if(F(a)*F(c)<0){ // then root lies b/w  a&c  and we write b=c.
    //         b=c;
    //     }
    //     else{ // then root lies b/w b&c and we write a=c.
    //         a=c;
    //     }
    //     i++;
    //  }while(fabs(F(c))>0.001); // that gives absolute/mod
    //  printf("\n \n Approximate root = %.4f \n \n", c); // .4f 
    //  return 0;
// } 