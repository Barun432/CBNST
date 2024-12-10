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