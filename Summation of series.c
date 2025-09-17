#include <stdio.h>
#include <math.h>

double Algo1_SumGeoSeries(double a, double r, int n) {
    return (a * (pow(r, n) - 1)) / (r - 1);
}

int main() {
    double a, r;
    int n;
    scanf("%lf %lf %d", &a, &r, &n);
    printf("%.2lf\n", Algo1_SumGeoSeries(a, r, n));
    return 0;
}
