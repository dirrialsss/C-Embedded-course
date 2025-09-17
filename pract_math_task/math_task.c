#include <stdio.h>
#include <math.h>

int main() {
    double alpha_deg, alpha_rad, z1, z2;
    double denominator;
    const double EPSILON = 1e-10;

    printf("Enter alpha in degrees:  ");
    scanf("%lf", &alpha_deg);

    alpha_rad = alpha_deg * M_PI / 180.0;

    printf("Our results:\n");
    denominator = cos(alpha_rad) - cos(3*alpha_rad) + cos(5*alpha_rad);
    if (fabs(denominator) < EPSILON) {
        printf("[z1] Error: division by zero in z1!\n");
    } else {
        z1 = (sin(2*alpha_rad) + sin(5*alpha_rad) - sin(3*alpha_rad)) / denominator;
        printf(" z1 = %.4f\n", z1);
    }

    // ---- z2 ----
    if (fabs(cos(3*alpha_rad)) < EPSILON) {
        printf("[z2] Error: tan(3*alpha) undefined!\n");
    } else {
        z2 = tan(3*alpha_rad);
        printf(" z2 = %.4f\n", z2);
    }

    return 0;
}