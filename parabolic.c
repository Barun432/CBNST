/////////////////////// TERM////////// parabolic///////
#include <stdio.h>
void parabolicCurveFitting(float x[], float y[], int n) {
    float sumX = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0;
    float sumY = 0, sumXY = 0, sumX2Y = 0;
     for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumX3 += x[i] * x[i] * x[i];
        sumX4 += x[i] * x[i] * x[i] * x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2Y += x[i] * x[i] * y[i];
    }
    float D = n * (sumX2 * sumX4 - sumX3 * sumX3) 
            - sumX * (sumX * sumX4 - sumX2 * sumX3) 
            + sumX2 * (sumX * sumX3 - sumX2 * sumX2);

    float Da = sumY * (sumX2 * sumX4 - sumX3 * sumX3) 
             - sumX * (sumXY * sumX4 - sumX2Y * sumX3) 
             + sumX2 * (sumXY * sumX3 - sumX2Y * sumX2);

    float Db = n * (sumXY * sumX4 - sumX2Y * sumX3) 
             - sumY * (sumX * sumX4 - sumX2 * sumX3) 
             + sumX2 * (sumX * sumX2Y - sumXY * sumX2);

    float Dc = n * (sumX2 * sumX2Y - sumXY * sumX3) 
             - sumX * (sumX * sumX2Y - sumXY * sumX2) 
             + sumY * (sumX * sumX3 - sumX2 * sumX2);
    float a = Da / D;
    float b = Db / D;
    float c = Dc / D;
   printf("Parabolic equation: y = %.2fx^2 + %.2fx + %.2f\n", c, b, a);
}
int main() {
    int n;
    printf("Enter number of data points: ");
    scanf("%d", &n);
    float x[n], y[n];
    printf("Enter x and y values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }
    parabolicCurveFitting(x, y, n);
    return 0;
}
///////////////////////regression//////////
#include <stdio.h>
void regressionLines(float x[], float y[], int n) {
float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;
for (int i = 0; i < n; i++) {
sumX += x[i];
sumY += y[i];
sumXY += x[i] * y[i];
sumX2 += x[i] * x[i];
sumY2 += y[i] * y[i];
}
float b1 = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
float a1 = (sumY - b1 * sumX) / n;
float b2 = (n * sumXY - sumX * sumY) / (n * sumY2 - sumY * sumY);
float a2 = (sumX - b2 * sumY) / n;
printf("Regression line (y on x): y = %.2fx + %.2f\n", b1, a1);
printf("Regression line (x on y): x = %.2fy + %.2f\n", b2, a2);
}
int main() {
int n;
printf("Enter number of data points: ");
scanf("%d", &n);
float x[n], y[n];
printf("Enter x and y values:\n");
for (int i = 0; i < n; i++) {
scanf("%f %f", &x[i], &y[i]);
}
regressionLines(x, y, n);
return 0;
}