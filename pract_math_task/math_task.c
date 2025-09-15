#include <stdio.h>
#include <math.h>

int main() {
    double alpha_deg, alpha_rad, z1, z2;

    printf("Enter alpha in degrees:  ");
    scanf("%lf", &alpha_deg);

    alpha_rad = alpha_deg * M_PI / 180.0;

    z1 = (sin(2*alpha_rad)+sin(5*alpha_rad)-sin(3*alpha_rad))/(cos(alpha_rad)-cos(3*alpha_rad)+cos(5*alpha_rad));

    z2 = tan(3 * alpha_rad);

    printf("Our results:\n");
    printf(" z1 = %.4f\n",z1);
    printf(" z2 = %.4f\n",z2);

    return 0;
}