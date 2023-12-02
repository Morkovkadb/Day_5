#include <math.h>
#include <stdio.h>
#define NMAX 10
#define ABS(x) ((x) < 0 ? -(x) : (x))

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n;
    int data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
    } else {
            output(data, n);
            output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    }

    return 0;
}

int input(int *a, int *n) {
    scanf("%d", n);
    if (*n < 0 || *n > NMAX) {
        return 1;
    }

    int *ptr = a;
    for (int i = 0; i < *n; ++i) {
        scanf("%d", ptr);
        ptr++;
    }
    return 0;
}
void output(int *a, int n) {
    int *ptr = a;
    for (int i = 0; i < n; ++i) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");
}

int max(int *a, int n) {
    int *ptr = a;
    int max = *ptr;
    for (int i = 0; i < n; ++i) {
        if (max < *ptr) {
            max = *ptr;
        }
        ptr++;
    }
    return max;
}
int min(int *a, int n) {
    int *ptr = a;
    int min = *ptr;
    for (int i = 0; i < n; ++i) {
        if (min > *ptr) {
            min = *ptr;
        }
        ptr++;
    }
    return min;
}

// int is_discrete_uniform_distribution(int *array_pointer, int const *n) {
//     int *ptr = array_pointer;
//     int *second_pointer = ptr++;
//     for (int i = 0; i < *(n)-1; ++i) {
//         if (ABS(*ptr) - ABS(*second_pointer) != -1 && ABS(*ptr) - ABS(*second_pointer) != 1) {
//             return 1;
//         }
//         ptr++;
//         second_pointer++;
//     }
//     return 0;
// }

double mean(int *a, int n) {
    int max_value = max(a, n);
    int min_value = min(a, n);
    double res = (max_value + min_value) / 2.0;
    res = res * 10.0 * 10.0 * 10.0 * 10.0 * 10.0 * 10.0;
    res = round(res);
    res = res / 10.0 / 10.0 / 10.0 / 10.0 / 10.0 / 10.0;
    return res;
}

double variance(int *a, int n) {
    double my_mean = mean(a, n);
    double upper_mul = 0;
    int *ptr = a;
    for (int i = 0; i < n; ++i) {
        upper_mul += pow((*ptr - my_mean), 2.0);
        ptr++;
    }
    double res = upper_mul / (n + 0.0);
    res = res * 10.0 * 10.0 * 10.0 * 10.0 * 10.0 * 10.0;
    res = round(res);
    res = res / 10.0 / 10.0 / 10.0 / 10.0 / 10.0 / 10.0;
    return res;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6lf %.6lf", max_v, min_v, mean_v, variance_v);
}