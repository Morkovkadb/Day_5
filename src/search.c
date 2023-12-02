/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <math.h>
#include <stdio.h>
#define MAX_EL 30

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
double mean(int *a, int n) {
    int max_value = max(a, n);
    int min_value = min(a, n);
    double res = ((double)max_value + (double)min_value) / 2.0;
    res = res * 10.0 * 10.0 * 10.0 * 10.0 * 10.0 * 10.0;
    res = round(res);
    res = res / 10.0 / 10.0 / 10.0 / 10.0 / 10.0 / 10.0;
    return res;
}

double variance(int *a, int n) {
    double my_mean = mean(a, n);
    double upper_mul = 0.0;
    int *ptr = a;
    for (int i = 0; i < n; ++i) {
        upper_mul += pow((*ptr - my_mean), 2.0);
        ptr++;
    }
    double res = upper_mul / (double)n;
    res = res * 10.0 * 10.0 * 10.0 * 10.0 * 10.0 * 10.0;
    res = round(res);
    res = res / 10.0 / 10.0 / 10.0 / 10.0 / 10.0 / 10.0;
    return res;
}

int input(int *array, int *n) {
    if (scanf("%d", n) == 1 && *n > 0 && getchar() == '\n') {
        for (int i = 0; i < *n; ++i) {
            int temp_value;
            int succes = scanf("%d", &temp_value);
            char last_char = getchar();
            if (succes == 1 && (last_char == '\n' || last_char == ' ')) {
                *(array + i) = temp_value;
            } else {
                return 1;
            }
        }
        return 0;
    } else {
        return 1;
    }
}
int search_number() {
    int array[MAX_EL];
    int n;
    if (input(array, &n)) {
        printf("n/a");
        return 1;
    }

    double my_mean = mean(array, n);
    double my_variance = variance(array, n);
    int find = 0;
    for (int i = 0; i < n; ++i) {
        if (*(array + i) % 2 == 0 && *(array + i) >= my_mean && *(array + i) != 0 &&
            *(array + i) <= my_mean + 3 * sqrt(my_variance)) {
            printf("%d", *(array + i));
            find = 1;
            break;
        }
    }
    if (!find) {
        printf("0");
    }

    return 0;
}

int main() {
    search_number();
    return 0;
}
