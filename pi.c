#include <stdio.h>
#include <omp.h>

#define NUM_STEPS 100000000  // Number of steps for the approximation

double f(double x) {
    return 1.0 / (1.0 + x * x);
}

int main() {
    double step_size = 1.0 / NUM_STEPS;
    double sum = 0.0;
    double pi;

    // Start parallel region
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < NUM_STEPS; i++) {
        double x = (i + 0.5) * step_size;  // midpoint of each step
        sum += f(x);
    }

    // Multiply by step size and 4 to estimate pi
    pi = 4.0 * step_size * sum;

    printf("Estimated value of pi: %f\n", pi);

    return 0;
}
